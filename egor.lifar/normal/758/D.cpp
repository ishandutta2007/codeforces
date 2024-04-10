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
  

#define left left228
#define right right228
#define prev prev228
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
const int INF = 2000000000;

int n;
string k;
int l;
bool can[62][62];
int prev[62][62];
int who[62][62];


int main() {
    cin >> n >> k;
    l = sz(k);
    for (int i = 0; i < l; i++) {
        long long cur = 0;
        for (int j = i; j < l; j++) {
            if (cur != INF) {
                cur *= 10LL;
                cur += k[j] - '0';
            }
            cur = min(cur, 1LL * n);
            who[i][j] = cur;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= l; i++) {
        for (int j = l - 1; j >= 0; j--) {
            if (i == 1) {
                if (k[j] == '0' && j != l - 1) {
                    continue;
                }
                if (who[j][l - 1] < n) {
                    can[i][j] = 1;
                    prev[i][j] = l;
                }
                continue;
            }
            for (int j1 = j; j1 < l; j1++) {
                if (who[j][j1] < n && can[i - 1][j1 + 1]) {
                    if (k[j] == '0' && j1 - j != 0) {
                        continue;
                    }
                    can[i][j] = 1;
                    prev[i][j] = j1 + 1;
                    break;
                } 
            }
        }
        if (can[i][0]) {
            int cur = 0;
            int i1 = i;
            while (cur < l) {
                int cp = 0;
                for (int t = cur; t < prev[i1][cur]; t++) {
                    cp *= 10;
                    cp += k[t] - '0';
                }
                ans *= n;
                ans += cp;
                cur = prev[i1][cur];
                i1--;
            }
            break;
        }
    }
    cout << ans << endl;
    return 0;
}