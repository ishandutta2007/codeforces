// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
/*













 
*/
/*
  !










*/
/*
   _  __  U _____ u  _  __    
  |"|/ /  \| ___"|/ |"|/ /    
  | ' /    |  _|"   | ' /     
U/| . \\u  | |___ U/| . \\u   
  |_|\_\   |_____|  |_|\_\    
,-,>> \\,-.<<   >>,-,>> \\,-. 
 \.)   (_/(__) (__)\.)   (_/  
*/
/*















*/
/*






  










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
const long long INF = 1e18;


int t;


int main() {
    t = readInt();
    for (int it = 0; it < t; it++) {
        int x = readInt(), y = readInt(), p = readInt(), q = readInt();
        if (p == 0) {
            if (x == 0) {
                printf("0\n");
            } else {
                printf("-1\n");
            }
            continue;
        }
        long long kek = 1LL * x * q;
        long long ft = (kek + p - 1) / p;
        ft = max(ft, 1LL * y);
        if (ft % q != 0) {
            ft = ft + q - ft % q;
        }
        long long l = 0;
        long long r = 1000000000;
        while (l != r) {
            long long mid = (l + r) >> 1LL;
            if (((ft + mid * q) / q) * p - x <= ft + mid * q - y) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        ft += l * q;
        long long ans = INF;
        for (int its = 0; its < 10000; its++) {
            long long cnt = ft / q;
            cnt *= p;
            if (cnt - x <= ft - y && cnt >= x) {
                chkmin(ans, ft - y);
                break;
            }
            ft += q;
        }
        if (ans == INF) {
            printf("-1\n");
        } else {
            printf("%lld\n", ans);
        }
    }
    return 0;
}