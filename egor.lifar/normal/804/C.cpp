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
const int MAXN = 510000;


vector<int> c[MAXN], g[MAXN];
int col[MAXN];
int fr[MAXN];
int ans = 1;


void dfs(int v, int p) {
    chkmax(ans, sz(c[v]));
    for (int i = 0; i < sz(c[v]); i++) {
        fr[i] = 1;
    }
    for (auto x: c[v]) {
        if (col[x] != -1) {
            fr[col[x]] = 0;
        }
    }
    int z = 0;
    for (auto x: c[v]) {
        if (col[x] != -1) {
            continue;
        }
        while (!fr[z]) {
            ++z;
        }
        col[x] = z++;
    }
    for (auto u: g[v]) {
        if (u == p) {
            continue;
        }
        dfs(u, v);
    }
}


int main() {
    int n = readInt(), m = readInt();
    for (int i = 0; i < n; i++) {
        int x = readInt();
        c[i].resize(x);
        for (int j = 0; j < x; j++) {
            c[i][j] = readInt();
            c[i][j]--;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        int x = readInt(), y = readInt();
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 0; i < m; i++) { 
        col[i] = -1;
    }
    dfs(0, -1);
    writeInt(ans, '\n');
    for (int i = 0; i < m; i++) {
        if (col[i] == -1) {
            col[i] = 0;
        }
        writeInt(col[i] + 1, ' ');
    }
    writeChar('\n');
    return 0;
}