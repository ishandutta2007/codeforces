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
 
 
#define hash hash228 
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define next next1
const int MAXN = 100001;


int n;
int a[MAXN];
vector<int> v[MAXN];
bool w[MAXN];
int dp[MAXN][2];
long long ans = 0;
long long sum = 0;


void dfs(int u, int pr = -1) {
    dp[u][w[u]] = 1;
    if (w[u]) {
        sum++;
    }
    for (auto h: v[u]) {
        if (h != pr) {
            dfs(h, u);
            for (int i = 0; i < 2; i++) {
                sum += 1LL * dp[u][i] * dp[h][i ^ 1];
            }
            for (int i = 0; i < 2; i++) {
                dp[u][i ^ w[u]] += dp[h][i];
            }
        }
    }
}   


int main() {
    n = readInt();
    for (int i = 0; i < n; i++) {
        a[i] = readInt();
    }
    for (int i = 0; i < n - 1; i++) {
        int a = readInt(), b = readInt();
        a--, b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < n; j++) {
            w[j] = a[j] & (1 << i);
            dp[j][0] = 0;
            dp[j][1] = 0;
        }
        sum = 0;
        dfs(0);
        ans += sum * (1LL << i);
    }
    cout << ans << endl;
    return 0;
}