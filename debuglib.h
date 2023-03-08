using namespace std;
#define see(args...)                             \
    {                                            \
        cerr << "LINE " << __LINE__;             \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
        cerr << endl;                            \
    }
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << ' ' << *it << " = " << a;
    err(++it, args...);
}
inline void op() { cout << '\n'; }
template <typename T, typename... Types>
inline void op(T var1, Types... var2) {
    cout << var1 << ' ';
    op(var2...);
}

template <class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> pair) {
    return out << "(" << pair.first << ", " << pair.second << ")";
}
template <class T>
ostream& operator<<(ostream& out, vector<T> vec) {
    out << "(";
    for (auto& v : vec) out << v << ' ';
    return out << ")";
}
template <class T>
ostream& operator<<(ostream& out, set<T> vec) {
    out << "(";
    for (auto& v : vec) out << v << ", ";
    return out << ")";
}
template <class L, class R>
ostream& operator<<(ostream& out, map<L, R> vec) {
    out << "(";
    for (auto& v : vec) out << "[" << v.first << ", " << v.second << "]";
    return out << ")";
}