#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

const int mod = 10007;

void ADD(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

void SUB(int &x, int y) {
	x -= y;
	if (x < 0) x += mod;
}

int power(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod, b >>= 1;
	}
	return ans;
}

typedef vector <int> Poly;

Poly operator + (const Poly &A, const Poly &B) {
	Poly C(max(A.size(), B.size()), 0);
	for (int i = 0; i < C.size(); i++) {
		if (i < A.size()) ADD(C[i], A[i]);
		if (i < B.size()) ADD(C[i], B[i]);
	}
	return C;
}

Poly operator * (Poly A, const int &x) {
	; for (auto &it : A) it = it * x % mod;
	return A;
}

Poly operator * (const Poly &A, const Poly &B) {
	if (!A.size() || !B.size()) return Poly({});
	Poly C(A.size() + B.size() - 1);
	; for (int i = 0; i < A.size(); i++) for (int j = 0; j < B.size(); j++) ADD(C[i + j], A[i] * B[j] % mod);
	return C;
}

pair <Poly, Poly> operator / (Poly A, const Poly &B) {
	Poly C;
	int inv = power(B.back(), mod - 2);
	while (A.size() >= B.size()) {
		C.push_back(A.back() * inv % mod), A.pop_back();
		for (int i = 1; i < B.size(); i++) {
			SUB(A[(int)A.size() - i], C.back() * B[B.size() - i - 1] % mod);
		}
	}
	return mp(C, A);
}

Poly operator ^ (Poly A, int k) {
	Poly ans = {1};
	while (k) {
		if (k & 1) ans = ans * A;
		k >>= 1;
		if (!k) break;
		A = A * A;
	}
	return ans;
}

Poly operator % (Poly A, const Poly &B) {
	while (A.size() >= B.size()) {
		int x = A.back(); A.pop_back();
		for (int i = 1; i < B.size(); i++) {
			SUB(A[(int)A.size() - i], x * B[i] % mod);
		}
	}
	return A;
}

char s[210];
int n, k;
int dp[210][210][210];
map <pii, int> coef[2];
int U, V, W, K;

int GetXk(Poly add, Poly mod, int k) {
	Poly ext;
	{
		auto tmp = add / mod;
		ext = tmp.fi, add = tmp.se;
	}
	int res = k < ext.size() ? ext[k] : 0;
	Poly f(mod.size() - 1);
	for (int i = 0; i < f.size(); i++) {
		f[i] = i < add.size() ? add[i] : 0;
		for (int j = 1; j <= i; j++) {
			SUB(f[i], mod[j] * f[i - j] % :: mod);
		}
	}
	Poly ans({1});
	Poly A({0, 1});
	while (k) {
		if (k & 1) ans = ans * A % mod;
		A = A * A % mod, k >>= 1;
	}
	for (int i = 0; i < ans.size(); i++) {
		ADD(res, ans[i] * f[i] % :: mod);
	}
	return res;
}

Poly _Solve(int p, int q, int k) {
	if (p + q > k) return {};
	k -= p + q;
	return (Poly({1, mod - 24}) ^ U - p) * (Poly({1, mod - 25}) ^ V - q) * (Poly({0, 1}) ^ K - k);
}

Poly Solve(int flag, int p, int q, int k) {
	if (!flag) {
		if (!(k & 1)) return _Solve(p, q, k >> 1);
		return _Solve(p, q, k - 1 >> 1) * 26;
	}
	if (!(k & 1)) return _Solve(p, q + 1, k >> 1);
	return _Solve(p, q + 1, k + 1 >> 1);
}

int main() {
	scanf("%s%d", s, &k), n = strlen(s);
	k += n;
	memset(dp, 0, sizeof(dp)), dp[0][n - 1][0] = 1;
	for (int l = 0; l < n; l++) {
		for (int r = n - 1; r > l; r--) {
			int lim = l + n - 1 - r >> 1;
			if (s[l] == s[r]) {
				for (int t = 0; t <= lim; t++) {
					ADD(dp[l + 1][r - 1][t + 1], dp[l][r][t]);
				}
			} else {
				for (int t = 0; t <= lim; t++) {
					ADD(dp[l + 1][r][t], dp[l][r][t]);
					ADD(dp[l][r - 1][t], dp[l][r][t]);
				}
			}
		}
	}
	for (int i = 0; i + 1 < n; i++) {
		for (int t = 0; t <= n; t++) if (dp[i + 1][i][t]) {
			int p = n - 2 * t, q = t;
			ADD(coef[0][mp(p, q)], dp[i + 1][i][t]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int t = 0; t <= n; t++) if (dp[i][i][t]) {
			int p = n - 1 - 2 * t, q = t;
			ADD(coef[1][mp(p, q)], dp[i][i][t]);
		}
	}
	U = n, V = n + 1 >> 1, W = 1, K = k + 1 >> 1;
	static vector <int> hold;
	for (int flag = 0; flag < 2; flag++) {
		for (auto it : coef[flag]) {
			hold = hold + Solve(flag, it.fi.fi, it.fi.se, k) * it.se;
		}
	}
	int ans = GetXk(hold, (Poly({1, mod - 24}) ^ U) * (Poly({1, mod - 25}) ^ V) * (Poly({1, mod - 26})), K);
	printf("%d\n", ans);
	return 0;
}