#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

void ADD(int &x, int y) {
	 x += y;
	 if (x >= mod) x -= mod;
}

void SUB(int &x, int y) {
	x -= y;
	if (x < 0) x += mod;
}

long long power(long long a, int b) {
	long long ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod, b >>= 1;
	}
	return ans;
}

namespace PolyOp {
	const int G = 3;
	int num[1 << 18], t1[1 << 18], t2[1 << 18], lstN;
	long long W[1 << 18 | 10], invN;
	void PreCalcNTT(int N) {
		if (lstN == N) return ; lstN = N, invN = power(N, mod - 2);
		for (int i = 0; i < N; i++) {
			num[i] = num[i >> 1] >> 1 | (i & 1 ? N >> 1 : 0);
		}
		W[0] = 1, W[1] = power(G, (mod - 1) / N); for (int i = 2; i <= N; i++) W[i] = W[i - 1] * W[1] % mod;
	}
	void NTT(int *f, int N, int flag) {
		PreCalcNTT(N);
		for (int i = 0; i < N; i++) {
			if (i < num[i]) swap(f[i], f[num[i]]);
		}
		for (int len = 2; len <= N; len <<= 1) {
			for (int i = 0; i < N; i += len) {
				int *fl = f + i, *fr = fl + len / 2, step = flag ? -N / len : N / len;
				long long *w = flag ? W + N : W;
				for (int j = 0; j < len / 2; j++) {
					int tmp = *fr * *w % mod;
					SUB(*fr = *fl, tmp), ADD(*fl, tmp);
					fl++, fr++, w += step;
				}
			}
		}
		if (flag) {
			for (int i = 0; i < N; i++) {
				f[i] = f[i] * invN % mod;
			}
		}
	}
	void polymul(int *f, int n, int *g, int m, int *h) {
		if (n + m - 1 <= 256) {
			static int mem[300];
			for (int i = 0; i < n + m - 1; i++) {
				unsigned long long tmp = 0; int cnt = 0;
				for (int x = 0; x < n; x++) {
					int y = i - x;
					if (y >= 0 && y < m) {
						tmp += 1ll * f[x] * g[y], cnt++;
						if (!(cnt & 7)) tmp %= mod;
					}
				}
				mem[i] = tmp % mod;
			}
			for (int i = 0; i < n + m - 1; i++) {
				h[i] = mem[i];
			}
			return ;
		}
		int N = 1; while (N < n + m - 1) N <<= 1;
		for (int i = 0; i < N; i++) {
			t1[i] = i < n ? f[i] : 0, t2[i] = i < m ? g[i] : 0;
		}
		NTT(t1, N, 0), NTT(t2, N, 0);
		for (int i = 0; i < N; i++) {
			t1[i] = 1ll * t1[i] * t2[i] % mod;
		}
		NTT(t1, N, 1);
		for (int i = 0; i < n + m - 1; i++) {
			h[i] = t1[i];
		}
	}
	void polyinv(int *f, int n, int *g) {
		if (n == 1) {g[0] = power(f[0], mod - 2); return ;}
		int N = n + 1 >> 1; polyinv(f, N, g);
		static int tmp[1 << 18];
		polymul(g, N, g, N, tmp);
		polymul(f, n, tmp, N + N - 1, tmp);
		for (int i = 0; i < n; i++) {
			g[i] = ((i < N ? 2ll * g[i] : 0ll) - tmp[i] + mod) % mod;
		}
	}
	void polydiv(int *f, int n, int *g, int m, int *h) {
		static int ff[1 << 18], gg[1 << 18];
		for (int i = 0; i < n; i++) {
			ff[i] = f[n - i - 1], gg[i] = i < m ? g[m - i - 1] : 0;
		}
		static int tmp[1 << 18];
		polyinv(gg, n - m + 1, tmp), polymul(tmp, n - m + 1, ff, n - m + 1, ff);
		for (int i = 0; i < n - m + 1; i++) {
			h[i] = ff[n - m - i];
		}
	}
	void polymod(int *f, int n, int *g, int m, int *h) {
		if (n < m) {
			for (int i = 0; i < n; i++) {
				h[i] = f[i];
			}
			return ;
		}
		static int tmp[1 << 18];
		polydiv(f, n, g, m, tmp);
		polymul(tmp, n - m + 1, g, m, tmp);
		for (int i = 0; i < m - 1; i++) {
			SUB(h[i] = f[i], tmp[i]);
		}
	}
	int POOL[10000000], *CUR = POOL;
	int *P[1 << 18], *Q[1 << 18];
	int SolveP(int now, int l, int r, int *a) {
		P[now] = CUR, CUR += r - l + 2, Q[now] = CUR, CUR += r - l + 1;
		if (l == r) {
			P[now][0] = a[l] ? mod - a[l] : 0, P[now][1] = 1;
			return 2;
		}
		int mid = l + r >> 1;
		int ls = SolveP(now << 1, l, mid, a), rs = SolveP(now << 1 | 1, mid + 1, r, a);
		polymul(P[now << 1], ls, P[now << 1 | 1], rs, P[now]);
		return ls + rs - 1;
	}
	void SolveQ(int now, int l, int r, int *b) {
		if (l == r) {
			b[l] = Q[now][0];
			return ;
		}
		int mid = l + r >> 1;
		polymod(Q[now], r - l + 1, P[now << 1], mid - l + 2, Q[now << 1]);
		polymod(Q[now], r - l + 1, P[now << 1 | 1], r - mid + 1, Q[now << 1 | 1]);
		SolveQ(now << 1, l, mid, b), SolveQ(now << 1 | 1, mid + 1, r, b);
	}
	void polyeva(int *f, int n, int *a, int m, int *b) {
		int N = SolveP(1, 0, m - 1, a);
		polymod(f, n, P[1], N, Q[1]);
		SolveQ(1, 0, m - 1, b);
	}
}

