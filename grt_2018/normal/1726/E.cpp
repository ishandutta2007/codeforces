//GRT_2018
#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 300 * 1000 + 10, mod = 998244353;
int t, n;
int dp[nax];
int f[nax], inv[nax];

int fastpow(int a, int b) {
	int w = 1;
	while(b > 0) {
		if(b & 1) w = ((ll)w * a) % mod;
		b >>= 1;
		a = ((ll)a * a) % mod;
	}
	return w;
}

int C(int x, int y) {
	return (((ll)((ll)f[x] * inv[y]) % mod) * inv[x - y]) % mod;
}

void solve() {
	cin >> n;
	dp[0] = dp[1] = 1;
	for(int i = 2; i <= n; ++i) {
		dp[i] = (dp[i - 1] + (ll)dp[i - 2] * (i - 1)) % mod;
	}
	f[0] = inv[0] = 1;
	for(int i = 1; i <= n; ++i) {
		f[i] = ((ll)f[i - 1] * i) % mod;
		inv[i] = fastpow(f[i], mod - 2);
	}
	int ans = 0;
	for(int two = 0; two * 2 <= n; two += 2) {
		int ones = n - 2 * two;
		int mul = ((ll)C(ones + two, two) * dp[ones]) % mod;
		int w = ((ll)f[two] * inv[two / 2]) % mod;
		mul = ((ll)mul * w) % mod;
		ans = (ans + mul) % mod;
	}
	cout << ans << "\n";

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		solve();
	}
}