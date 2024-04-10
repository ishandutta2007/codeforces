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
  

#define prev prev228
#define left left228
#define right right228  
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
const int MAXN = 150228;
const int MAXT = 10000000;


int n, m, h, k;
int left[MAXT], right[MAXT], f[MAXT], g[MAXT];
int a[MAXN];
int root = 0;


void add(int &uk, int l, int r, int v, int d) {
    if (uk == 0) {
        uk = ++k;
        left[uk] = 0;
        right[uk] = 0;
        f[uk] = 0;
        g[uk] = 0;
    }
    if (l == r) {
        f[uk] += d;
        g[uk] = f[uk];
        return;
    }
    f[uk] += d;
    int vm = (l + r) >> 1;
    if (v <= vm) {
        add(left[uk], l, vm, v, d);
    } else {
        add(right[uk], vm + 1, r, v, d);
    }   
    g[uk] = 0;
    g[uk] = min(g[uk], left[uk] == 0 ? 0 : g[left[uk]]);
    g[uk] = min(g[uk], (left[uk] == 0 ? 0 : f[left[uk]]) + (right[uk] == 0 ? 0 : g[right[uk]]));
}


int main() {
    n = readInt(), m = readInt(), h = readInt();
    for (int i = 0; i < m; i++) {
        int b = readInt();
        add(root, 1, h, max(h - b, 1), 1);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        a[i] = readInt();
        add(root, 1, h, a[i], -1);
        if (i >= m) {
            ans += (g[root] >= 0);
            add(root, 1, h, a[i - m + 1], 1);
        }
    }
    writeInt(ans, '\n');
    return 0;
}