#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 998244353;

ll numWays(vector<pair<int, int>> v) {
	sort(v.begin(), v.end());
	pair<int, int> prv(-1, -1);
	int c = 1;
	ll res = 1;
	for (auto cur : v) {
		assert(cur.first >= prv.first);
		if (cur.second < prv.second) return 0;
		if (cur != prv) prv = cur, c = 0;
		res *= ++c;
		res %= MOD;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	vector<pair<int, int>> v, a, b, c;
	for (int i = 0; i < N; i++) {
		int x, y; cin >> x >> y;
		v.emplace_back(x, y);
		a.emplace_back(x, 0);
		b.emplace_back(y, 0);
		c.emplace_back(0, 0);
	}
	ll ans = numWays(c) + numWays(v) - numWays(a) - numWays(b);
	ans %= MOD;
	if (ans < 0) ans += MOD;
	cout << ans << '\n';

	return 0;
}