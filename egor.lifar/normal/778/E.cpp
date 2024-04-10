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


const int MAXN = 1015;
int n;
int b[MAXN][MAXN];
char c[MAXN];
char a[MAXN];
int w[15];
int len = 0;
int sa[MAXN], rk[MAXN];
int tsa[MAXN], trk[MAXN];
int sum[15];
int f[2][MAXN];
int cost[MAXN][12][2];
int dj[11][MAXN];
int lp[MAXN];



int main(){
    scanf("%s", a + 1);
    n = strlen(a + 1);
    len = n;
    for (int i = 1; i <= n; i++) {
        if (i < n + 1 - i) {
            swap(a[i], a[n + 1 - i]);
        }
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", c + 1);
        int m = strlen(c + 1);
        lp[i] = m;
        for (int j = 1; j <= m; j++) {
            b[i][j] = c[m + 1 - j] - '0';
        }
    }
    for (int i = 0; i < 10; i++)  {
        scanf("%d", &w[i]);
    }
    for (int i = 1; i <= n; i++) {
        sa[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        rk[sa[i]] = i;
    }
    for (int i = 0; i <= n; i++) {
        f[0][i] = f[1][i] = -1000000000;
    }
    int now = 0;
    f[0][0] = 0;
    for (int bit = 1; bit <= 1005; bit++) {
        for (int i = 0; i <= n; i++)  {
            f[now ^ 1][i] = -1000000000;
        }
        memset(cost, 0, sizeof(cost));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 2; k++) {
                    if ((bit <= max(lp[sa[i]],len)) || (bit == max(lp[sa[i]], len) + 1 && (b[sa[i]][bit] + j + k) % 10 != 0)) {
                        cost[i][j][k]=cost[i - 1][j][k]+w[(b[sa[i]][bit]+j+k)%10];
                    } else {
                        cost[i][j][k] = cost[i - 1][j][k];
                    }
                }
            }
        }
        memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= n; i++) {
            sum[b[i][bit]]++;
        }
        for (int i = 8; i >= 0; i--) {
            sum[i] += sum[i + 1];
        }
        for (int i = n; i >= 1; i--) {
            tsa[sum[b[sa[i]][bit]]--] = sa[i];
        }
        for (int i = 1; i <= n; i++) {
            trk[tsa[i]] = i;
        }
        for (int i = 0; i < 10; i++) {
            int uk = 0;
            while (uk < n && b[tsa[uk + 1]][bit] > i) {
                uk++;
            }
            for (int j = 0; j <= n; j++) {
                while (uk < n && rk[tsa[uk + 1]] <= j && b[tsa[uk + 1]][bit] == i) {
                    uk++;
                }
                dj[i][j] = uk;
            }
        }
        for (int i = 0; i <= n; i++) {
            if (f[now][i] >= 0) {
                for (int v = 0; v < 10; v++){
                    if (v > 0 && bit > len) {
                        continue;
                    }
                    if (bit <= len && a[bit] != '?' && (a[bit] - '0' != v)) {
                        continue;
                    }
                    if (bit == len && v == 0) {
                        continue;
                    }
                    chkmax(f[now ^ 1][dj[9 - v][i]], f[now][i] + cost[i][v][1] + cost[n][v][0] - cost[i][v][0]);
                }
            }
        }
        now ^= 1;
        for (int i = 1; i <= n; i++) {
            sa[i] = tsa[i], rk[i] = trk[i];
        }
    }
    printf("%d\n", f[now][0]);
    return 0;
}