#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(12); cout << fixed;
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	map<int, int> res;
	for (int i = 0; i < n; ++i) {
		res[a[i]] = res[a[i] - 1] + 1;
	}
	int mx = 0;
	int num = -1;
	for (auto &entry: res) {
		if (entry.second > mx) {
			mx = entry.second;
			num = entry.first;
		}
	}
	vector<int> ans;
	int want = num;
	for (int i = n - 1; i >= 0; --i) {
		if (a[i] == want) {
			ans.push_back(i + 1);
			--want;
		}
	}
	cout << int32_t(ans.size()) << "\n";
	reverse(all(ans));
	for (int x: ans) cout << x << " ";
	cout << "\n";
	return 0;
}