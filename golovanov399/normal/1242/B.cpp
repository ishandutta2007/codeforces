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
	scanf("%d", &x);
	return x;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), m = nxt();
	vector<vector<int>> a(n);
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	int ans = -1;
	set<int> remaining;
	for (int i = 0; i < n; ++i) {
		remaining.insert(i);
	}
	for (int i = 0; i < n; ++i) {
		if (!remaining.count(i)) {
			continue;
		}
		++ans;

		remaining.erase(i);
		set<int> banned;
		for (int x : a[i]) {
			if (remaining.count(x)) {
				banned.insert(x);
				remaining.erase(x);
			}
		}
		while (!remaining.empty()) {
			auto v = *remaining.begin();
			remaining.erase(remaining.begin());
			set<int> new_banned;
			for (int x : a[v]) {
				if (remaining.count(x)) {
					continue;
				} else if (banned.count(x)) {
					banned.erase(x);
					new_banned.insert(x);
				}
			}
			for (int x : banned) {
				remaining.insert(x);
			}
			banned.swap(new_banned);
		}
		remaining.swap(banned);
	}

	cout << ans << "\n";

	return 0;
}