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
const int MAXN = 100011;
const int INF = 1000000001;


char s[20][MAXN];
int n, m;
int dp[21 * MAXN][21];


inline void add(int x) {
    int now = 0;
    int cnt = __builtin_popcount(x);
    for (int i = 0; i < n; i++) {
        dp[now][cnt]++;
        if ((x >> i) & 1) {
            now <<= 1;
            now += 2;
        } else {
            now <<= 1;
            now++;
        }
    }
    dp[now][cnt]++;
}


void change(int now, int h, int dist) {
    if (h != dist) {
        change((now << 1) + 1, h + 1, dist);
        change((now << 1) + 2, h + 1, dist);
        for (int i = 0; i <= n; i++) {
            dp[now][i] = dp[(now << 1) + 1][i] + dp[(now << 1) + 2][i];
        }
    } else {
        dp[now][0] = dp[(now << 1) + 2][1];
        dp[now][n] = dp[(now << 1) + 1][n - 1];
        for (int i = 1; i < n; i++) {
            dp[now][i] = dp[(now << 1) + 1][i - 1] + dp[(now << 1) + 2][i + 1];
        }
    }
}


int main() {
    n = readInt(), m = readInt();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            s[i][j] = readChar();
        }
    }
    for (int i = 0; i < m; i++) {
        int x = 0;
        for (int j = 0; j < n; j++) {
            x <<= 1;
            x += s[j][i] - '0';
        }
        add(x);
    }
    int ans = n * m;
    for (int i = 0; i < (1 << n); i++) {
        int sum = 0;
        for (int j = 0; j <= n; j++) {
            sum += dp[0][j] * min(j, n - j);
        }
        chkmin(ans, sum);
        if (i + 1 != (1 << n)) {
            for (int j = 0; j < n; j++) {
                if (((i >> j) & 1) == 0) {
                    change(0, 0, j);
                    break;
                }
            }
        }
    }
    writeInt(ans, '\n');
    return 0;
}