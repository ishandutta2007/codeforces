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
	vector<int> a(n);
	generate(all(a), nxt);
	if (count_if(all(a), [](int x) { return !!x; }) % 2) {
		cout << "-1\n";
		return;
	}
	if (all_of(all(a), [](int x) { return !x; })) {
		cout << "1\n1 " << n << "\n";
		return;
	}
	vector<int> ans;
	if (a[0] == 0) {
		ans.push_back(0);
	}
	for (int i = 0; i < n; ++i) {
		while (i < n && !a[i]) {
			++i;
		}
		if (i == n) {
			break;
		}
		int l = i;
		++i;
		while (!a[i]) {
			++i;
		}
		int r = i;
		ans.push_back(l);
		if ((l % 2 == r % 2) == (a[l] == a[r])) {
			ans.push_back(r - (a[l] == a[r]));
		}
	}
	ans.push_back(n);
	cout << ans.size() - 1 << "\n";
	for (int i = 0; i < (int)ans.size() - 1; ++i) {
		cout << ans[i] + 1 << " " << ans[i + 1] << "\n";
	}
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}