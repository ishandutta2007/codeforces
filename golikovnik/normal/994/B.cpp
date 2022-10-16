
 #include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(12); cout << fixed;
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> p(n);
	for (int i = 0; i < n; ++i) {
		int power;
		cin >> power;
		p[i] = {power, i};
	}
	sort(all(p));
	vector<int> c(n);
	for (int &x: c) cin >> x;
	multiset<int> gold;
	for (int x: c) gold.insert(-x);
	reverse(all(p));
	vector<int> ans(n);
	for (int i = 0; i < n; ++i) {
		int his_gold = c[p[i].second];
		int res = his_gold;
		auto ptr = gold.find(-his_gold);
		gold.erase(ptr);
		int did = 0;
		for (const int &x: gold) {
                        if (did == k) break;
			res -= x;
			++did;
		}
		ans[p[i].second] = res;
	}
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << " ";
	}
	return 0;
}