/*
 












 
 */
#pragma GCC optimize "-o3"
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
/** Interface */
     
inline int readChar();
template <class T = long long> inline T readInt(); 
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
const string FILENAME = "input";
const int MAXN = 500228;



struct point
{
    long long x, y;
    point(){}
    point(long long _x, long long _y) {
        x = _x;
        y = _y;
    }
};


point operator -(const point &a, const point &b) {
    return point(a.x - b.x, a.y - b.y);
}

point operator +(const point &a, const point &b) {
    return point(a.x + b.x, a.y + b.y);
}


bool operator ==(const point &a, const point &b) {
    return a.x == b.x && a.y == b.y;
}


struct edge
{
    int to;
    int a, b;
    edge(){}
    edge(int _to, int _a, int _b) {
        to = _to;
        a = _a;
        b = _b;
    }
};

int n, m;
vector<edge> g[MAXN];
vector<edge> ng[MAXN];
int uk;
unordered_map<int, bool> bad[MAXN];


void dfs(int u, int pr = -1) {
    int len = sz(g[u]) - (pr == -1 ? 0: 1);
    if (len <= 2) {
        for (auto x: g[u]) {
            if (x.to != pr) {
                ng[u].pb(x);
                ng[x.to].pb(edge(u, x.a, x.b));
                dfs(x.to, u);
            }
        }
    } else {
        bool f = true;
        int cnt = 0;
        int pre = -1;
        for (auto x: g[u]) {
            if (x.to != pr) {
                cnt++;
                if (f) {
                    ng[u].pb(x);
                    ng[x.to].pb(edge(u, x.a, x.b));
                    pre = u;
                } else {
                    if (cnt != len) {
                        ng[pre].pb(edge(uk, 0, 0));
                        ng[uk].pb(edge(pre, 0, 0));
                    }
                    ng[uk].pb(x);
                    ng[x.to].pb(edge(uk, x.a, x.b));
                    pre = uk;
                    if (cnt != len - 1) {
                        uk++;
                    }
                }
                f = false;
            }
        }
        for (auto x: g[u]) {
            if (x.to != pr) {
                dfs(x.to, u);
            }
        }
    }
}


int sz[MAXN];
int deep[MAXN];
vector<int> st;

void dfs1(int u, int pr = -1) {
    sz[u] = 1;
    st.pb(u);
    for (auto h: ng[u]) {
        if (bad[u][h.to]) {
            continue;
        }
        if (h.to != pr) {
            deep[h.to] = deep[u] + 1;
            dfs1(h.to, u);
            sz[u] += sz[h.to];
        }
    }
}


vector<point> sts[2];
int id;


void dfs2(int u, int pr, long long cura = 0, long long curb = 0) {
    int cnt = 0;
    for (auto h: ng[u]) {
        if (bad[u][h.to]) {
            continue;
        }
        if (h.to != pr) {
            cnt++;
           // cout << h.a << ' ' << h.b << '\n';
            dfs2(h.to, u, cura + h.a, curb + h.b);
        }
    }
   if (cnt == 0) {
     //  cout << cura << ' ' << curb << '\n';
        sts[id].pb(point(cura, curb));
    }
}





bool dist(const point &a, const point &b) {
    long double kek = (long double)b.x * b.x + (long double)b.y * b.y - (long double)a.x * a.x + (long double)a.y * a.y;
    return kek > 0;
}

point gg;


int sign1(long long f) {
    if (f > 0) {
        return 1;
    }
    if (f == 0) {
        return 0;
    }
    return -1;
}


int sign(long double x) {
    if (abs(x) < 1e-13) {
        return 0;
    }
    if (x > 0) {
        return 1;
    }
    return -1;
}





const int DIG = 1073741824;


struct int96
{
    long long a[3];

};



int96 init(const long long &x) {
    int96 a;
    a.a[0] = x & 1073741823;
    a.a[1] = x >> 30;
    a.a[2] = 0;
    return a;
}

