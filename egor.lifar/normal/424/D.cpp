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
const int MAXN = 301;


int n, m, t;
int h[MAXN][MAXN];
int tp, tu, td;
long long sums[MAXN][MAXN];
long long sums1[MAXN][MAXN];
long long sums2[MAXN][MAXN];
long long sums3[MAXN][MAXN];


int main() {
    n = readInt(), m = readInt(), t = readInt();
    tp = readInt(), tu = readInt(), td = readInt();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            h[i][j] = readInt();
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m - 1; j++) {
            if (j) {
                sums[i][j] = sums[i][j - 1];
            } else {
                sums[i][j] = 0;
            }
            if (h[i][j + 1] == h[i][j]) {
                sums[i][j] += tp;
            } else if (h[i][j + 1] > h[i][j]) {
                sums[i][j] += tu;
            } else {
                sums[i][j] += td;
            }
        }
        for (int j = 1; j <= m - 1; j++) {
            if (j) {
                sums2[i][j] = sums2[i][j - 1];
            } else {
                sums2[i][j] = 0;
            }
            if (h[i][j + 1] == h[i][j]) {
                sums2[i][j] += tp;
            } else if (h[i][j + 1] > h[i][j]) {
                sums2[i][j] += td;
            } else {
                sums2[i][j] += tu;
            }
        }
    } 
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n - 1; j++) {
            if (j) {
                sums1[j][i] = sums1[j - 1][i];
            } else {
                sums1[j][i] = 0;
            }
            if (h[j + 1][i] == h[j][i]) {
                sums1[j][i] += tp;
            } else if (h[j + 1][i] > h[j][i]) {
                sums1[j][i] += tu;
            } else {
                sums1[j][i] += td;
            }
        }
        for (int j = 1; j <= n - 1; j++) {
            if (j) {
                sums3[j][i] = sums3[j - 1][i];
            } else {
                sums3[j][i] = 0;
            }
            if (h[j + 1][i] == h[j][i]) {
                sums3[j][i] += tp;
            } else if (h[j + 1][i] > h[j][i]) {
                sums3[j][i] += td;
            } else {
                sums3[j][i] += tu;
            }
        }
    } 
    long long diff = 1e18;
    int a, b, c, d;
    int its = 0;
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            for (int i1 = i + 2; i1 <= n; i1++) {
                for (int j1 = j + 2; j1 <= m; j1++) {
                    long long sum = sums[i][j1 - 1] - sums[i][j - 1];
                    sum += sums2[i1][j1 - 1] - sums2[i1][j - 1];
                    sum += sums3[i1 - 1][j] - sums3[i - 1][j];
                    sum += sums1[i1 - 1][j1] - sums1[i - 1][j1];
                    if (abs(sum - t) < diff) {
                        diff = abs(sum - t);
                        a = i, b = j, c = i1, d = j1;
                    }
                }   
            }
            its += (n - i - 1) * (m - j - 1);
            if (its >= 300000000) {
                break;
            }
        }
        if (its >= 300000000) {
            break;
        }
    }
    cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
    return 0;
}