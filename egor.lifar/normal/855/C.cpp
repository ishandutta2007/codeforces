/*
 






































 
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
const int MAXN = 100001;
const int Mod = 1000000007;


int n, m;
int k, x;
int dp[MAXN][11][3];
bool used[MAXN];
vector<int> g[MAXN];
int dp1[2][11];


void dfs(int u) {
    used[u] = true;
    vector<int> sons;
    for (auto h: g[u]) {
        if (!used[h]) {
            dfs(h);
            sons.push_back(h);
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int t = 0; t <= x; t++) {
            dp1[i][t] = 0;
        }
    }
    dp1[0][0] = 1;
    for (int i = 0; i < sz(sons); i++) {
        for (int t = 0; t <= x; t++) {
            if (!dp1[0][t]) {
                continue;
            }
            for (int t1 = 0; t1 <= x - t; t1++) {
                dp1[1][t + t1] += (1LL * dp[sons[i]][t1][0] * dp1[0][t]) % Mod;
                dp1[1][t + t1] %= Mod;
            }
        }
        for (int t = 0; t <= x; t++) {
            dp1[0][t] = dp1[1][t];
            dp1[1][t] = 0;
        }
    }
    for (int t = 0; t <= x - 1; t++) {
        dp[u][t + 1][1] = dp1[0][t]; 
    }
    for (int i = 0; i < 2; i++) {
        for (int t = 0; t <= x; t++) {
            dp1[i][t] = 0;
        }
    }
    dp1[0][0] = 1;
    for (int i = 0; i < sz(sons); i++) {
        //cout << dp[sons[i]][0][2] <<< endl;
        for (int t = 0; t <= x; t++) {
            if (!dp1[0][t]) {
                continue;
            }
            for (int t1 = 0; t1 <= x - t; t1++) {
                dp1[1][t + t1] += (1LL * ((dp[sons[i]][t1][0] + dp[sons[i]][t1][2]) % Mod) * dp1[0][t]) % Mod;
                dp1[1][t + t1] %= Mod;
            }
        }
        for (int t = 0; t <= x; t++) {
            dp1[0][t] = dp1[1][t];
            dp1[1][t] = 0;
        }
    }
    for (int t = 0; t <= x; t++) {
        dp[u][t][2] = (1LL * dp1[0][t] * (m - k)) % Mod; 
    }
    for (int i = 0; i < 2; i++) {
        for (int t = 0; t <= x; t++) {
            dp1[i][t] = 0;
        }
    }
    dp1[0][0] = 1;
    for (int i = 0; i < sz(sons); i++) {
        for (int t = 0; t <= x; t++) {
            if (!dp1[0][t]) {
                continue;
            }
            for (int t1 = 0; t1 <= x - t; t1++) {
                dp1[1][t + t1] += (1LL * (((dp[sons[i]][t1][0] + dp[sons[i]][t1][1]) % Mod + dp[sons[i]][t1][2]) % Mod) * dp1[0][t]) % Mod;
                dp1[1][t + t1] %= Mod;
            }
        }
        for (int t = 0; t <= x; t++) {
            dp1[0][t] = dp1[1][t];
            dp1[1][t] = 0;
        }
    }
    for (int t = 0; t <= x; t++) {
        dp[u][t][0] = (1LL * dp1[0][t] * (k - 1)) % Mod; 
    }
}


int main() {
    n = readInt(), m = readInt();
    for (int i = 0; i < n - 1; i++) {
        int a = readInt(), b = readInt();
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    k = readInt(), x = readInt();
    dfs(0);
    int ans = 0;
    for (int i = 0; i <= x; i++) {
        ans = (ans + dp[0][i][0]) % Mod;
        ans = (ans + dp[0][i][1]) % Mod;
        ans = (ans + dp[0][i][2]) % Mod;
    }
    writeInt(ans, '\n');
    return 0;
}