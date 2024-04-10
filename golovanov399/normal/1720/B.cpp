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

int f(vector<int> a, int l, int r) {
	int ans = *max_element(a.begin() + l, a.begin() + r + 1) - *min_element(a.begin() + l, a.begin() + r + 1);
	a.erase(a.begin() + l, a.begin() + r + 1);
	ans += *max_element(all(a)) - *min_element(all(a));
	return ans;
}

void solve() {
	int n = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	vector<pair<int, int>> ar(n);
	for (int i = 0; i < n; ++i) {
		ar[i] = {a[i], i};
	}
	sort(all(ar));
	vector<int> ids = {ar[0].second, ar[1].second, ar[n - 2].second, ar[n - 1].second};
	sort(all(ids));
	cout << max(f(a, ids[1], ids[2]), f(a, ids[0], ids[1])) << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}