#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int N = 1e5 + 10, mod = 998244353;
int n, a[N];
i64 s[N];
int fac[N], inv[N], invfac[N];
void init() {
	fac[0] = inv[1] = invfac[0] = 1;
	for(int i = 1; i < N; i ++) fac[i] = 1ll * fac[i - 1] * i % mod;
	for(int i = 2; i < N; i ++) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	for(int i = 1; i < N; i ++) invfac[i] = 1ll * invfac[i - 1] * inv[i] % mod;
}
int c(int n, int m) {
	return 1ll * fac[n] * invfac[m] % mod * invfac[n - m] % mod;
}
int main() {	
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	init();
	for(cin >> T; T; T --) {
		cin >> n;
		map<i64, int> mp;
		for(int i = 1; i <= n; i ++) cin >> a[i], s[i] = s[i - 1] + a[i];
		int ans = 1;
		for(int i = 1; i <= n; i ++) mp[s[i]] ++;
		for(auto [x, y] : mp) {
			if(mp.count(s[n] - x) && x * 2 < s[n]) {
				int a = y, b = mp[s[n] - x] - (x == 0), ret = 0;
				for(int k = 0; k <= min(a, b); k ++) {
					ret = (ret + 1ll * c(a, k) * c(b, k)) % mod;
				}
				ans = 1ll * ans * ret % mod;
			}
		}
		if(s[n] % 2 == 0 && mp.count(s[n] / 2)) {
			int a = mp[s[n] / 2] - (s[n] == 0), ret = 1;
			for(int i = 1; i <= a; i ++) ret = 1ll * ret * 2 % mod;
			ans = 1ll * ans * ret % mod;
		}
		cout << ans << '\n';
	}
	return 0;
}