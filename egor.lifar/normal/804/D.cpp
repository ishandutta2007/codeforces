/*
  !










*/
#include <iostream>
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
  
using namespace std;


#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define next next228
#define rank rank228
#define prev prev228
const int MAXN = 100228;


vector<int> g[MAXN];
int id[MAXN];
int ecnt[MAXN], vcnt[MAXN];
bool used[MAXN];
int diam[MAXN];
vector<int> dists[MAXN];
vector<long long> suffs[MAXN];
int deep[MAXN];


void dfs(int v) {
    used[v] = true;
    for (auto to: g[v]) {
        if (!used[to]) {
            id[to] = id[v];
            dfs(to);
        }
    }
}


void dfs2(int v, int p) {
    for (auto to: g[v]) {
        if (to != p) {
            dfs2(to, v);
            chkmax(deep[v], deep[to] + 1);
        }
    }
}


void dfs3(int v, int p, int up) {
    pair<int, int> mx1 = make_pair(up, 0), mx2 = make_pair(0, 0);
    for (auto to: g[v]) {
        if (to != p) {
            pair<int, int> cur = make_pair(deep[to] + 1, to);
            if (cur > mx1) {
                mx2 = mx1;
                mx1 = cur;
            } else if (cur > mx2) {
                mx2 = cur;
            }
        }
    }
    diam[id[v]] = max(diam[id[v]], mx1.first + mx2.first);
    dists[id[v]].push_back(mx1.first);
    for (auto to: g[v]) {
        if (to != p) {
            if (to == mx1.second) {
                dfs3(to, v, mx2.first + 1);
            } else {
                dfs3(to, v, mx1.first + 1);
            }
        }
    }
}


int main() {
    int n = readInt(), m = readInt(), q = readInt();
    for (int i = 1; i <= m; i++) {
        int u = readInt(), v = readInt();
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> roots;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            roots.push_back(i);
            id[i] = i;
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        ecnt[id[i]] += sz(g[i]);
        vcnt[id[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        ecnt[i] >>= 1;
    }
    for (int i = 0; i < sz(roots); i++) {
        int v = roots[i];
        dfs2(v, -1);
        dfs3(v, -1, 0);
        sort(all(dists[v]));
        suffs[v].resize(sz(dists[v]));
        suffs[v].back() = dists[v].back();
        for (int j = sz(dists[v]) - 2; j >= 0; j--) {
            suffs[v][j] = suffs[v][j + 1] + dists[v][j];
        }
    }
    map<pair<int, int>, double> mm;
    for (int it = 1; it <= q; it++) {
        int u = readInt(), v = readInt();
        u = id[u];
        v = id[v];
        if (u > v) {
            swap(u, v);
        }
        if (mm.count(make_pair(u, v))) {
            printf("%.10lf\n", mm[make_pair(u, v)]);
        } else if (id[u] == id[v]) {
            printf("-1\n");
        } else if (ecnt[u] != vcnt[u] - 1 || ecnt[v] != vcnt[v] - 1) {
            printf("-1\n");
        } else {
            int a = id[u], b = id[v];
            if (sz(dists[a]) > sz(dists[b])) {
                swap(a, b);
            }
            int canDiam = max(diam[a], diam[b]);
            long long ans = 0;
            for (int i = 0; i < sz(dists[a]); i++) {
                int need = canDiam - dists[a][i] - 1;
                int j = lower_bound(all(dists[b]), need) - dists[b].begin();
                ans += 1LL * j * canDiam;
                ans += 1LL * (dists[a][i] + 1) * (sz(dists[b]) - j);
                if (j != sz(dists[b])) {
                    ans += suffs[b][j];
                }
            }
            long long ways = 1LL * vcnt[a] * vcnt[b];
            mm[make_pair(u, v)] = 1.0 * ans / ways;
            printf("%.10lf\n", mm[make_pair(u, v)]);
        }
    }
    return 0;
}