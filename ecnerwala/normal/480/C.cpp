#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

const int MAXN = 6e3;
const int MAXK = 6e3;
int N, K, A, B;

ll dp[MAXN];
ll ndp[MAXN];

int main() {
	cin >> N >> A >> B >> K;
	A--, B--;
	dp[A] = 1;
	for(int t = 0; t < K; t++) {
		memset(ndp, 0, sizeof(ndp));
		for(int i = 0; i < N; i++) {
			if(i == B) continue;
			int l = 2 * i - B, r = B;
			if(l > r) swap(l, r);
			// exclusive range
			if(l < 0) l = -1;
			if(r > N) r = N;
			ndp[l + 1] += dp[i];
			ndp[l + 1] %= MOD;
			ndp[r] += MOD - dp[i];
			ndp[r] %= MOD;
		}
		ll v = 0;
		for(int i = 0; i < N; i++) {
			v += ndp[i];
			v %= MOD;
			dp[i] = (v - dp[i] + MOD) % MOD;
		}
	}
	ll v = 0;
	for(int i = 0; i < N; i++) {
		v += dp[i];
		v %= MOD;
	}
	cout << v << '\n';
	return 0;
}