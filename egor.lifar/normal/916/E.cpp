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
const int MAXN = 100001;


int n, q;
int a[MAXN];
vector<int> g[MAXN];
vector<int> v[MAXN];
int in[MAXN];
int out[MAXN];
int t = 0;
int prs[MAXN][18];


void dfs(int u, int pr = -1) {
    t++;
    in[u] = t;
    for (auto h: g[u]) {
        if (h != pr) {
            v[u].push_back(h);
            prs[h][0] = u;
            dfs(h, u);
        }
    }
    out[u] = t;
}


int root;


bool parent(int a, int b) {
    return in[a] <= in[b] && out[b] <= out[a];
}


int lca(int a, int b) {
    if (parent(a, b)) {
        return a;
    }
    if (parent(b, a)) {
        return b;
    }
    for (int k = 17; k >= 0; k--) {
        if (!parent(prs[a][k], b)) {
            a = prs[a][k];
        }
    }
    return prs[a][0];
}


long long d[MAXN * 5];
long long mod[MAXN * 5];
int ss;


void push(int v, int g) {
    if (mod[v] != 0) {
        d[v] += mod[v] * g;
        if (v < ss) {
            mod[v * 2] += mod[v];
            mod[v * 2 + 1] += mod[v];
        }
        mod[v] = 0;
    }
}


long long rmq(int v, int vl, int vr, int l, int r) {
    if (vl > r || vr < l) {
        return 0;
    }
    if (l <= vl && vr <= r) {
        push(v, vr - vl + 1);
        return d[v];
    }
    push(v, vr - vl + 1);
    return rmq(v * 2, vl, (vl + vr) / 2, l, r) + rmq(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r);
}


void add(int v, int vl, int vr, int l, int r, long long x) {
    if (vl > r || vr < l) {
        push(v, vr - vl + 1);
        return;
    }
    if (l <= vl && vr <= r) {
        mod[v] += x;
        push(v, vr - vl + 1);
        return;
    }
    push(v, vr - vl + 1);
    add(v * 2, vl, (vl + vr) / 2, l, r, x);
    add(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r, x);
    d[v] = d[v * 2] + d[v * 2 + 1];
}


void add(int u, int x) {
   // cout << u + 1 << endl;
    if (u == root) {
        add(1, 1, ss, 1, n, x);
        return;
    }
    if (!parent(u, root)) {
        add(1, 1, ss, in[u], out[u], x);
    } else {
        add(1, 1, ss, 1, n, x);
        int l = 0;
        int r = sz(v[u]) - 1;
        while (l != r) {
            int mid = (l + r + 1) >> 1;
            if (in[v[u][mid]] > in[root]) {
                r = mid - 1;
            }  else {
                l = mid;
            }
        }
        add(1, 1, ss, in[v[u][l]], out[v[u][l]], -x);
       // cout << rmq(1, 1, ss, in[v[u][l]], out[v[u][l]]) << endl;
    }
}



long long get(int u) {
    if (u == root) {
        return rmq(1, 1, ss, 1, n);
    }
  //  cout << u << ' ' << root << endl;
    if (!parent(u, root)) {
     //   cout << u << endl;
        //cout << in[u] << ' ' << out[u] << endl;
        return rmq(1, 1, ss, in[u], out[u]);
    } else {
        long long ans = rmq(1, 1, ss, 1, n);
       // cout << ans << endl;
        int l = 0;
        int r = sz(v[u]) - 1;
        while (l != r) {
            int mid = (l + r + 1) >> 1;
            if (in[v[u][mid]] > in[root]) {
                r = mid - 1;
            }  else {
                l = mid;
            }
        }
        ans -= rmq(1, 1, ss, in[v[u][l]], out[v[u][l]]);
        return ans;
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  //  read(FILENAME);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    } 
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0);
    for (int k = 1; k <= 17; k++) {
        for (int i = 0; i < n; i++) {
            prs[i][k] = prs[prs[i][k - 1]][k - 1];
        }
    }
    ss = 1;
    while (ss < n) {
        ss <<= 1;
    }
    for (int i = 0; i < n; i++) {
       // cout << in[i] << endl;
        d[ss + in[i] - 1] = a[i];
    }
    for (int i = ss - 1; i >= 1; i--) {
        d[i] = d[i * 2] + d[i * 2 + 1];
    }
   // cout << rmq(1, 1, ss, 1, ss) << endl;
    for (int it = 0; it < q; it++) {
        int t;
        cin >> t;
        if (t == 1) {
            int ns;
            cin >> ns;
            root = ns - 1;
        } else {
            if (t == 2) {
                int a, b, x;
                cin >> a >> b >> x;
                a--, b--;
                int c = lca(a, b) ^ lca(a, root) ^ lca(b, root);
                add(c, x);
            } else {
                int a;
                cin >> a;
                a--;
                //xscout << a << endl;
                cout << get(a) << '\n';
            }
        }
    }
    return 0;
}