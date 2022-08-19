#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

inline ll inv(ll a, ll m = MOD) {
	if(a == 1 || a == m - 1) return a;
	return m - inv(m % a, a) * m / a;
}

const int MAXN = 2e6;

int N, K;
ll L;

int A[MAXN];
int V;
int vals[MAXN];
ll dp[MAXN];
ll ndp[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> L >> K;
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		vals[i] = A[i];
	}
	sort(vals, vals + N);
	V = int(unique(vals, vals + N) - vals);

	for(int i = 0; i < N; i++) {
		A[i] = int(lower_bound(vals, vals + V, A[i]) - vals);
	}

	dp[0] = 1;

	ll res = 0;
	for(int k = 1; k <= K && k <= ((L - 1) / N) + 1; k++) {
		for(int i = 1; i < V; i++) {
			dp[i] += dp[i - 1];
			dp[i] %= MOD;
		}
		for(int i = 0; i < N; i++) {
			ndp[A[i]] += dp[A[i]];
			ndp[A[i]] %= MOD;
			// length K
			// choose K
			res += ((L / N) + (i < L % N) - (k - 1)) % MOD * dp[A[i]];
			res %= MOD;
		}
		for(int i = 0; i < V; i++) {
			dp[i] = ndp[i];
			ndp[i] = 0;
		}
	}
	cout << res % MOD << '\n';

	return 0;
}