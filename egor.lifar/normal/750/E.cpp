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
const int INF = 1000000000;


typedef int M[5][5];


void mutliplex(M a, M b, M &res) {
    M c;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            c[j][i] = INF;
            for (int k = 0; k < 5; k++) {
                c[j][i] = min(c[j][i], b[j][k] + a[k][i]);
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            res[i][j] = c[i][j];
        }
    }
}


const int ss = 1 << 18;


M matrix[ss * 2];


void it_get(int l, int r, M &res) {
    l += ss;
    r += ss;
    M rl, rr;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
           rl[i][j] = rr[i][j] = (i == j ? 0 : INF);
        }
    }
    while (l <= r) {
        if (l & 1) {
            mutliplex(rl, matrix[l++], rl);
        }
        if (!(r & 1)) { 
            mutliplex(matrix[r--], rr, rr);
        }
        l >>= 1, r >>= 1;
    }
    mutliplex(rl, rr, res);
}


int n, q;
char s[ss];


int main () {
    n = readInt(), q = readInt();
    for (int k = 0; k < n; k++) {
        s[k] = readChar();
        int t = s[k] - '0';
        int ind = ss + k;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                matrix[ind][i][j] = INF;
            }
        }
        if (t == 0) {
            matrix[ind][0][0] = 0;
            matrix[ind][1][1] = 1;
            matrix[ind][2][1] = 0;
            matrix[ind][2][2] = 0;
            matrix[ind][3][3] = 0;
            matrix[ind][4][4] = 0;
        } else if (t == 1) {
            matrix[ind][0][0] = 0;
            matrix[ind][1][1] = 0;
            matrix[ind][2][2] = 1;
            matrix[ind][3][2] = 0;
            matrix[ind][3][3] = 0;
            matrix[ind][4][4] = 0;
        } else if (t == 2) {
            matrix[ind][0][0] = 1;
            matrix[ind][1][0] = 0;
            matrix[ind][1][1] = 0;
            matrix[ind][2][2] = 0;
            matrix[ind][3][3] = 0;
            matrix[ind][4][4] = 0;
        } else if (t == 6) {
            matrix[ind][0][0] = 0;
            matrix[ind][1][1] = 0;
            matrix[ind][2][2] = 0;
            matrix[ind][3][3] = 1;
            matrix[ind][4][4] = 1;
        } else if (t == 7) {
            matrix[ind][0][0] = 0;
            matrix[ind][1][1] = 0;
            matrix[ind][2][2] = 0;
            matrix[ind][3][3] = 1;
            matrix[ind][4][3] = 0;
            matrix[ind][4][4] = 0;
        } else {
            matrix[ind][0][0] = 0;
            matrix[ind][1][1] = 0;
            matrix[ind][2][2] = 0;
            matrix[ind][3][3] = 0;
            matrix[ind][4][4] = 0;
        }
    }
    for (int i = (n + ss - 1) >> 1; i > 0; i--) {
        mutliplex(matrix[i << 1], matrix[(i << 1) + 1], matrix[i]);
    }
    for (int i = 0; i < q; i++) {
        int a = readInt(), b = readInt();
        a--, b--;
        M r;
        it_get(a, b, r);
        int ans = r[4][0];
        if (ans == INF) {
            ans = -1;
        }
        writeInt(ans, '\n');
    }
    return 0;
}