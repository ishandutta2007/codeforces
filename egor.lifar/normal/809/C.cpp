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
#define y1 y1228
#define y2 y2228
const int Mod = 1000000007;


int t;


int calc(int x, int y, int k, int add) {
    if (x > y) {
        swap(x, y);
    }
    if (!x) {
        return 0;
    }
    if (k <= 0) {
        return 0;
    }
    int z = 1 << (31 - __builtin_clz(y));
    int ans = 0;
    int kk = min(k, z);
    if (x < z) {
        ans = ((1LL * (kk + 1) * kk / 2 % Mod) * x) % Mod + (((1LL * kk * x) % Mod * add) % Mod);
        ans = (ans % Mod + calc(x, y - z, k - z, z + add)) % Mod;
    } else {
        ans = (((1LL * (kk + 1) * kk / 2 % Mod) * z) % Mod + ((1LL * kk * z) % Mod * add)) % Mod + calc(x - z, y - z, k, add);
        ans = (1LL * ans + 1LL * (calc(z, y - z, k - z, z + add) + calc(z, x - z, k - z, z + add))) % Mod;
    }
    return ans;
}


int x, y, x1, y1, k;


int main() {
    t = readInt();
    for (int it = 0; it < t; it++) {
        x = readInt(), y = readInt(), x1 = readInt(), y1 = readInt(), k = readInt();
        x --, y--;
        int ans = calc(x1, y1, k, 0) + calc(x, y, k, 0) - calc(x, y1, k, 0) - calc(x1, y, k, 0);
        ans = (1LL * ans + Mod * 2) % Mod;
        writeInt(ans, '\n');
    }
    return 0;
}