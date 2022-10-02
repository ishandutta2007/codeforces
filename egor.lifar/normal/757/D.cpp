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
#define rank rank228
#define left left228
#define right right228  
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
const int Mod = 1000000007;

int n;
string s;
int dp[77][1048576];
int who[76][76];
int prev[76];


int main(){
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            if (s[i - 1] == '1') {
                prev[i] = i - 1;
            } else {
                prev[i] = prev[i - 1];
            }
        } else {
            prev[i] = -1;
        }
        for (int j = i; j < n; j++) {
            int f = 0;
            for (int k = i; k <= j; k++) {
                f *= 2;
                f += s[k] - '0';
                if (f >= 21) {
                    break;
                }
            }
            who[i][j] = f - 1;
        }
    }
    int sum = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = i - 1; j >= max(0, i - 75); j--) {
            if (who[j][i - 1] >= 20) {
                break;
            }
            if (who[j][i - 1] == -1) {
                continue;
            }
            int sf = 1 << who[j][i - 1];
            dp[i][sf]++;
            if (dp[i][sf] >= Mod) {
                dp[i][sf] -= Mod;
            }
            for (int t = 0; t < (1 << 20); t++) {
                if (t & sf) {
                    dp[i][t] += dp[j][t ^ sf];
                    while (dp[i][t] >= Mod) {
                        dp[i][t] -= Mod;
                    }
                    dp[i][t] += dp[j][t];
                    while (dp[i][t] >= Mod) {
                        dp[i][t] -= Mod;
                    }
                }
            }
        }
        if (i > 75) {
            int t = prev[i - 7];
            if (t != -1) {
                for (int j = t; j < min(t + 7, i - 7); j++) {
                    if (who[j][i - 1] >= 20) {
                        continue;
                    }
                    if (who[j][i - 1] == -1) {
                        continue;
                    }
                    int sf = 1 << who[j][i - 1];
                    dp[i][sf]++;
                    while (dp[i][sf] >= Mod) {
                        dp[i][sf] -= Mod;
                    }
                    for (int t = 0; t < (1 << 20); t++) {
                        if (t & sf) {
                            dp[i][t] += dp[j][t ^ sf];
                            while (dp[i][t] >= Mod) {
                                dp[i][t] -= Mod;
                            }
                            dp[i][t] += dp[j][t];
                            while (dp[i][t] >= Mod) {
                                dp[i][t] -= Mod;
                            }
                        }
                    }
                } 
            }
        }
        for (int t = 0; t < (1 << 20); t++) {
            if (prev[i] == -1 && s[i] == '0') {
                dp[i][t] = 0;
            }
        }
        for (int t = 2; t <= (1 << 20); t *= 2) {
            sum += dp[i][t - 1];
            while (sum >= Mod) {
                sum -= Mod;
            }
        }
    }
    printf("%d\n", sum);
    return 0;
}