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
#define left left228
const int MAXN = 1001;
const int inf = 1000000000;


int n, m, k;
char p[MAXN][MAXN];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
char c[4] = {'D', 'L', 'R', 'U'};
int dp[MAXN][MAXN][2];


int main() {
    n = readInt(), m = readInt(), k = readInt();
    int stx, sty;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            p[i][j] = readChar();
            if (p[i][j] == 'X') {
                stx = i;
                sty = j;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 2; k++) {
                dp[i][j][k] = inf;
            }
        }
    }
    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(stx, sty), 0));
    dp[stx][sty][0] = 0;
    while (!q.empty()) {
        pair<pair<int, int>, int> a = q.front();
        q.pop();
        int i = a.first.first;
        int j = a.first.second;
        bool k = a.second;
        for (int g = 0; g < 4; g++) {
            int i1 = i + dx[g];
            int j1 = j + dy[g];
            if (i1 < 0 || j1 < 0 || i1 >= n || j1 >= m) {
                continue;
            } 
            if (p[i1][j1] == '*') {
                continue;
            }
            if (dp[i1][j1][k ^ 1] == inf) {
                dp[i1][j1][k ^ 1] = dp[i][j][k] + 1;
                q.push(make_pair(make_pair(i1, j1), k ^ 1));
            }
        }
    }
    string ans;
    for (int i = 0; i < k; i++) {
        for (int g = 0; g < 4; g++) {
            int i1 = stx + dx[g];
            int j1 = sty + dy[g];
            if (i1 < 0 || j1 < 0 || i1 >= n || j1 >= m) {
                continue;
            } 
            if (p[i1][j1] == '*') {
                continue;
            }
            if (dp[i1][j1][(k - i - 1) & 1] <= k - i - 1) {
                ans += c[g];
                stx = i1;
                sty = j1;
                break;
            }
        }
        if (sz(ans) < i + 1) {
            writeWord("IMPOSSIBLE");
            return 0;
        }
    }
    for (auto x: ans) {
        writeChar(x);
    }
    writeChar('\n');
    return 0;
}