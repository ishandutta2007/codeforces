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


int n, m;
string s[15];
int dp[15][2];

   
int main() {
    cin >> n >> m;
    for (int i = n - 1; i >= 0; i--) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1000000;
        dp[i][1] = 1000000;
    }
    dp[0][0] = 0;
    for (int i = 0; i < n - 1; i++) {
        chkmin(dp[i + 1][1], dp[i][0] + m + 2);
        chkmin(dp[i + 1][0], dp[i][1] + m + 2);
        int f = -1;
        for (int j = 0; j < m + 2; j++) {
            if (s[i][j] == '1') {
                f = j;
                break;
            }
        }
        int l = -1;
        for (int j = m + 1; j >= 0; j--) {
            if (s[i][j] == '1') {
                l = j;
                break;
            }
        }
        if (f == -1) {
            chkmin(dp[i + 1][0], dp[i][0] + 1);
            chkmin(dp[i + 1][1], dp[i][1] + 1);
        } else {
            chkmin(dp[i + 1][0], dp[i][0] + 1 + l * 2);
            chkmin(dp[i + 1][1], dp[i][1] + 1 + (m + 1 - f) * 2);
        }
    }
    int f = -1;
    for (int j = 0; j < m + 2; j++) {
        if (s[n - 1][j] == '1') {
            f = j;
            break;
        }
    }
    int l = -1;
    for (int j = m + 1; j >= 0; j--) {
        if (s[n - 1][j] == '1') {
            l = j;
            break;
        }
    }
    if (f == -1) {
        for (int i = n - 1; i >= 0; i--) {
            f = -1;
            for (int j = 0; j < m + 2; j++) {
                if (s[i][j] == '1') {
                    f = j;
                    break;
                }
            }
            l = -1;
            for (int j = m + 1; j >= 0; j--) {
                if (s[i][j] == '1') {
                    l = j;
                    break;
                }
            }
            if (f != -1) {
                cout << min(dp[i][0] + l, dp[i][1] + (m + 1 - f)) << endl;
                return 0;
            }
        }
        cout << 0 << endl;
        return 0;
    }
    //cout << dp[n - 1][0] << ' ' << dp[n - 1][1] << endl;
    cout << min(dp[n - 1][0] + l, dp[n - 1][1] + (m + 1 - f)) << endl;
    return 0;
}