long long fac[100010], inv[100010];

void GetSti(int n, int *sti) {
	static int t1[100010], t2[100010], t3[1 << 18];
	for (int i = 0; i <= n; i++) {
		t1[i] = power(i, n) * inv[i] % mod;
		t2[i] = i & 1 ? mod - inv[i] : inv[i];
	}
	PolyOp :: polymul(t1, n + 1, t2, n + 1, t3);
	for (int i = 0; i <= n; i++) {
		sti[i] = t3[i];
	}
}

int main() {
	fac[0] = 1; for (int i = 1; i <= 100005; i++) fac[i] = fac[i - 1] * i % mod;
	inv[100005] = power(fac[100005], mod - 2); for (int i = 100004; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
	int n, k, p; scanf("%d%d%d", &n, &k, &p);
	int q = 1 - p + mod, invq = power(q, mod - 2), invp = power(p, mod - 2);
	static int a[100010], f[100010];
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]), a[i]++;
	}
	static int sti[100010]; GetSti(k, sti);
	{ // CalcF
		static int coef[100010];
		for (int i = k; i >= 0; i--) {
			coef[i] = i < k ? 1ll * coef[i + 1] * (i + 1) % mod * p % mod * invq % mod : 0;
			SUB(coef[i], 1ll * sti[i] * invq % mod);
		}
		coef[0] = mod - coef[0];
		static int P[200010], Q[200010];
		function <int(int, int)> Solve;
		Solve = [&](int l, int r) -> int {
			if (l == r) {
				P[l * 2] = mod - l + 1, P[l * 2 + 1] = 1;
				Q[l * 2] = 1ll * (mod - l + 1) * coef[l] % mod, Q[l * 2 + 1] = coef[l];
				return 2;
			}
			int mid = l + r >> 1;
			int ls = Solve(l, mid), rs = Solve(mid + 1, r);
			static int PP[200010], QQ[200010];
			PolyOp :: polymul(P + l * 2, ls, P + (mid + 1) * 2, rs, PP);
			PolyOp :: polymul(P + l * 2, ls, Q + (mid + 1) * 2, rs, QQ);
			for (int i = 0; i < ls + rs - 1; i++) {
				if (i < ls) ADD(Q[l * 2 + i], QQ[i]);
				else Q[l * 2 + i] = QQ[i];
				P[l * 2 + i] = PP[i];
			}
			return ls + rs - 1;
		};
		int N = Solve(1, k);
		PolyOp :: polyeva(Q + 2, N, a + 1, n, f + 1);
		for (int i = 1; i <= n; i++) {
			f[i] = (f[i] * power(p, a[i]) + 1ll * coef[0] * (1 - power(p, a[i]) + mod)) % mod;
		}
	}
	static int pre[100010][3], suc[100010][3];
	pre[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		pre[i][0] = pre[i - 1][0];
		pre[i][1] = 1ll * (pre[i - 1][0] + pre[i - 1][1]) * a[i] % mod;
		pre[i][2] = (1ll * pre[i - 1][2] * a[i] + 1ll * (pre[i - 1][0] + pre[i - 1][1]) * (a[i] - 1)) % mod;
	}
	suc[n + 1][0] = 1;
	for (int i = n; i >= 1; i--) {
		suc[i][0] = suc[i + 1][0];
		suc[i][1] = 1ll * (suc[i + 1][0] + suc[i + 1][1]) * a[i] % mod;
		suc[i][2] = (1ll * suc[i + 1][2] * a[i] + 1ll * (suc[i + 1][0] + suc[i + 1][1]) * (a[i] - 1)) % mod;
	}
	static int g[100010];
	for (int i = 1; i <= n; i++) {
		g[i] = 0;
		ADD(g[i], 1ll * (pre[i - 1][1] + pre[i - 1][0]) * suc[i + 1][2] % mod);
		ADD(g[i], 1ll * pre[i - 1][2] * (suc[i + 1][0] + suc[i + 1][1]) % mod);
		ADD(g[i], 1ll * (pre[i - 1][1] + pre[i - 1][0]) * (suc[i + 1][0] + suc[i + 1][1]) % mod);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ADD(ans, 1ll * f[i] * g[i] % mod);
	}
	printf("%d\n", ans);
	return 0;
}