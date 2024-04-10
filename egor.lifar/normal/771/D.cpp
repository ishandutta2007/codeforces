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
const int MAXN = 77;
const int INF = 1000000000;


int n;
char s[MAXN];
int t[MAXN];
int pos[3][MAXN];
int cnt[3];
int f[3][MAXN][3][MAXN];
int dp[3][MAXN][MAXN][MAXN];


int main() {
    n = readInt();
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
        s[i] = readChar();
        if (s[i] == 'V') {
            t[i] = 0;
            pos[0][cnt[0]] = i;
            cnt[0]++;
        } else if (s[i] == 'K') {
            t[i] = 1;
            pos[1][cnt[1]] = i;
            cnt[1]++;
        } else {
            t[i] = 2;
            pos[2][cnt[2]] = i;
            cnt[2]++;
        }
    }
    memset(f, 0, sizeof(f));
    for (int t = 0; t < 3; t++) {
        for (int i = 0; i < cnt[t]; i++) {
            for (int nt = 0; nt < 3; nt++) {
                if (nt == t) {
                    continue;
                }
                for (int j = 0; j <= cnt[nt]; j++) {
                    int &cur = f[t][i][nt][j];
                    cur = 0;
                    for (int r = 0; r < j; r++) {
                        if (pos[nt][r] > pos[t][i]) {
                            cur++;
                        }
                    }
                }
            }
        }
    }
    for (int t = 0; t < 3; t++) {
        for (int i = 0; i <= cnt[0]; i++) {
            for (int j = 0; j <= cnt[1]; j++) {
                for (int k = 0; k <= cnt[2]; k++) {
                    dp[t][i][j][k] = INF;
                }
            }
        }
    }
    dp[2][0][0][0] = 0;
    for (int i = 0; i <= cnt[0]; i++) {
        for (int j = 0; j <= cnt[1]; j++) {
            for (int k = 0; k <= cnt[2]; k++) {
                int a[3] = {i, j, k};
                for (int t = 0; t < 3; t++) {
                    for (int nt = 0; nt < 3; nt++) {
                        if (t == 0 && nt == 1) {
                            continue;
                        }
                        if (dp[t][i][j][k] == INF) {
                            continue;
                        }
                        if (a[nt] == cnt[nt]) {
                            continue;
                        }
                        int cur = f[nt][a[nt]][0][a[0]];
                        cur += f[nt][a[nt]][1][a[1]];
                        cur += f[nt][a[nt]][2][a[2]];
                        dp[nt][i + (nt == 0)][j + (nt == 1)][k + (nt == 2)] = min(dp[nt][i + (nt == 0)][j + (nt == 1)][k + (nt == 2)], dp[t][i][j][k] + cur);
                    }  
                }
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < 3; i++) {
        chkmin(ans, dp[i][cnt[0]][cnt[1]][cnt[2]]);
    }
    writeInt(ans, '\n');
    return 0;
}