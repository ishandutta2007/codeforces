#include <bits/stdc++.h>
using namespace std;

const double pi = 3.1415926535897932384626433832795;

// typedef pair <double, double> Complex;

struct Complex {
	double fi, se;
	Complex() {fi = se = 0;}
	Complex(double x, double y) {fi = x, se = y;}
};

Complex operator + (Complex a, Complex b) {return Complex(a.fi + b.fi, a.se + b.se);}

Complex operator * (Complex a, Complex b) {return Complex(a.fi * b.fi - a.se * b.se, a.fi * b.se + a.se * b.fi);}

Complex operator - (Complex a, Complex b) {return Complex(a.fi - b.fi, a.se - b.se);}

Complex operator / (Complex a, double b) {return Complex(a.fi / b, a.se / b);}

Complex Conj(Complex a) {return Complex(a.fi, -a.se);}

const int MAXN = 1 << 15;

template <typename T>
void chmin(T &x, T y) {
	x = min(x, y);
}

int n, m, t, x;
int C[110], A[110], B[110];
double W[110][20010], RW[110][20010];
double S[110][20010];
vector <int> G[60];
int dist[60];
double dp[60][20010];
double trans[110][20010];

namespace PolyOp {
	Complex t1[MAXN], t2[MAXN];
	Complex W[MAXN | 10];
	int num[MAXN], LSTN;
	void PreCalc() {
		for (int i = 0; i <= MAXN; i++) {
			W[i] = Complex(cos(2 * pi / MAXN * i), sin(2 * pi / MAXN * i));
		}
	}
	void PreCalcFFT(int N) {
		if (LSTN == N) return ;
		LSTN = N;
		for (int i = 0; i < N; i++) {
			num[i] = num[i >> 1] >> 1 | (i & 1 ? N >> 1 : 0);
		}
	}
	void Copy(Complex *t, int N, double *f, int n) {
		for (int i = 0; i < N; i++) {
			t[i] = Complex(i < n ? f[i] : 0, 0);
		}
	}
	void FFT(Complex *f, int N, int flag) {
		for (int i = 0; i < N; i++) {
			if (i < num[i]) swap(f[i], f[num[i]]);
		}
		for (int len = 2; len <= N; len <<= 1) {
			for (int i = 0; i < N; i += len) {
				Complex *fl = f + i, *fr = fl + len / 2, *w = flag ? W + MAXN : W;
				int step = flag ? -MAXN / len : MAXN / len;
				for (int j = 0; j < len / 2; j++) {
					Complex tmp = *fr * *w;
					*fr = *fl - tmp, *fl = *fl + tmp;
					fl++, fr++, w += step;
				}
			}
		}
		if (flag) {
			for (int i = 0; i < N; i++) {
				f[i] = f[i] / N;
			}
		}
	}
	void polydot(Complex *f, Complex *g, int N, Complex *h) {
		for (int i = 0; i < N; i++) {
			h[i] = f[i] * g[i];
		}
	}
	void polymul(double *f, int n, double *g, int m, double *h) {
		int N = 1; while (N < n + m - 1) N <<= 1; PreCalcFFT(N);
		for (int i = 0; i < N; i++) {
			t1[i] = Complex(i < n ? f[i] : 0, 0);
			t2[i] = Complex(i < m ? g[i] : 0, 0);
		}
		FFT(t1, N, 0), FFT(t2, N, 0);
		// for (int i = 0; i < N; i++) {
		// 	t2[i] = Conj(t1[i ? N - i : 0]);
		// }
		// for (int i = 0; i < N; i++) {
		// 	Complex X = t1[i], Y = t2[i];
		// 	t1[i] = (X + Y) / 2, t2[i] = (X - Y) / 2;
		// 	swap(t2[i].fi, t2[i].se), t2[i].se *= -1;
		// }
		for (int i = 0; i < N; i++) {
			t1[i] = t1[i] * t2[i];
		}
		FFT(t1, N, 1);
		for (int i = 0; i < n + m - 1; i++) {
			h[i] = t1[i].fi;
		}
	}
}

using PolyOp :: polymul;
using PolyOp :: PreCalcFFT;
using PolyOp :: FFT;
using PolyOp :: Copy;
using PolyOp :: polydot;

Complex tdp[60][MAXN], tmp[MAXN];

void Work(int l, int r, int L, int R) {
	int N = 1; while (N < R - L + R - l) N <<= 1; PreCalcFFT(N);
	for (int x = 1; x <= n; x++) {
		Copy(tdp[x], N, dp[x] + L, R - L + 1), FFT(tdp[x], N, 0);
	}
	for (int x = 1; x <= n; x++) {
		for (auto e : G[x]) {
			int y = B[e], c = C[e];
			Copy(tmp, N, RW[e] + t - R + l, R - l), FFT(tmp, N, 0);
			polydot(tmp, tdp[y], N, tmp);
			FFT(tmp, N, 1);
			for (int i = l; i <= r; i++) {
				trans[e][i] += tmp[R - l - (r - i) - 1].fi;
				trans[e][i] += c * (S[e][R - i] - S[e][L - i - 1]);
			}
		}
	}
}

void Solve(int l, int r) {
	if (l == r) {
		for (int x = 1; x <= n; x++) {
			dp[x][l] = 1e18;
			for (auto e : G[x]) {
				int y = B[e], c = C[e];
				trans[e][l] += (dist[y] + c) * (S[e][t] - S[e][t - l]);
				chmin(dp[x][l], trans[e][l]);
			}
			if (x == n) dp[x][l] = 0;
		}
		return ;
	}
	int mid = l + r >> 1;
	Solve(mid + 1, r), Work(l, mid, mid + 1, r), Solve(l, mid);
}

int main() {
	PolyOp :: PreCalc();
	scanf("%d%d%d%d", &n, &m, &t, &x);
	for (int i = 0; i < m; i++) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		A[i] = a, B[i] = b, C[i] = c;
		G[a].push_back(i);
		for (int j = 1; j <= t; j++) {
			int x; scanf("%d", &x);
			W[i][j] = RW[i][t - j] = x / 100000.0;
			S[i][j] = S[i][j - 1] + W[i][j];
		}
	}
	memset(dist, 0x3f, sizeof(dist)), dist[n] = x;
	for (int it = 0; it < n + 10; it++) for (int i = 0; i < m; i++) {
		chmin(dist[A[i]], dist[B[i]] + C[i]);
	}
	Solve(0, t);
	printf("%.10f\n", dp[1][0]);
	return 0;
}