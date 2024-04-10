#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<ll, ll> pii;

const ll MOD = 1e9 + 7;

const int MAXN = 1e5 + 20;

int N;
int P[MAXN];
int X[MAXN]; // black or not
vector<int> adj[MAXN];

ll dp[MAXN][2];

ll exp(ll a, ll e, ll m = MOD) {
	ll res = 1;
	while(e) {
		if(e % 2) res *= a, res %= m;
		e /= 2;
		a *= a, a %= m;
	}
	return res;
}

ll inv(ll a, ll m = MOD) {
	return exp(a, m - 2, m); // works only for primes
}

int main() {
	cin >> N;
	for(int i = 1; i < N; i++) cin >> P[i];
	for(int i = 0; i < N; i++) {
		cin >> X[i];
	}
	for(int i = 0; i < N; i++) {
		dp[i][0] = 1;
		dp[i][1] = 0;
	}

	for(int i = N - 1; i >= 0; i--) {
		if(X[i]) {
			dp[i][1] = dp[i][0];
			dp[i][0] = 0;
		}
		if(i) {
			int p = P[i];
			dp[p][1] = dp[i][0] * dp[p][1] + dp[i][1] * dp[p][1] + dp[i][1] * dp[p][0];
			dp[p][1] %= MOD;
			dp[p][0] = dp[p][0] * dp[i][0] + dp[p][0] * dp[i][1];
			dp[p][0] %= MOD;
		}
		//cerr << i << ' ' << dp[i][0] << ' ' << dp[i][1] << '\n';
	}

	cout << dp[0][1] << '\n';
	return 0;
}