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
  

#define prev prev228
#define rank rank228
#define left left228
#define right right228  
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
const int Mod = 1000000007;
const int MAXN = 1000228;
const int MAXK = 30;


inline int add(int a, int b) {
    if ((a += b) >= Mod) {
        a -= Mod;
    }
    return a;
}


inline int mul(int a, int b) {
    return ((long long)a) * b % Mod;
}



int dp[MAXN][30];
int minimalPrime[MAXN];


int main() {
    for (int j = 0; j < MAXK; j++) {
        dp[0][j] = (j > 0) + 1;
    }
    for (int i = 1; i < MAXN; i++) {
        int sum = 0;
        for (int j = 0; j < MAXK; j++) {
            sum = add(sum, dp[i - 1][j]);
            dp[i][j] = sum;
        }
    }
    memset(minimalPrime, -1, sizeof(minimalPrime));
    for (int i = 2; i < MAXN; i++) {
        if (minimalPrime[i] == -1) {
            minimalPrime[i] = i;
            for (int j = min(1LL * MAXN, 1LL * i * i); j < MAXN; j += i) {
                if (minimalPrime[j] == -1) {
                    minimalPrime[j] = i;
                }
            }
        }
    }
    int q = readInt();
    for (int i = 0; i < q; i++) {
        int r = readInt(), n = readInt();
        vector<pair<int, int> > g;
        while (n > 1) {
            int p = minimalPrime[n];
            g.emplace_back(p, 0);
            while (n % p == 0) {
                n /= p; 
                g.back().second++;
            }
        }
        int ans = 1;
        for (auto pr : g) {
            ans = mul(ans, dp[r][pr.second]);
        }
        writeInt(ans, '\n');
    }
    return 0;
}