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
#define ends ends228
#define begins begins228


int n;
int a[65][65];
long double dp[65][65][65];
long double ver[65][65][65];


int dfs(int l, int r) {
    if (l + 1 == r) {
        dp[l][r][l] = (long double)(a[l][r]) / 100.0;
        dp[l][r][r] = (long double)(a[r][l]) / 100.0;
        ver[l][r][l] = (long double)(a[l][r]) / 100.0;
        ver[l][r][r] = (long double)(a[r][l]) / 100.0;
        return 1;
    }
    int mid = (l + r) >> 1;
    int level = dfs(l, mid) << 1;
    dfs(mid + 1, r);
    for (int who = l; who <= mid; who++) {
        for (int who1 = mid + 1; who1 <= r; who1++) {
            ver[l][r][who] += ver[l][mid][who] * ver[mid + 1][r][who1] * ((long double)(a[who][who1]) / 100.0); 
        }
    }
    for (int who = mid + 1; who <= r; who++) {
        for (int who1 = l; who1 <= mid; who1++) {
            ver[l][r][who] += ver[l][mid][who1] * ver[mid + 1][r][who] * ((long double)(a[who][who1]) / 100.0); 
        }
    }
    for (int whos = l; whos <= r; whos++) {
        dp[l][r][whos] = ver[l][r][whos] * level;
        long double add = 0;
        for (int who = l; who <= mid; who++) {
            for (int who1 = mid + 1; who1 <= r; who1++) {
                if (who != whos && who1 != whos) {
                    continue;
                }
                chkmax(add, dp[l][mid][who] + dp[mid + 1][r][who1]);
            }
        }
        dp[l][r][whos] += add;
    }
    return level;
}


int main() {
    cin >> n;
    int k = (1 << n);
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            cin >> a[i][j];
        }
    }
    dfs(1, k);
    long double ans = 0.0;
    for (int i = 1; i <= k; i++) {
        chkmax(ans, dp[1][k][i]);
    }
    printf("%.10lf\n", (double)ans);
    return 0;
}