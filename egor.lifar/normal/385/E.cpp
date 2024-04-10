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


struct matrix
{
    int a[6][6];
};


int n;


matrix operator *(matrix m1, matrix m2) {
    matrix m3;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            m3.a[i][j] = 0;
            for (int k = 0; k < 6; k++) {
                m3.a[i][j] = (m3.a[i][j] + (1LL * m1.a[i][k] * m2.a[k][j])) % n;
            }
        }
    }
    return m3;
}


matrix base;
matrix e;



matrix powm(matrix a, long long k) {
    if (k == 0) {
        return e;
    }
    if (k == 1LL) {
        return a;
    } else {
        if (k & 1LL) {
            return powm(a, k - 1LL) * a;
        } else {
            matrix b = powm(a, k >> 1LL);
            return b * b;
        }
    }
}



int main() {
    base.a[0][0] = 2;
    base.a[0][1] = 1;
    base.a[0][2] = 1;
    base.a[0][3] = 0;
    base.a[0][4] = 1;
    base.a[0][5] = 2;
    base.a[1][0] = 1;
    base.a[1][1] = 2;
    base.a[1][2] = 0;
    base.a[1][3] = 1;
    base.a[1][4] = 1;
    base.a[1][5] = 2;
    base.a[2][0] = 1;
    base.a[2][1] = 1;
    base.a[2][2] = 1;
    base.a[2][3] = 0;
    base.a[2][4] = 1;
    base.a[2][5] = 2;
    base.a[3][0] = 1;
    base.a[3][1] = 1;
    base.a[3][2] = 0;
    base.a[3][3] = 1;
    base.a[3][4] = 1;
    base.a[3][5] = 2;
    base.a[4][0] = 0;
    base.a[4][1] = 0;
    base.a[4][2] = 0;
    base.a[4][3] = 0;
    base.a[4][4] = 1;
    base.a[4][5] = 1;
    base.a[5][0] = 0;
    base.a[5][1] = 0;
    base.a[5][2] = 0;
    base.a[5][3] = 0;
    base.a[5][4] = 0;
    base.a[5][5] = 1;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (i == j) {
                e.a[i][j] = 1;
            } else {
                e.a[i][j] = 0; 
            }
        }
    }
    cin >> n;
    int sx, sy;
    cin >> sx >> sy;
     sx--;
     sy--;
    //sx %= n;
    //sy %= n;
    int dx, dy;
    cin >> dx >> dy;
    dx = (dx % n + n) % n;
    dy = (dy % n + n) % n;
    long long t;
    cin >> t;
    matrix a = powm(base, t);
    t %= n; 
    matrix b;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            b.a[i][j] = 0;
        }
    }
    b.a[0][0] = sx;
    b.a[1][0] = sy;
    b.a[2][0] = dx;
    b.a[3][0] = dy;
    b.a[4][0] = 0;
    b.a[5][0] = 1;
    a = a * b;
    cout << a.a[0][0] + 1 << ' ' << a.a[1][0] + 1 << endl;
    return 0;
}