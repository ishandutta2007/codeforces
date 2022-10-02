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
#define get get228
#define y1 y1228                                                         
const int MAXN = 2001;


int n, m, k;
char s[MAXN][MAXN];
int a[MAXN][MAXN];
string s1[MAXN];


int main() {
    n = readInt(), m = readInt(), k = readInt();
    int cnt = 0;
    int cnt1 = 0;
    for (int i = 0; i < 2 * n - 1; i++) {
        if (i % 2 == 0) {
            cnt1 += m - 1;
            for (int j = 0; j < m - 1; j++) {
                s[i][j] = readChar();
                if (s[i][j] == 'E') {
                    cnt++;
                }
            }
        } else {
            cnt1 += m;
            for (int j = 0; j < m; j++) {
                s[i][j] = readChar();
                if (s[i][j] == 'E') {
                    cnt++;
                }
            }
        }
    }
    if (k == 1) {
        if (cnt * 4 >= 3 * cnt1) {
            writeWord("YES\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    writeInt(1, ' ');
                }
                writeChar('\n');
            }
        } else {
            writeWord("NO\n");
        }
        return 0;
    }
    if (m >= n) {
        for (int i = 0; i < n; i++) {
            a[i][0] = 1;
            for (int j = 1; j < m; j++) {
                if (s[i * 2][j - 1] == 'E') {
                    a[i][j] = a[i][j - 1]; 
                } else {
                    a[i][j] = 3 - a[i][j - 1];
                }
            }
            if (i) {
                int res = 0;
                for (int j = 0; j < m; j++) {
                    if (s[i * 2 - 1][j] == 'E') {
                        if (a[i][j] == a[i - 1][j]) {
                            res++;
                        }
                    } else {
                        if (a[i][j] != a[i - 1][j]) {
                            res++;
                        }
                    }
                }
                if (res <= m / 2) {
                    for (int j = 0; j < m; j++) {
                        a[i][j] = 3 - a[i][j];
                    }
                }
            }
        }
        writeWord("YES\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                writeInt(a[i][j], ' ');
            }
            writeChar('\n');
        }
    } else {
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < 2 * n - 1; j += 2) {
                s1[i * 2] += s[j][i];
            }   
            if (i < m - 1) {
                for (int j = 0; j < 2 * n - 1; j += 2) {
                    s1[i * 2 + 1] += s[j][i];
                }
            }   
        }
        swap(n, m);
        for (int i = 0; i < n; i++) {
            a[i][0] = 1;
            for (int j = 1; j < m; j++) {
                if (s1[i * 2][j - 1] == 'E') {
                    a[i][j] = a[i][j - 1]; 
                } else {
                    a[i][j] = 3 - a[i][j - 1];
                }
            }
            if (i) {
                int res = 0;
                for (int j = 0; j < m; j++) {
                    if (s1[i * 2 - 1][j] == 'E') {
                        if (a[i][j] == a[i - 1][j]) {
                            res++;
                        } 
                    } else {
                        if (a[i][j] != a[i - 1][j]) {
                            res++;
                        } 
                    }
                }
                if (res <= m / 2) {
                    for (int j = 0; j < m; j++) {
                        a[i][j] = 3 - a[i][j];
                    }
                }
            }
        }
        swap(n, m);
        writeWord("YES\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                writeInt(a[j][i], ' ');
            }
            writeChar('\n');
        }
    }   
    return 0;
}