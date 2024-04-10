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


#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
const int MAXN = 400228;
const int Mod = 1000000007;


int f, w, h;
int fact[MAXN];
int antiFact[MAXN];


long long powm(long long a, long long b) {
    if (b == 0) {
        return 1;
    }
    long long g = powm(a, b >> 1);
    g = (g * g) % Mod;
    if (b & 1) {
        g = (g * a) % Mod;
    }
    return g;
}


long long getCnk(int n, int k) {
    if (k-- == 0) {
        return 1;
    }
    long long ans = fact[n + k];
    ans = (ans * antiFact[n]) % Mod;
    ans = (ans * antiFact[k]) % Mod;
    return ans;
}


int main() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % Mod;
    }
    antiFact[MAXN - 1] = powm(fact[MAXN - 1], Mod - 2);
    for (int i = MAXN - 2; i >= 0; i--) {
        antiFact[i] = (1LL * antiFact[i + 1] * (i + 1)) % Mod;
    }
    cin >> f >> w >> h;
    h++;
    long long p = 0, q = 0;
    for (int i = 0; i <= f; i++) {
        for (int j = max(0, i - 1); j <= min(w, i + 1); j++) {
            if ((i == 0) != (f == 0)) {
                continue;
            }
            if ((j == 0) != (w == 0)) {
                continue;
            }
            int r = (j == i) ? 2LL: 1LL;
            r = (r * getCnk(f - i, i)) % Mod;
            long long cntq = getCnk(w - j, j), cntp = 0;
            if (1LL * j * h <= w) {
                cntp = getCnk(w - h * j, j);
            }
            p = (p + cntp * r) % Mod;
            q = (q + cntq * r) % Mod;
        }
    }
    cout << (p * powm(q, Mod - 2)) % Mod << endl;
    return 0;
}