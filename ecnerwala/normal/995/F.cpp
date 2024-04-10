#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = ll(1e9) + 7;

ll inv(ll a, ll m = MOD) {
	return a == 1 ? 1 : m - inv(m % a, a) * m / a;
}

const int MAXN = 4000;
int N;
const int MAXK = MAXN + 10;
int K;
int P[MAXN];
ll dp[MAXN][MAXK];

ll interp(ll x) {
	ll res = 0;
	for (int i = 0; i <= K; i++) {
		ll num = dp[0][i];
		ll den = 1;
		for (int j = 0; j <= K; j++) {
			if (i == j) continue;
			num *= (x - j);
			num %= MOD;
			if (num < 0) num += MOD;
			den *= (i - j);
			den %= MOD;
			if (den < 0) den += MOD;
		}
		res += num * inv(den);
		res %= MOD;
	}
	return res;
}

int D;

int main() {
	cin >> N >> D;
	P[0] = -1;
	for (int i = 1; i < N; i++) {
		cin >> P[i];
		P[i] --;
	}

	K = N + 1;
	for (int i = 0; i < N; i++) {
		dp[i][0] = 0;
		for (int k = 1; k <= K; k++) {
			dp[i][k] = 1;
		}
	}

	for (int i = N-1; i >= 0; i--) {
		for (int k = 1; k <= K; k++) {
			dp[i][k] += dp[i][k-1];
			if (dp[i][k] >= MOD) dp[i][k] -= MOD;
		}
		if (!i) continue;
		int p = P[i];
		assert(0 <= p && p < i);
		for (int k = 0; k <= K; k++) {
			dp[p][k] *= dp[i][k];
			dp[p][k] %= MOD;
		}
	}
	cerr << "hi\n";

	// we'll decrease K to N
	K--;
	cerr << interp(K+1) << ' ' << dp[0][K+1] << '\n';
	assert(interp(K+1) == dp[0][K+1]);
	cout << interp(D) << '\n';

	return 0;
}