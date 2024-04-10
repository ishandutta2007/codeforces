#include  <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n;
	cin >> n;
	vector <int> b(n);
	for (int i = 0; i < n; ++i) cin >> b[i];
	map <int, ll> mx;
	for (int i = 0; i < n; ++i) {
	 	int cr = i - b[i];
	 	ll val = mx[cr] + b[i];
	 	mx[cr] = val;
	}
	ll ans = 0;
	for (auto p : mx) ans = max(ans, p.second);
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}	
}