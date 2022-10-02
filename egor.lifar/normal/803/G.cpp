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
#define mid ((L + R) >> 1)
const int INF = 2000000000;
const int MAXN = 100228;


int b[MAXN << 1], ans[MAXN << 1][20];


int calc(int st, int ed) {
	int u = 31 - __builtin_clz(ed - st + 1);
	return min(ans[st][u], ans[ed - (1 << u) + 1][u]);
}


int mod[MAXN * 50], mx[MAXN * 50], ls[MAXN * 50], rs[MAXN * 50];
int used, k, n;



int calc1(int st, int ed) {
	if (ed - st + 1 >= n) {
		return calc(0, n - 1);
	}
	return calc(st % n, st % n + (ed - st));
}


inline void push_up(int u) {
	mx[u] = min(mx[ls[u]], mx[rs[u]]);
}


inline void push_down(int u) {
	if (mod[u]) {
		mod[ls[u]] = mod[rs[u]] = mod[u];
		mx[ls[u]] = mx[rs[u]] = mod[u];
	}
	mod[u] = 0;
}


void update(int u, int L, int R, int l, int r, int x) {
	if (L >= r || R <= l) {
		return;
	}
	if (l <= L && R <= r) {
		mod[u] = x, mx[u] = x;
		return;
	}
	if (!ls[u]) {
		ls[u] = ++used;
		mx[ls[u]] = calc1(L, mid - 1);
	}
	if (!rs[u]) {
		rs[u] = ++used;
		mx[rs[u]] = calc1(mid, R - 1);
	}
	push_down(u);
	update(ls[u], L, mid, l, r, x);
	update(rs[u], mid, R, l, r, x);
	push_up(u);
}


int calc(int u, int L, int R, int l, int r) {
	if (L >= r || R <= l) {
		return INF;
	}
	if (l <= L && R <= r) {
		return mx[u];
	}
	if (!ls[u]) {
		ls[u] = ++used;
		mx[ls[u]]=calc1(L, mid - 1);
	}
	if (!rs[u]) {
		rs[u] = ++used;
		mx[rs[u]]=calc1(mid, R - 1);
	}
	push_down(u);
	return min(calc(ls[u], L, mid, l, r), calc(rs[u], mid, R, l, r));
}


int main() {
	n = readInt(), k = readInt();
	for (int i = 0; i < n; i++) {
		b[i] = readInt();
	}
	for (int i = 0; i < n; i++) {
		b[i + n] = b[i];
	}
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j + (1 << i) <= (n << 1); j++) {
			if (i == 0) {
				ans[j][i] = b[j];
			} else {
				ans[j][i] = min(ans[j][i - 1], ans[j + (1 << (i - 1))][i - 1]);
			}
		}
	}
	used = 1;
	mx[1] = calc(0, n - 1);
	int q = readInt();
	for (int it = 0; it < q; it++) {
		int t = readInt(), l = readInt(), r = readInt();
		if (t == 1) {
			int x = readInt();
			update(1, 0, n * k, l - 1, r, x);
		} else {
			writeInt(calc(1, 0, n * k, l - 1, r), '\n');
		}
	}
	return 0;
}