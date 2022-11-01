// July 13, 2018


#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG)

	int n;
	cin >> n;
	vector<int> a(n); // val, ind
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		a[i] = val;
		m[val]++;
	}
	int maxcnt = -1;
	for (auto i : m) {
		maxcnt = max(maxcnt, i.second);
	}
	sort(a.begin(), a.end());
	auto orig = a;
	rotate(a.begin(), a.begin() + maxcnt, a.end());

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > orig[i]) {
			ans++;
		}
	}

	cout << ans << '\n';




	return 0;
}