#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353, G = 3, inv2 = mod + 1 >> 1;

long long power(long long a, int b) {
	long long ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod, b >>= 1;
	}
	return ans;
}

void ADD(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

void SUB(int &x, int y) {
	x -= y;
	if (x < 0) x += mod;
}

namespace PolyOp {
	int t1[1 << 18], t2[1 << 18];
	int num[1 << 18], lstN;
	long long W[1 << 18], invN;
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
					int tmp = *w * *fr % mod;
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
	int polymul(int *f, int n, int *g, int m, int *h) {
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
		return n + m - 1;
	}
}

int n, m;
int a[100010];
int S[100010], T[100010];
int coef[200010];
int lef[200010], rig[200010];
int lefsum[200010], rigsum[200010];
int f[100010], g[100010];
int tmp[200010];
vector <int> seq;

void Solve(int l, int r) {
	if (l == r) return ;
	int mid = l + r >> 1;
	Solve(l, mid), Solve(mid + 1, r);
	int len = PolyOp :: polymul(f + l, mid - l + 1, g + mid + 1, r - mid, tmp);
	for (int i = 0; i < len; i++) {
		ADD(coef[l + mid + 1 + i], tmp[i]);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n + 1; i++) {
		if (i <= n) scanf("%d", &a[i]);
		ADD(S[i] = S[i - 1], a[i]);
		ADD(T[i] = T[i - 1], 1ll * a[i] * i % mod);
	}
	int ans = 0;
	for (int i = 0; i < m; i++) {
		int x; scanf("%d", &x);
		seq.push_back(x);
	}
	m = (int)seq.size() - 1;
	for (int i = 0; i <= m; i++) {
		lef[i] = i == 0 ? 1 : lef[i - 1] * 2 % mod;
		lefsum[i] = lef[i];
		if (i > 0) ADD(lefsum[i], lefsum[i - 1]);
	}
	for (int i = m; i >= 0; i--) {
		rig[i] = i == m ? 1 : rig[i + 1] * 2 % mod;
		rigsum[i] = rig[i];
		if (i < m) ADD(rigsum[i], rigsum[i + 1]);
	}
	for (int i = 0; i <= m; i++) {
		int x = seq[i];
		if (i < m) SUB(ans, 1ll * lef[i] * rigsum[i + 1] % mod * T[x] % mod);
		if (i > 0) SUB(ans, 1ll * lefsum[i - 1] * rig[i] % mod * T[x] % mod);
		if (i < m) ADD(ans, 1ll * lef[i] * rigsum[i + 1] % mod * x % mod * S[x] % mod);
		if (i > 0) ADD(ans, 1ll * lefsum[i - 1] * rig[i] % mod * x % mod * S[x] % mod);
		ADD(ans, 1ll * lef[i] * (T[n] - T[x] + mod - 1ll * x * (S[n] - S[x]) % mod + mod) % mod);
		ADD(ans, 1ll * rig[i] * (1ll * x * S[x] % mod - T[x] + mod) % mod);
		f[x] = lef[i], g[x] = rig[i];
	}
	Solve(0, n);
	for (int i = 0; i <= n + n; i++) {
		long long coef = :: coef[i];
		ADD(ans, 2 * coef * T[i >> 1] % mod);
		SUB(ans, coef * i % mod * S[i >> 1] % mod);
	}
	ans = ans * power(power(2, m + 1) - 1, mod - 2) % mod;
	printf("%d\n", ans);
	return 0;
}