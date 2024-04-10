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
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> suffix_cnt(n + 1);
	set<int> right;
	suffix_cnt[n] = 0;
	for (int i = n - 1; i >= 0; i--) {
		suffix_cnt[i] = suffix_cnt[i + 1];
		if (right.count(a[i])) continue;
		right.insert(a[i]);
		suffix_cnt[i]++;
	}
	long long ans = 0;
	set<int> left;
	for (int i = 0; i < n; i++) {
		if (left.count(a[i])) continue;
		left.insert(a[i]);
		ans += suffix_cnt[i + 1];
	}

	cout << ans << '\n';


	return 0;
}