int96 operator +(const int96 &a, const int96 &b) {
    int96 c;
    c = init(0);
    for (int i = 0; i < 3; i++) {
        c.a[i] = a.a[i] + b.a[i];
    }  
    for (int i = 0; i < 2; i++) {
        if (c.a[i] >= DIG) {
            c.a[i] -= DIG;
            c.a[i + 1]++;
        }
    }
    return c;
}


int96 operator *(const int96 &a, const int96 &b) {
    int96 c;
    c = init(0);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            c.a[i + j] += a.a[i] * b.a[j];
        }
    }
    for (int i = 0; i < 2; i++) {
        c.a[i + 1] += c.a[i] >> 30;
        c.a[i] = c.a[i] & 1073741823;
    }
    return c;
}


bool operator >(const int96 &a, const int96 &b) {
    for (int i = 2; i >= 0; i--) {
        if (a.a[i] > b.a[i]) {
            return true;
        }
        if (a.a[i] < b.a[i]) {
            return false;
        }
    }
    return false;
}





// int cmp(const long long &a, const long long &b, const long long &c, const long long &d) {
//     int96 aa = init(a);
//     int96 cc = init(c);
//     aa = aa * init(b);
//     cc = cc * init(d);
//     if (aa > cc) {
//         return 1;
//     }
//     if (cc > aa) {
//         return -1;
//     }
//     return 0;
// }
int cmp(long long a, long long b, long long c, long long d) {
    long double dif = (long double) a * b - (long double) c * d;
    if (abs(dif) > 1e18) return sign(dif);
    return sign1(a * b - c * d);
}


int vec(const point &a, const point &b) {
    return cmp(a.x, b.y, a.y, b.x);
}


bool comp(const point &a, const point &b) {
    int s = cmp(a.x - gg.x, b.y - gg.y, b.x - gg.x, a.y - gg.y);
    if (s == 0) {
        return make_pair(abs(a.x - gg.x), abs(a.y - gg.y)) < make_pair(abs(b.x - gg.x), abs(b.y - gg.y));
    }
    return s < 0;
}

vector<point> convexhull(vector<point> p) {
    int k = sz(p);
    gg = p[0];
    for (int i = 1; i < k; i++) {
        if (gg.y > p[i].y || (gg.y == p[i].y && gg.x > p[i].x)) {
            gg = p[i];
        }
    }
    //cout << gg.x << ' ' << gg.y << '\n';
    sort(all(p), comp);
    p.resize(distance(p.begin(), unique(all(p))));
    vector<int> f;
    for (int i = 0; i < sz(p); i++) {
        if (sz(f) < 2) {
            f.pb(i);
            continue;
        }
        while (sz(f) >= 2 && vec(p[f[sz(f) - 1]] - p[f[sz(f) - 2]], p[i] - p[f[sz(f) - 2]]) >= 0) {
            f.pop_back();
        }
        f.pb(i);
    }
    while (sz(f) > 2 && vec(p[f[sz(f) - 1]] - p[f[sz(f) - 2]], p[0] - p[f[sz(f) - 2]]) >= 0) {
        f.pop_back();
    }
    vector<point> ans;
    for (auto x: f) {
        ans.pb(p[x]);
    }
    return ans;
}



inline int semiplane(const point &a) {
    return a.y > 0 || (a.y == 0 && a.x > 0);
}


inline bool comp1(const point &a, const point &b) {
    int t = semiplane(a);
    int t1 = semiplane(b);
    if (t != t1) {
        return t > t1;
    }
    int f = vec(a, b);
    if (f == 0) {
        return make_pair(abs(a.x), abs(a.y)) < make_pair(abs(b.x), abs(b.y));
    }
    return f < 0;
}


vector<point> minkovskiy(const vector<point> &a, const vector<point> &b) {
    vector<point> sum;
    vector<point> keka, kekb;
    for (int i = 0; i < sz(a); i++) {
        keka.pb(a[(i + 1) % sz(a)] - a[i]);
    }
    for (int i = 0; i < sz(b); i++) {
        kekb.pb(b[(i + 1) % sz(b)] - b[i]);
    }
    sum.resize(sz(keka) + sz(kekb));
    merge(all(keka), all(kekb), sum.begin(), comp1);
    point cur = a[0] + b[0];
    vector<point> res;
    res.pb(cur);
    int it = 0;
    for (auto x: sum) {
        it++;
        cur.x += x.x;
        cur.y += x.y;
       // assert(cur.x >= 0 && cur.y >= 0);
        if (it == sz(sum)) {
            continue;
        }
        res.pb(cur);
    }
    return res;
}


