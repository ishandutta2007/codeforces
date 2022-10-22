#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2010, mod = 998244353;
int n, m, s[N][N];
int fpw(int a, int b) {
	int ans = 1;
	for(; b; b >>= 1, a = 1ll * a * a % mod) if(b & 1) ans = 1ll * ans * a % mod;
	return ans;
}
int main() {
// 	freopen("in.txt", "r", stdin);
	s[1][1] = 1;
	for(int i = 2; i < N; i ++) {
		for(int j = 1; j <= i; j ++) {
			s[i][j] = (s[i - 1][j - 1] + 1ll * s[i - 1][j] * j) % mod;
		}
	}
	int T;
	for(cin >> T; T; T --) {
		int n, m, k;
		cin >> n >> m >> k;
		int res = 1, ans = 0, power = fpw(m, n), invm = fpw(m, mod - 2);
		for(int i = 1; i <= min(k, n); i ++) {
			int c = 1ll * (n - i + 1) * ((m + 1) / 2) % mod;
			res = 1ll * res * c % mod;
			power = 1ll * power * invm % mod;
			ans = (ans + 1ll * res * power % mod * s[k][i] % mod) % mod;
		}
		cout << ans << '\n';
	}
	return 0;
}