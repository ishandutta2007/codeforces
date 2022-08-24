#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

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
	vector<int> ans = {a[0]};
	for (int i = 1; i < n - 1; ++i) {
		if ((a[i] < a[i - 1]) == (a[i] < a[i + 1])) {
			ans.push_back(a[i]);
		}
	}
	ans.push_back(a.back());
	cout << ans.size() << "\n";
	for (int x : ans) {
		cout << x << " ";
	}
	cout << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}