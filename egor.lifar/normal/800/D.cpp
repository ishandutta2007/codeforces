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
  
using namespace std;


#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define next next228
#define rank rank228
#define prev prev228
const int MAXN = 1000228;
const int u = 1000000;
const int t[6] = {1, 10, 100, 1000, 10000, 100000};
const int Mod = 1000000007; 


int n; 
long long a[MAXN], s[MAXN], e[MAXN];
long long ans;


int main() {
	n = readInt();
	for (int i = 0; i < u; i++) {
		a[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		long long x = readInt();
		e[x] = (2 * e[x] + x * x % Mod * a[x] + 2 * x * s[x]) % Mod;
		s[x] = (2 * s[x] + a[x] * x) % Mod;
		a[x] = (2 * a[x]) % Mod;
	}
	for (int i = 5; i >= 0; i--) {
		for (int j = u - 1; j >= 0; j--) {
			if ((j / t[i]) % 10 != 9) {
				e[j] = (e[j] * a[j + t[i]] + e[j + t[i]] * a[j] + 2 * s[j] * s[j + t[i]]) % Mod;
				s[j] = (s[j] * a[j + t[i]] + s[j + t[i]] * a[j]) % Mod;
				a[j] = (a[j] * a[j + t[i]]) % Mod;
			}
		}
	}
	for (int i = 5; i >= 0; i--) {
		for (int j = 0; j < u; j++) {
			if ((j / t[i]) % 10 != 9) {
				e[j] = (e[j] + Mod - e[j + t[i]]) % Mod;
			}
		}
	}
	for (int i = 0; i < u; i++) {
		ans ^= e[i] * i;
	}
	cout << ans << '\n';
	return 0;
}