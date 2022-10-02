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
 
struct flusher {
    ~flusher() {
        if (write_pos)
            fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
    }
} flusher;
 
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#define left _left
#define right _right
#define last _last
#define sz(c) (int)(c).size()
#define al(c) (c).begin(), (c).end()
const int MAXN = 1003;
const int MAXK = 53;


short int sums[3][MAXN];
short int dp[2][MAXK][MAXN][MAXN];


inline short int Max(short int a, short int b) {
    if (a > b) {
        return a;
    }
    return b;
}


short int getsum(int a, int b, int c) {
    return sums[c][b] - sums[c][a - 1];
}


int main() {
    int n = readInt(), p = readInt(), k = readInt();
    for (int i = 0; i < 2; i++) {
        int cnt = readInt();
        for (int j = 1; j <= cnt; j++) {
            int x = readInt();
            sums[i][x] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        sums[2][i] = sums[1][i] | sums[0][i];
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= n; j++) {
            sums[i][j] += sums[i][j - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int l = 1; l < k && l <= i; l++) {
            for (int q = 0; q < 2; q++) {
                dp[q][l][i][0] = getsum(i - l + 1, i, q);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= p; j++) {
            for (int l = 0; l < k && l <= i; l++) {
                for (int q = 0; q < 2; q++) {
                    if (l) {
                        dp[q][l][i][j] = Max(dp[q][l - 1][i - 1][j] + getsum(i, i, q), dp[1 - q][min(i, k) - l][i - l][j - 1] + getsum(i - l + 1, i, 2));
                    } else {
                        dp[q][l][i][j] = Max(dp[q][l][i - 1][j], dp[q][l][max(i - k, 0)][j - 1] + max(getsum(max(i - k + 1, 1), i, 0), getsum(max(i - k + 1, 1), i, 1)));
                        if (j > 1) {
                            for (int m = max(i - k + 1, 1); m < i; m++) {
                                for (int t = 0; t < 2; t++) {
                                    chkmax(dp[q][l][i][j], dp[t][min(m, k) - (m - max(i - k + 1, 1) + 1)][max(i - k, 0)][j - 2] + getsum(m + 1, i, 1 - t) + getsum(max(i - k + 1, 1), m, 2));
                                }
                            }
                        }
                    }
                    chkmax(dp[q][l][i][j], dp[q][l][i][j - 1]);
                }
            }
        }
    }
    writeInt(dp[0][0][n][p], '\n');
    return 0;
}