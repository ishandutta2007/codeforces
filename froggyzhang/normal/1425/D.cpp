#include <bits/stdc++.h>

#define debug(...) fprintf(stderr, __VA_ARGS__)

#ifndef AT_HOME
#define getchar() IO::myGetchar()
#define putchar(x) IO::myPutchar(x)
#endif

namespace IO {
	static const int IN_BUF = 1 << 23, OUT_BUF = 1 << 23;

	inline char myGetchar() {
		static char buf[IN_BUF], *ps = buf, *pt = buf;
		if (ps == pt) {
			ps = buf, pt = buf + fread(buf, 1, IN_BUF, stdin);
		}
		return ps == pt ? EOF : *ps++;
	}

	template<typename T>
	inline bool read(T &x) {
		bool op = 0;
		char ch = getchar();
		x = 0;
		for (; !isdigit(ch) && ch != EOF; ch = getchar()) {
			op ^= (ch == '-');
		}
		if (ch == EOF) {
			return false;
		}
		for (; isdigit(ch); ch = getchar()) {
			x = x * 10 + (ch ^ '0');
		}
		if (op) {
			x = -x;
		}
		return true;
	}

	inline int readStr(char *s) {
		int n = 0;
		char ch = getchar();
		for (; isspace(ch) && ch != EOF; ch = getchar())
			;
		for (; !isspace(ch) && ch != EOF; ch = getchar()) {
			s[n++] = ch;
		}
		s[n] = '\0';
		return n;
	}

	inline void myPutchar(char x) {
		static char pbuf[OUT_BUF], *pp = pbuf;
		struct _flusher {
			~_flusher() {
				fwrite(pbuf, 1, pp - pbuf, stdout);
			}
		};
		static _flusher outputFlusher;
		if (pp == pbuf + OUT_BUF) {
			fwrite(pbuf, 1, OUT_BUF, stdout);
			pp = pbuf;
		}
		*pp++ = x;
	}

	template<typename T>
	inline void print_(T x) {
		if (x == 0) {
			putchar('0');
			return;
		}
		static int num[40];
		if (x < 0) {
			putchar('-');
			x = -x;
		}
		for (*num = 0; x; x /= 10) {
			num[++*num] = x % 10;
		}
		while (*num){
			putchar(num[*num] ^ '0');
			--*num;
		}
	}

	template<typename T>
	inline void print(T x, char ch = '\n') {
		print_(x);
		putchar(ch);
	}

	inline void printStr_(const char *s, int n = -1) {
		if (n == -1) {
			n = strlen(s);
		}
		for (int i = 0; i < n; ++i) {
			putchar(s[i]);
		}
	}

	inline void printStr(const char *s, int n = -1, char ch = '\n') {
		printStr_(s, n);
		putchar(ch);
	}
}
using namespace IO;

const int N = 2005, P = 1000000007;

int n, m, R;
int C[N][N];
int sum[N][N];

struct Node {
	int x, y, w;
} a[N];

int Query(int sx, int sy, int tx, int ty) {
	if (sx < 1) {
		sx = 1;
	}
	if (sy < 1) {
		sy = 1;
	}
	if (tx > 1000) {
		tx = 1000;
	}
	if (ty > 1000) {
		ty = 1000;
	}
	if (sx > tx || sy > ty) {
		return 0;
	}
	return sum[tx][ty] - sum[sx - 1][ty] - sum[tx][sy - 1] + sum[sx - 1][sy - 1];
}

int main() {
	read(n), read(m), read(R);
	for (int i = 1; i <= n; ++i) {
		read(a[i].x), read(a[i].y), read(a[i].w);
		++sum[a[i].x][a[i].y];
	}
	for (int i = 1; i <= 1000; ++i) {
		for (int j = 1; j <= 1000; ++j) {
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}
	for (int i = 0; i <= n; ++i) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int ix1 = a[i].x - R, iy1 = a[i].y - R, ix2 = a[i].x + R, iy2 = a[i].y + R;
			int jx1 = a[j].x - R, jy1 = a[j].y - R, jx2 = a[j].x + R, jy2 = a[j].y + R;
			int ci = Query(ix1, iy1, ix2, iy2);
			int cj = Query(jx1, jy1, jx2, jy2);
			int c = ci + cj - Query(std::max(ix1, jx1), std::max(iy1, jy1), std::min(ix2, jx2), std::min(iy2, jy2));
			int s = (C[n][m] - C[n - ci][m] - C[n - cj][m] + C[n - c][m]) % P;
			ans = (ans + 1ll * a[i].w * a[j].w % P * (s + P)) % P;
		}
	}
	print(ans);
}