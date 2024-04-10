#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
// #define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

void solve() {
	int n = nxt();
	map<int, int> M;
	for (int i = 0; i < n; ++i) {
		M[nxt()] += 1;
	}
	int mx = 0;
	for (auto p : M) {
		mx = max(mx, p.second);
	}
	int ans = n - mx;
	while (mx < n) {
		++ans;
		mx *= 2;
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}