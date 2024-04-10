#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
	}
	array<vector<pair<int, int>>, 2> arr;
	string s;
	cin >> s;
	for (int i = 0; i < n; ++i) {
		arr[s[i] - '0'].emplace_back(p[i], i);
	}
	vector<int> ans(n);
	sort(all(arr[0]));
	sort(all(arr[1]));
	int it = 1;
	for (auto i : arr[0]) {
		ans[i.second] = it++;
		// cout << i.second + 1 << ' ';
	}
	for (auto i : arr[1]) {
		ans[i.second] = it++;
		// cout << i.second + 1 << ' ';
	}
	for (int i : ans)
		cout << i << ' ';
	cout << '\n';
}

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    SOLVE
}