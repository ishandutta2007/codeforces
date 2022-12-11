#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;



int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	vector<vector<int>> t;
	t.pb(a);
	int ans = 0;
	ll cc = 0;
	for (int i = 31; i >= 0; --i) {
		ll cost[2] = {0, 0};
		vector<vector<int> > d;
		for (const auto& c : t) {
			vector<int> f[2];
			int c0 = 0, c1 = 0;
			for (int x : c) {
				if ((x >> i) & 1) {
					f[1].pb(x);
					++c1;
					cost[1] += c0;
				} else {
					f[0].pb(x);
					++c0;
					cost[0] += c1;
				}
			}
			if (f[0].size() > 0) d.emplace_back(std::move(f[0]));
			if (f[1].size() > 0) d.emplace_back(std::move(f[1]));
		}

		if (cost[0] > cost[1]) ans ^= 1 << i;

		cc += min(cost[0], cost[1]);

		swap(t, d);
	}
	cout << cc << ' ' << ans;
}