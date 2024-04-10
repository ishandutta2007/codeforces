#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 1000013
#define MOD 998244353
LL N;

inline LL mpow(LL a, LL b) {
	return b ? mpow((a*a)%MOD, b>>1) * (b % 2 ? a : 1) % MOD : 1;
}

inline LL minv(LL n) {
	return mpow(n, MOD - 2);
}

inline LL norm(LL n) {
	return ((n % MOD) + MOD) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	LL ans = 0;
	
	LL t = mpow(3, N * N);
	t -= mpow((mpow(3, N) - 3 + MOD) % MOD, N);
	t = norm(t);
	t = (t * 2) % MOD;
	ans += t;

	LL choose = 1;
	LL exp1 = mpow(3, N);
	LL exp2 = mpow(3, N * N);
	LL inv1 = minv(3);
	LL inv2 = minv(mpow(3, N));
	for (int k = 1; k <= N; k++) {
		t = -3;
		t *= (k % 2 ? -1 : 1);
		t = norm(t);

		choose *= (N - k + 1);
		choose %= MOD;
		choose *= minv(k);
		choose %= MOD;

		t = (t * choose) % MOD;
		exp1 = (exp1 * inv1) % MOD;
		exp2 = (exp2 * inv2) % MOD;
		t *= norm(mpow(norm(exp1 - 1), N) - exp2);
		t %= MOD;
		ans = (ans + t) % MOD;
	}

	cout << ans << endl;
	return 0;
}