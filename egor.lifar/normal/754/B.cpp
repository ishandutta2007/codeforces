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
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
const int MAXN = 200228;


string s[4];


int main() {
    for (int i = 0; i < 4; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (j + 2 < 4) {
                if (s[i][j] == 'o' || s[i][j + 1] == 'o' || s[i][j + 2] == 'o') {
                    continue;
                }
                int cnt = 0;
                if (s[i][j] == 'x') {
                    cnt++;
                }
                if (s[i][j + 1] == 'x') {
                    cnt++;
                }
                if (s[i][j + 2] == 'x') {
                    cnt++;
                }
                if (cnt >= 2) {
                    writeWord("YES\n");
                    return 0;
                }
            }
        }
        for (int j = 0; j < 4; j++) {
            if (i + 2 < 4) {
                if (s[i][j] == 'o' || s[i + 1][j] == 'o' || s[i + 2][j] == 'o') {
                    continue;
                }
                int cnt = 0;
                if (s[i][j] == 'x') {
                    cnt++;
                }
                if (s[i + 1][j] == 'x') {
                    cnt++;
                }
                if (s[i + 2][j] == 'x') {
                    cnt++;
                }
                if (cnt >= 2) {
                    writeWord("YES\n");
                    return 0;
                }
            }
        }
        for (int j = 0; j < 4; j++) {
            if (i + 2 < 4 && j + 2 < 4) {
                if (s[i][j] == 'o' || s[i + 1][j + 1] == 'o' || s[i + 2][j + 2] == 'o') {
                    continue;
                }
                int cnt = 0;
                if (s[i][j] == 'x') {
                    cnt++;
                }
                if (s[i + 1][j + 1] == 'x') {
                    cnt++;
                }
                if (s[i + 2][j + 2] == 'x') {
                    cnt++;
                }
                if (cnt >= 2) {
                    writeWord("YES\n");
                    return 0;
                }
            }
        }
        for (int j = 0; j < 4; j++) {
            if (i + 2 < 4 && j >= 2) {
                if (s[i][j] == 'o' || s[i + 1][j - 1] == 'o' || s[i + 2][j - 2] == 'o') {
                    continue;
                }
                int cnt = 0;
                if (s[i][j] == 'x') {
                    cnt++;
                }
                if (s[i + 1][j - 1] == 'x') {
                    cnt++;
                }
                if (s[i + 2][j - 2] == 'x') {
                    cnt++;
                }
                if (cnt >= 2) {
                    writeWord("YES\n");
                    return 0;
                }
            }
        }
    }
    writeWord("NO\n");
    return 0;
}