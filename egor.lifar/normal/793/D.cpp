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
const int inf = 2000000001;
const int MAXN = 81;


int n, k, m;
int dp[MAXN][MAXN][2][MAXN];
int dist[MAXN][MAXN];
vector<pair<int, int> > v[MAXN];


int main() {
    n = readInt(), k = readInt(), m = readInt();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = inf;
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        a = readInt(), b = readInt(), c = readInt();
        chkmin(dist[a - 1][b - 1], c);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && dist[i][j] != inf) {
                v[i].push_back(make_pair(j, dist[i][j]));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int h = 0; h < 2; h++) {
                for (int cnt = 1; cnt <= k; cnt++) {
                    dp[i][j][h][cnt] = inf;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        dp[0][i][1][1] = 0;
        dp[i][n - 1][0][1] = 0;
    }
    for (int kt = 1; kt < k; kt++) {
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                for (int h = 0; h < 2; h++) {
                    if (dp[i][j][h][kt] != inf) {
                        int p = dp[i][j][h][kt];
                        for (auto x: v[(h == 0 ? i: j)]) {
                            if (x.first >= i && x.first <= j) {
                                if (h) {
                                    chkmin(dp[i][x.first][1][kt + 1], p + x.second);
                                    chkmin(dp[x.first][j - 1][0][kt + 1], p + x.second);
                                } else {
                                    chkmin(dp[i + 1][x.first][1][kt + 1], p + x.second);
                                    chkmin(dp[x.first][j][0][kt + 1], p + x.second);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    int ans = inf;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int h = 0; h < 2; h++) {
                chkmin(ans, dp[i][j][h][k]);
            }
        }
    }
    if (ans == inf) {
        writeInt(-1, '\n');
        return 0;
    }
    writeInt(ans, '\n');
	return 0;
}