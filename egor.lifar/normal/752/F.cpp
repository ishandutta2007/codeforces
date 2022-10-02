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
  
struct Flusher {
    ~Flusher() {
        if (write_pos)
            fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
    }
} flusher;
  

#define left left228
#define right right228  
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
const int MAXN = 200228;


int n;
vector<int> g[MAXN];
int k;
int sz[MAXN];
bool good[MAXN];
vector<int> ans;
int norm;


void dfs1(int u, int p = -1) {
    if (good[u]) {
        sz[u] = 1;
    }
    for (auto h: g[u]) {
        if (h != p) {
            dfs1(h, u);
            sz[u] += sz[h];
        }
    }
}


int f(int u, int p, int curSize) {
    for (auto h: g[u]) {
        if (h != p && sz[h] * 2 > curSize) {
            return f(h, u, curSize);
        }
    }
    return u;
}


void dfs(int u, int p) {
    if (good[u]) {
        ans.push_back(u);
    }
    for (auto h: g[u]) {
        if (h != p) {
            dfs(h, u);
        }
    }
}



bool comp(int a, int b) {
    return sz[a] < sz[b];
}



int main() {
    n = readInt(), k = readInt();
    for (int i = 0; i < n - 1; i++){
        int a = readInt(), b = readInt();
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < 2 * k; i++){
        int a = readInt();
        a--;
        good[a] = 1;
    }
    dfs1(0);
    norm = f(0, -1, sz[0]);
    writeWord("1\n");
    writeInt(norm + 1, '\n');
    int v = norm;
    sort(all(g[v]), comp);
    for (int i = 0; i < sz(g[v]); i++) {
        dfs(g[v][i], v);
    }
    if (good[v]) {
        ans.push_back(v);
    }
    for (int i = 0; i < k; i++) {
        writeInt(ans[i] + 1, ' ');
        writeInt(ans[i + k] + 1, ' ');
        writeInt(v + 1, '\n');
    }
    return 0;
}