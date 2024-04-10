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
   
   
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define next next228
#define rank rank228
#define prev prev228
#define y1 y1228
const int MAXN = 305;


vector<int> g[MAXN];
pair<pair<int, int>, int> ans[MAXN * MAXN * 2];
pair<int, int> p[MAXN];
int aa[MAXN], bb[MAXN], f[MAXN], dong[MAXN];
int k;


inline void up(int u, int v, int c) {
    ans[k++] = make_pair(make_pair(u, v) ,c);
    aa[u] -= c;
    aa[v] += c;
}


void dfs(int x, int need) {
    f[x] = 1;
    for (int i = sz(g[x]) - 1; i >= 0 && aa[x] < need; i--) {
        int j = g[x][i];
        if (f[j]) {
            continue;
        }
        if (dong[j]) {
            int tmp = min(bb[j], need - aa[x]);
            up(j, x, tmp);
            dfs(j, bb[j]);
            if (aa[j] < bb[j]) {
                up(x, j, bb[j] - aa[j]);
            }
        } else {
            dfs(j, need);
            int limit = min(aa[j], need - aa[x]);
            up(j, x, limit);
        }
    }
}


int main() {
    int n = readInt(), v = readInt(), m = readInt();
    for (int i = 1; i <= n; i++) {
        aa[i] = readInt();
    }
    for (int i = 1; i <= n; i++) {
        bb[i] = readInt();
    }
    for (int i = 1; i <= n; i++) {
        p[i - 1] = make_pair(-bb[i], i);
    }
    sort(p, p + n);
    for (int i = 0; i < m; i++) {
        int a = readInt(), b = readInt();
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int h = 0; h < n; h++) {
        int i = p[h].second;
        memset(f, 0, sizeof(f));
        dfs(i, bb[i]);
        dong[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (aa[i] != bb[i]) {
            writeWord("NO\n");
            return 0;
        }
    }
    writeInt(k, '\n');
    for (int i = 0; i < k; i++) {
        writeInt(ans[i].first.first, ' ');
        writeInt(ans[i].first.second, ' ');
        writeInt(ans[i].second, '\n');
    }
    return 0;
}