#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int N = 1e7;
constexpr i64 inf = 1e18;
int n, q, k, f[6];
i64 val[N];
int main() {
// 	freopen("in.txt", "r", stdin);
	cin >> k;
	for(int i = 0; i < 6; i ++) cin >> f[i];
	cin >> q >> n;
	unordered_map<int, i64> mp;
	auto id = [&] (int i, int n) {
		return i * 1000000 + n;
	};
	constexpr int W[6] = {1, 11, 111, 1111, 11111, 111111};
	int ts = 0, tt = 0;
	function<i64(int, int, int)> dfs = [&] (int B, int n, int i)  {
		if(n > 9ll * k * W[i]) return -inf;
		if(B == 1) {
			if(n > (k - 1) * 9) return n % 3 == 0 ? 1ll * (n / 3) * f[i] : 3ll * (k - 1) * f[i];
			else return 1ll * (n / 3) * f[i];
		}
		if(val[id(i, n)]) return val[id(i, n)];
		i64 &ans = val[id(i, n)];
		ans = -1e18;
		for(int c = 0; n >= 0 && c <= 9 * k; c ++, n -= B) {
			if(c > (k - 1) * 9ll) ans = max(ans, 1ll * (c % 3 == 0 ? c / 3 : (k - 1) * 3) * f[i] + dfs(B / 10, n, i - 1));
			else ans = max(ans, 1ll * (c / 3) * f[i] + dfs(B / 10, n, i - 1));
		}
		return ans;
	};
	cout << dfs(1e5, n, 5) << '\n';
	cerr << 1.0 * clock() / CLOCKS_PER_SEC << '\n';
	return 0;
}