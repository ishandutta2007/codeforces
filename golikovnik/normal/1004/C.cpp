#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> l, r;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		a[i] = x;
		if (l.find(x) == l.end()) {
			l[x] = i;
		} else {
			l[x] = min(l[x], i);
		}
		if (r.find(x) == r.end()) {
			r[x] = i;
		} else {
			r[x] = max(r[x], i);
		}
	}
	vector<int> right;
	for (auto &entry: r) {
		right.push_back(entry.second);
	}
	sort(all(right));
	int ans = 0;
	for (auto &entry: l) {
		int pos = entry.second;
		auto it = upper_bound(all(right), pos);
		int cur_ans = int32_t(right.size()) - (it - right.begin());
		ans += max(0ll, cur_ans);
	}
	cout << ans << "\n";
	return 0;	
}