vector<point> kek;


void check() {
    sts[0] = convexhull(sts[0]);
    sts[1] = convexhull(sts[1]);
    vector<point> res = minkovskiy(sts[0], sts[1]);
    for (auto x: res) {
        kek.pb(x);
    }
}



void solve(int u, int pr = -1) {
    deep[u] = 0;
    st.clear();
    //memset(used, 0, sizeof(used));
    dfs1(u);
    if (sz(st) == 1) {
        return;
    }
    // if (n > 1000) {
    //     exit(0);
    // }
    int centroid = -1, centroid1 = -1;
    for (int i = 0; i < sz(st); i++) {
        if (sz[st[i]] < sz(st) / 2) {
            continue;
        }
        if (centroid == -1 || deep[centroid] < deep[st[i]]) {
            centroid = st[i];
        }
    }
    int ca, cb;
    for (auto x: ng[centroid]) {
        if (!bad[centroid][x.to]) {
            if (deep[x.to] > deep[centroid]) {
                if (sz[x.to] >= sz(st) / 3 && sz[x.to] <= (sz(st) + 1) / 2) {
                    centroid1 = x.to;
                    ca = x.a;
                    cb = x.b;
                    break;
                }
            } else {
                if (sz(st) - sz[centroid] >= sz(st) / 3 && sz(st) - sz[centroid] <= (sz(st) + 1) / 2) {
                    centroid1 = x.to;
                    ca = x.a;
                    cb = x.b;
                    break;
                }
            }
        }
    }   
    assert(centroid1 != -1);
    id = 0;
    sts[0].clear();
    dfs2(centroid, centroid1, ca, cb);
    id = 1;
    sts[1].clear();
    dfs2(centroid1, centroid);
    check();
    bad[centroid][centroid1] = true;
    bad[centroid1][centroid] = true;
    for (auto x: ng[centroid]) {
        if (bad[centroid][x.to]) {
            continue;
        }
        solve(x.to, centroid);
    }
    for (auto x: ng[centroid1]) {
        if (bad[centroid1][x.to]) {
            continue;
        }
        solve(x.to, centroid1);
    }
}


 
int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
   // read(FILENAME);
    //cin >> n >> m;
    n = readInt(), m = readInt();
    if (n == 1) {
        for (int i = 0; i < m; i++) {
           // cout << 0 << ' ';
            writeInt(0, ' ');
        }
        // cout << '\n';
        writeChar('\n');
        return 0;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v, a, b;
        //cin >> u >> v >> a >> b;
        u = readInt(), v = readInt(), a = readInt(), b = readInt();
        u--, v--;
        g[u].pb(edge(v, a, b));
        g[v].pb(edge(u, a, b));
    }
    uk = n;
    dfs(0);    
    n = uk;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += sz(ng[i]);
    }
  //  assert(sum == 2 * (n - 1));
    solve(0);
    kek = convexhull(kek);
    int uk = 0;
    for (int t = 0; t < m; t++) {
        //cout << kek[uk].x << ' ' << kek[uk].y << '\n';
        while (kek[uk].x * t + kek[uk].y < kek[(uk + 1 + sz(kek)) % sz(kek)].x * t + kek[(uk + 1 + sz(kek)) % sz(kek)].y) {
            uk = (uk + 1 + sz(kek)) % sz(kek);
        }
             //   assert(kek[uk].x >= 0 && kek[uk].y >= 0);
     //   assert(kek[uk].x >= 0);
        // cout << kek[uk].x * t + kek[uk].y  << ' ';
        writeInt(kek[uk].x * t + kek[uk].y, ' ');
    }
   // cout << '\n';
      writeChar('\n');
    return 0;       
}