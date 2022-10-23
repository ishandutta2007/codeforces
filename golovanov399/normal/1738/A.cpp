#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	int n = nxt();
	vector<int> a[2];
	vector<int> types(n), as(n);
	generate(all(types), nxt);
	generate(all(as), nxt);
	for (int i = 0; i < n; ++i) {
		a[types[i]].push_back(as[i]);
	}
	for (int i : {0, 1}) {
		sort(all(a[i]));
		reverse(all(a[i]));
	}
	long long sum = accumulate(all(a[0]), 0ll) + accumulate(all(a[1]), 0ll);
	if (a[0].empty() || a[1].empty()) {
		cout << sum << "\n";
		return;
	}
	long long ans = 0;
	for (int first : {0, 1}) {
		int cnt_fs = min((int)a[0].size(), (int)a[1].size() - first);
		int cnt_sf = min((int)a[1].size(), (int)a[0].size() - !first);
		long long tmp = sum + accumulate(a[0].begin(), a[0].begin() + cnt_sf, 0ll) + accumulate(a[1].begin(), a[1].begin() + cnt_fs, 0ll);
		ans = max(ans, tmp);
	}
	cout << ans << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}