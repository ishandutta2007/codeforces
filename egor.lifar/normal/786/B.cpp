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
#include <cassert>

 
 
using namespace std;
 
 
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }
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
    if (pos == len)
        pos = 0, len = fread(buf, 1, buf_size, stdin);
    if (pos == len)
        return -1;
    return buf[pos++];
}
 
inline int readChar() {
    int c = getChar();
    while (c <= 32)
        c = getChar();
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
 
inline void writeWord( const char *s ) {
    while (*s)
        writeChar(*s++);
}
 
struct flusher {
    ~flusher() {
        if (write_pos)
            fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
    }
} flusher;
 
 
#define hash hash228 
#define next next228
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
const int MAXN = 500000;
const long long INF = 1e18;


vector<pair<long long, long long> > g[MAXN];
int lc[MAXN], rc[MAXN];
int vc = 0;


void addEdge(int v, int u, bool rev = false, long long cost = 0) {
    if (rev) {
        swap(v, u);
    }
    g[v].push_back(make_pair(u, cost));
}


int buildTree(int l, int r, bool down, vector<int> &leaves) {
    int v = vc++;
    if (r - l == 1) {
        leaves[l] = v;
    } else {
        int m = (l + r) >> 1;
        addEdge(v, lc[v] = buildTree(l, m, down, leaves), !down);
        addEdge(v, rc[v] = buildTree(m, r, down, leaves), !down);
    }
    return v;
}


void addSegEdges(int v, int l, int r, int lq, int rq, bool rev, int from, int w) {
    if (max(l, lq) >= min(r, rq)) {
        return;
    }
    if (lq <= l && r <= rq) {
        addEdge(from, v, rev, w);
        return;
    }
    int m = (l + r) >> 1;
    addSegEdges(lc[v], l, m, lq, rq, rev, from, w);
    addSegEdges(rc[v], m, r, lq, rq, rev, from, w);
}


long long dist[MAXN];


int main() {
    int n, q, s;
    cin >> n >> q >> s;
    s--;
    vector<int> ld(n), lu(n);
    int rd = buildTree(0, n, true, ld);
    int ru = buildTree(0, n, false, lu);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            addEdge(ld[i], lu[i], j);
        }
    }
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int v, u, w;
            cin >> v >> u >> w;
            v--, u--;
            addEdge(ld[v], ld[u], false, w);
        } else {
            int v, l, r, w;
            cin >> v >> l >> r >> w;
            v--, l--;
            if (t == 2) {
                addSegEdges(rd, 0, n, l, r, false, ld[v], w);
            } else {
                addSegEdges(ru, 0, n, l, r, true, ld[v], w);
            }   
        }
    }
    priority_queue<pair<long long, long long> > qq;
    for (int i = 0; i < vc; i++) {
        dist[i] = INF;
    }
    dist[ld[s]] = 0;
    qq.push(make_pair(0, ld[s]));
    while (!qq.empty()) {
        auto w = qq.top();
        qq.pop();
        int v = w.second;
        long long dd = -w.first;
        if (dd != dist[v]) {
            continue;
        }
        for (auto ww: g[v]) {
            int u = ww.first;
            long long ncost = dd + ww.second;
            if (uin(dist[u], ncost)) {
                qq.push(make_pair(-dist[u], u));
            }
        }
    }
    for (int i = 0; i < n; i++) { 
        int v = ld[i];
        if (dist[v] >= INF) {
            printf("-1 ");
        } else {
            printf("%lld ", dist[v]);
        }
    }
    writeChar('\n');
    return 0;
}