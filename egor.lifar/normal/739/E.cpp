#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


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


#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()


const int MAXN = 2001;
int n, a, b;
int dp[MAXN][MAXN];
int t[MAXN];
double pp[MAXN], qq[MAXN];


int main() {
	scanf("%d %d %d", &n, &a, &b);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &pp[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%lf", &qq[i]);
	}
	for (int i = 0; i < n; i++) {
		int A = pp[i] * 1000000;
		int B = qq[i] * 1000000;
		int C = (pp[i] + qq[i] - pp[i] * qq[i]) * 1000000;
		int k1 = min(i, a);
		int k2 = min(i, b);
		for (int j = k1; j >= 0; j--) {
			for (int k = k2; k >= 0; k--) {
				chkmax(dp[j + 1][k + 1], dp[j][k] + C);
				chkmax(dp[j + 1][k], dp[j][k] + A);
				chkmax(dp[j][k + 1], dp[j][k] + B);
			}
		}
	}
	double ans = double(dp[a][b]) / 1000000;
	printf("%.10lf\n", ans);
	return 0;
}