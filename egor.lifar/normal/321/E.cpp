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
   
   
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define next next228
#define rank rank228
#define prev prev228
#define y1 y1228
const int MAXN = 4001;
const int MAXK = 801;
const int INF = 1000000000;


int n, k;
int cost[MAXN][MAXN];
int c[MAXN][MAXN];
int dp[MAXK][MAXN];
int opt[MAXK][MAXN];


inline int getsum(int i, int j, int i1, int j1) {
    return c[i1][j1] - (i ? c[i - 1][j1]: 0) - (j ? c[i1][j - 1]: 0) + (i && j ? c[i - 1][j - 1]: 0);
}


inline void proceed(int i, int j, int optl, int optr) {
    dp[i][j] = INF;
    for (int f = optl; f <= min(optr, j - 1); f++) {
        if (dp[i][j] > dp[i - 1][f] + cost[f + 1][j]) {
            dp[i][j] = dp[i - 1][f] + cost[f + 1][j];
            opt[i][j] = f;
        }
    }
  //  cout << dp[i][j] << ' '  << j << ' ' << optl << ' ' << optr << ' ' << dp[0][1] + cost[2][4] << endl; 
}


inline void compute(int d, int l, int r, int optl, int optr) {
    if (l > r) {
        return;
    }
  //  cout << l << ' ' << r << ' ' << optl << ' ' << optr << endl; 
    if (l == r) {
        proceed(d, l, optl, optr);
        return;
    }
    int mid = (l + r + 1) >> 1;
    proceed(d, mid, optl, optr);
    compute(d, l, mid - 1, optl, opt[d][mid]);
    compute(d, mid + 1, r, opt[d][mid], optr);
}


int main() {
    n = readInt(), k = readInt();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = readInt();
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] += (i ? c[i - 1][j]: 0) + (j ? c[i][j - 1]: 0) - (i && j ? c[i - 1][j - 1]: 0);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cost[i][j] = getsum(i, i, j, j) / 2;
        }
    }
    for (int i = 0; i < n; i++) {
        dp[0][i] = cost[0][i];
    }
  //  cout << dp[0][1] << endl;
    for (int i = 1; i < k; i++) {
        compute(i, 0, n - 1, 0, n - 1);
    }
    writeInt(dp[k - 1][n - 1], '\n');
	return 0;
}