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
  
using namespace std;

const int MAXN = 11;
const int MAXM = 1228;
int n, m, k;
int g[MAXN][MAXN];
int ans;
int sz[MAXM];
int masks[MAXN];
int first[MAXM];


void dfs(int f, int h, int cnt) {
    if (f == (1 << n) - 1) {
        if (cnt == k) {
            ans++;
        }
        return;
    }
    if (h == 0) {
        return;
    }
    int j = first[h];
    int jst = (1 << j);
    int nmask = (masks[j] ^ f) & masks[j];
    for (int st = nmask; st != 0; st = (st - 1) & nmask) {
        int nf = f | st;
        int nh = (h ^ jst) | st;
        int ncnt = cnt + sz[st] - 1;
        if (f == 1 && sz[st] == 1) {
            ncnt++;
        }
        dfs(nf, nh, ncnt);
    }
    dfs(f, h ^ jst, cnt);
}


int main() {
    n = readInt(), m = readInt(), k = readInt();
    for (int i = 0; i < m; i++) {
        int a = readInt(), b = readInt();
        a--, b--;
        g[a][b] = g[b][a] = 1; 
    }
    for (int f = 1; f < (1 << n); f++) {
        sz[f] = (f & 1) + sz[f >> 1];
        for (int j = 0; j < n; j++) {
            if (f & (1 << j)) {
                first[f] = j;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            masks[i] |= (g[i][j] << j); 
        }
    }
    dfs(1, 1, 1);
    writeInt(ans, '\n');
    return 0;
}