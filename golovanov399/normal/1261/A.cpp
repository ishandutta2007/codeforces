#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

void solve() {
	int n = nxt(), k = nxt();
	string s;
	cin >> s;
	string need;
	for (int i = 0; i < k - 1; ++i) {
		need += "()";
	}
	for (int i = 0; i < n / 2 - k + 1; ++i) {
		need += "(";
	}
	for (int i = 0; i < n / 2 - k + 1; ++i) {
		need += ")";
	}
	vector<pair<int, int>> ans;
	for (int i = 0; i < n; ++i) {
		if (s[i] == need[i]) {
			continue;
		}
		int j = i;
		while (s[j] != need[i]) {
			++j;
		}
		reverse(s.begin() + i, s.begin() + j + 1);
		ans.push_back({i, j});
	}
	cout << ans.size() << "\n";
	for (auto [x, y] : ans) {
		cout << x + 1 << " " << y + 1 << "\n";
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}