#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll modinv(ll a, ll m) { return a == 1 ? 1 : m - modinv(m % a, a) * m / a; }

const int MAXN = 3e5;
ll fact[MAXN];
ll ifact[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; ll MOD; cin >> N >> MOD;
	fact[0] = 1;
	for (int i = 1; i <= N; i++) fact[i] = fact[i-1] * i % MOD;
	ifact[N] = modinv(fact[N], MOD);
	for (int i = N; i >= 1; i--) ifact[i-1] = ifact[i] * i % MOD;

	ll ans = 0;
	for (int l = 1; l <= N; l++) {
		ans += fact[l] * fact[N-l] % MOD * (N-l+1) % MOD * (N-l+1) % MOD;
		ans %= MOD;
	}
	cout << ans << '\n';

	return 0;
}