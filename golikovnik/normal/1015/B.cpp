#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

using namespace std;

void no() {
	puts("-1");
	exit(0);
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10); cout << fixed;
	int n; cin >> n;
	string s, t;
	cin >> s >> t;
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		if (s[i] == t[i]) continue;
		int j = i + 1;
		for (; s[j] != t[i] && j < n; ++j) {}
		if (j == n) no();
		for (int k = j - 1; k >= i; --k) {
			ans.push_back(k + 1);
			swap(s[k], s[k + 1]);
		}
	}
	cout << szof(ans) << "\n";
	for (int i = 0; i < szof(ans); ++i) {
		if (i) cout << " ";
		cout << ans[i];
	}
	return 0;	
}