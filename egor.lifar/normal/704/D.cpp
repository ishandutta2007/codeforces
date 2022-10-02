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
const int MAXV = 400000;
const int MAXN = 400000;
const int MAXE = 800000;
const int inf = 1000000000;


int V, E, src, tar;
int head[MAXV], work[MAXV], dis[MAXV], Sx[MAXV], xT[MAXV];
int to[MAXE], cap[MAXE], next[MAXE];
int q[MAXV], qf, qb;

inline void init(int n) {
    memset(head, -1, sizeof(int)*n);
    V = n; E = 0;
}


inline void add_edge(int u, int v, int c) {
    to[E] = v; cap[E] = c; next[E] = head[u]; head[u] = E++;
    to[E] = u; cap[E] = 0; next[E] = head[v]; head[v] = E++;
}


inline void add_edge(int u, int v, int l, int r) {
    if (l) {
        Sx[v] += l, xT[u] += l;
    }
    add_edge(u, v, r - l);
}


inline bool bfs() {
    memset(dis, -1, sizeof(dis));
    qf = qb =0;
    q[qb++] = src; dis[src] = 0;
    while (qf < qb && dis[tar] == -1) {
        int u = q[qf++];
        for (int i = head[u]; i >= 0; i = next[i]) {
            int v=to[i];
            if (dis[v] == -1 && cap[i] > 0) {
                dis[v] = dis[u]+1;
                q[qb++] = v;
            }
        }
    }
    return dis[tar] >= 0;
}


int dfs(int u, int &bot) {
    if (u == tar) {
        return bot;
    }
    for (int &i = work[u]; i >= 0; i = next[i]) {
        int v = to[i];
        if (dis[v] != dis[u] + 1 || cap[i] == 0) {
            continue;
        }
        int bot1 = min(bot, cap[i]);
        if (int flow = dfs(v, bot1)) {
            cap[i] -= flow;
            cap[i ^ 1] += flow;
            bot = bot1;
            return flow;
        }
    }
    return 0;
}


int dinic() {
    int ans = 0, bot;
    while (bfs()) {
        memcpy(work, head, sizeof(int)*V);
        int flow = inf;
        while (flow = dfs(src, bot = inf)) {
            ans += flow;
        }
    }
    return ans;
}


int x[MAXN], y[MAXN], xx[MAXN], yy[MAXN], nx, ny, cx[MAXN], cy[MAXN], dx[MAXN], dy[MAXN], id[MAXN];


int main() {
    int ok = 0;
    int N = readInt(), M = readInt(), R = readInt(), B = readInt();
    if (R < B) {
        swap(R, B);
        ok = 1;
    }
    for (int i = 0; i < N; i++) {
        x[i] = readInt(), y[i] = readInt();
        xx[nx++] = x[i]; yy[ny++] = y[i];
    }
    sort(xx, xx + nx); 
    nx = unique(xx, xx + nx) - xx;
    sort(yy, yy + ny); 
    ny = unique(yy, yy + ny) - yy;
    for (int i = 0; i < N; i++) {
        x[i] = lower_bound(xx, xx + nx, x[i]) - xx;
        y[i] = lower_bound(yy, yy + ny, y[i]) - yy; 
        cx[x[i]]++; cy[y[i]]++;     
    }
    for (int i = 0; i < N; i++) {
        dx[i] = cx[i], dy[i] = cy[i];
    }
    for (int i = 0; i < M; i++) {
        int t = readInt(), u = readInt(), v = readInt();
        int uu = u;
        if (t == 1) {
            u = lower_bound(xx, xx + nx, u) - xx;
            if (xx[u] == uu) {
                chkmin(dx[u], v);
            }
        } else {
            u = lower_bound(yy, yy + ny, u) - yy;
            if (yy[u] == uu) {
                chkmin(dy[u], v);
            }
        } 
    }
    int ss = nx + ny; 
    int tt = ss + 1;
    src = tt + 1; tar = src + 1;
    init(tar +  10);
    for (int i = 0; i < N; i++) {
        id[i] = E + 1;
        add_edge(x[i], y[i] + nx, 0, 1);
    }
    for (int i = 0; i < nx; i++) {
        int d = dx[i], c = cx[i];
        int l = (c - d) / 2 + (c - d) % 2, r = (c + d) / 2;
        if (l > r) {
            writeWord("-1\n"); 
            return 0;
        }
        add_edge(ss, i, l, r);
    }
    for (int i = 0; i < ny; i++) {
        int d = dy[i], c = cy[i];
        int l = (c - d) / 2 + (c - d) % 2, r = (c + d) / 2;
        if (l > r) {
            writeWord("-1\n"); 
            return 0;
        }
        add_edge(i + nx, tt, l, r);   
    }
    for (int i = 0; i <= tt; i++) {
        if (Sx[i]) {
            add_edge(src, i, Sx[i]);
        }
        if (xT[i]) {
            add_edge(i, tar, xT[i]);
        }
    }
    dinic();
    add_edge(tt, ss, inf);
    dinic();
    for (int e = head[src]; e != -1; e = next[e]) { 
        if (cap[e]) {
            writeWord("-1\n"); 
            return 0;
        }
    }
    int t = cap[E - 1];
    cout << 1LL * R * t + 1LL * B * (N - t) << '\n';
    for (int i = 0; i < N; i++) {
        int ID = id[i];
        if (cap[ID] ^ ok) {
            writeChar('r');
        } else {
            writeChar('b');
        }
    }
    writeChar('\n');
    return 0;
}