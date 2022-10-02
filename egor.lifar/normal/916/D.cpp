/*
 






































 
 */
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
    
     
     
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
/** Interface */
     
inline int readChar();
template <class T = int> inline T readInt(); 
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x ); 
inline void writeWord( const char *s );
     
/** Read */
     
static const int buf_size = 4096;
     
inline int getChar() {
    static char buf[buf_size];
    static int len = 0, pos = 0;
    if (pos == len) {
        pos = 0, len = fread(buf, 1, buf_size, stdin);
    }
    if (pos == len) {
        return -1;
    }
    return buf[pos++];
}
     
inline int readChar() {
    int c = getChar();
    while (c <= 32) {
        c = getChar();
    }
    return c;
}
     
template <class T>
inline T readInt() {
    int s = 1, c = readChar();
    T x = 0;
    if (c == '-')
        s = -1, c = getChar();
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    return s == 1 ? x : -x;
}
     
/** Write */
     
static int write_pos = 0;
static char write_buf[buf_size];
     
inline void writeChar( int x ) {
    if (write_pos == buf_size)
        fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
    write_buf[write_pos++] = x;
}
     
template <class T> 
inline void writeInt( T x, char end ) {
    if (x < 0)
        writeChar('-'), x = -x;
     
    char s[24];
    int n = 0;
    while (x || !n)
        s[n++] = '0' + x % 10, x /= 10;
    while (n--)
        writeChar(s[n]);
    if (end)
        writeChar(end);
}
     
inline void writeWord( const char *s ) {     while (*s)
writeChar(*s++); }
     
struct Flusher {
    ~Flusher() {
        if (write_pos)
            fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
    }
} flusher;   
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const pair<T, U> &_p) { _out << _p.first << ' ' << _p.second; return _out; }
template<typename T, typename U> inline istream &operator>> (istream &_in, pair<T, U> &_p) { _in >> _p.first >> _p.second; return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const vector<T> &_v) { if (_v.empty()) { return _out; } _out << _v.front(); for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline istream &operator>> (istream &_in, vector<T> &_v) { for (auto &_i : _v) { _in >> _i; } return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const map<T, U> &_m) { if (_m.empty()) { return _out; } _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->first << ": " << _it->second << ')'; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const unordered_map<T, U> &_m) { if (_m.empty()) { return _out; } _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->first << ": " << _it->second << ')'; } return _out; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define next next228
#define rank rank228
#define prev prev228
#define y1 y1228                                                         
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
const string FILENAME = "input";
const int MAXN = 100228;
const int MAXV = 1000000000;


struct node {
    node *l, *r;
    long long num;
};


node *V[MAXN], *M[MAXN];


long long getnum(node *x) {
    return x ? x->num: 0;
}


node *update(node *x, int l, int r, int q, int c) {
    node *z = new node();
    if (x) {
        *z = *x;
    }
    if (l == r) {
        z->num += c;
        return z;
    }
    int m = (l + r) / 2;
    if (q <= m) {
        z->l = update(z->l, l, m, q, c);
    } else {
        z->r = update(z->r, m + 1, r, q, c);
    }
    z->num = getnum(z->l) + getnum(z->r);
    return z;
}


int rmq(node *x, int l, int r, int zl, int zr) {
    if (!getnum(x)) {
        return 0;
    }
    if (zl <= l && r <= zr) {
        return x->num;
    }
    int m = (l + r) / 2;
    int ans = 0;
    if (zl <= m) {
        ans += rmq(x->l, l, m, zl, zr);
    }
    if (zr > m) {
        ans += rmq(x->r, m + 1, r, zl, zr);
    }
    return ans;
}


map<string, int> id;


int getid(string s) {
    if (!id.count(s)) {
        id[s] = sz(id) + 1;
    }
    return id[s];
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 //   read(FILENAME);
    int Q;
    cin >> Q;
    for (int q = 1; q <= Q; q++) {
        string op, s;
        cin >> op;
        V[q] = V[q - 1];
        M[q] = M[q - 1];
        if (op[0] == 's') {
            int x;
            cin >> s >>x;
            int t = getid(s);
            int v = rmq(M[q], 1, Q, t, t);
            if (v) {
                V[q] = update(V[q], 1, MAXV, v, -1);
            }
            M[q] = update(M[q], 1, Q, t, -v + x);
            V[q] = update(V[q], 1, MAXV, x, 1);
        } else if (op[0] == 'r') {
            cin >> s;
            int t = getid(s);
            int v = rmq(M[q], 1, Q, t, t);
            if (v) {
                M[q] = update(M[q], 1, Q, t, -v);
                V[q] = update(V[q], 1, MAXV, v, -1);
            }
        } else if (op[0] == 'q') {
            cin >> s;
            int t = getid(s);
            int v = rmq(M[q], 1, Q, t, t);
            if (v) {
                int ans = rmq(V[q], 1, MAXV, 1, v - 1);
                cout << ans << endl;
            } else {
                cout << -1 << endl;
            }
        } else {
            int d;
            cin >> d;
            M[q] = M[q - d - 1];
            V[q] = V[q - d - 1];
        }
    }
    return 0;
}