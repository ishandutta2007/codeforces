// ,   !!!
//  !!!!!!!
//     !!!!
//    ,   !!!!!
//ICM ACPC
//  Y!!   !!!
#pragma GCC optimize "-oFast"
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
#define next next228
#define prev prev228
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()


long long n;

 
int bs(int a,int b){
    long long sum = 1;
    for (int i = 1; i <= b; i++) {
        sum *= a;
        if (sum >= n) {
            return 1;
        }
    }
    return 0;
}


int bs2(int b) {
    long long sum = 1;
    for (int i = 1; i <= b; i++) {
        sum *= 2;
        if (sum >= n) {
            return 1;
        }
    }
    return 0;
}

int deal(int a, int b) {
    if (bs(a, b)) {
        return 1;
    }
    if (a == 1) {
         int k = deal(a + 1, b);
        if (k == -1) {
            return 1;
        } else {
            if (bs2(b)) {
                return 0;
            } else {
                return -deal(a, b + 1);
            }
        }
    }
    if (b == 1) {
         int k = deal(a, b + 1);
        if (k == -1) {
            return 1;
        } else {
            if (a * a >= n) {
                int k = n - a;
                if (k % 2 == 0) {
                    return 1;
                } else {
                    return -1;
                }
            } else {
                return -deal(a + 1, b);
            }
        }
    }
    int k1 = deal(a, b + 1);
    int k2 = deal(a + 1, b);
    if (k1 == -1 || k2 == -1) {
       return 1;
    }
    if (k1 == 1 && k2 == 1) {
       return -1;
    }
    return 0;
}

int main(){
    int a = readInt(), b = readInt();
    n = readInt();
    int k = deal(a, b);
    if (k == 1) {
        writeWord("Masha\n");
    } else if (k == 0) {
        writeWord("Missing\n");
    } else {
        writeWord("Stas\n");
    }
    return 0;
}