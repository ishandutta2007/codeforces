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
  
struct Flusher {
    ~Flusher() {
        if (write_pos)
            fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
    }
} flusher;
  

#define prev prev228
#define left left228
#define right right228  
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
const int MAXN = 5228;
const int Mod = 1e9 + 7;


int add(int a, int b) {
    a += b;
    if (a >=  Mod) {
        a -=  Mod;
    }
    return a;
}


int del(int a, int b) {
    a -= b;
    if (a < 0) {
        a +=  Mod;
    }
    return a;
}


int mult(int a, int b) {
    return (1LL * a * b) %Mod;
}


int n;
string s;
int dp[MAXN][MAXN], prev[MAXN], c[MAXN][MAXN];


int main() {
    cin >> n;
    cin >> s;   
    for (int i = 0; i < n; i++) {
        prev[i] = -1;
        for (int j = 0; j < i; j++) {
            if (s[i] == s[j]) {
                prev[i] = j;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = add(c[i - 1][j - 1], c[i - 1][j]);
        }
    }   
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        int pos = prev[i];
        for(int len = 0; len <= n; len++) {
            dp[i + 1][len] = dp[i][len];
            if (len == 0) {
                continue;
            }
            if (pos == -1) {
                dp[i + 1][len] = add(dp[i + 1][len], dp[i][len - 1]);
            } else {
                dp[i + 1][len] = add(dp[i + 1][len], del(dp[i][len - 1], dp[pos + 1][len - 1]));
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = add(ans, mult(dp[n][i], c[n - 1][i - 1]));
    }
    writeInt(ans, '\n');
    return 0;
}