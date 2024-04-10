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
  

#define prev prev228
#define left left228
#define right right228  
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
const int MAXN = 400001;
const long long h1 = 1000003;
const long long h2 = 424243;


long long hashes[MAXN];
long long in[MAXN];
long long d[MAXN];
long long s[MAXN];
int an[MAXN];
int szv;
vector<int> g[MAXN];
int cnts[MAXN];
int cur;
int ans = 0;
int ansv;


void lower(long long &x) {
    x = lower_bound(in, in + szv, x) - in;
}

    

void change(int i, int j) {
    if (cnts[i] == 1) {
        cur--;
    }
    cnts[i]--;
    if (cnts[j] == 0) {
        cur++;
    }
    cnts[j]++;
}

void dfs1(int u, int pr = -1) {
    d[u] = 0;
    for (auto h: g[u]) {
        if (h != pr) {
            dfs1(h, u);
            d[u] += d[h] * h1;
        }
    }
    d[u] ^= h2;
}


void dfs2(int u, int pr = -1) {
    hashes[u] = d[u] ^ h2;
    if (pr != -1) {
        hashes[u] += s[u] * h1;
    }
    hashes[u] ^= h2;
    for (auto h: g[u]) {
        if (h != pr) {
            s[h] = ((hashes[u] ^ h2) - d[h] * h1) ^ h2;
            dfs2(h, u);
        }
    }
}


void dfs3(int u, int pr) {
    if (pr != -1) {
        change(hashes[pr], s[u]);
        change(d[u], hashes[u]);
    }
    if (cur > ans) {
        ans = cur, ansv = u;
    }
    an[u] = cur;
    for (auto h: g[u]) {
        if (h != pr) {
            dfs3(h, u);
        }
    }
    if (pr != -1) {
        change(s[u], hashes[pr]);
        change(hashes[u], d[u]);
    }
}


int main() {
    int n = readInt();
    for (int i = 0; i < n - 1; i++) {
        int a = readInt(), b = readInt();
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs1(1);
    dfs2(1);
    for (int i = 1; i <= n; i++) {
        in[i * 3 - 3] = d[i];
        in[i * 3 - 2] = hashes[i];
        in[i * 3 - 1] = s[i];
    }
    sort(in, in + 3 * n);
    memset(cnts, 0, sizeof(cnts));
    szv = unique(in, in + 3 * n) - in;
    cur = 1;
    for (int i = 1; i <= n; i++) {
        lower(d[i]);
        lower(hashes[i]);
        lower(s[i]);
    }
    cnts[hashes[1]] = n;
    for (int i = 2; i <= n; i++) {
        change(hashes[1], d[i]);
    }
    dfs3(1, 1);
    writeInt(ansv, '\n');
    return 0;
}