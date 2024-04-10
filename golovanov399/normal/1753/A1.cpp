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
	if (n % 2) {
		cout << "-1\n";
		return;
	}
	vector<int> ans;
	for (int i = 0; i < n; i += 2) {
		ans.push_back(i);
		if (a[i] != a[i + 1]) {
			ans.push_back(i + 1);
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