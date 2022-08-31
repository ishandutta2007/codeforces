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

void panic() {
	cout << "-1\n";
	exit(0);
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	vector<int> nx(n, -1);
	vector<int> have[4];
	vector<char> cursed(n, 0);
	for (int i = n - 1; i >= 0; --i) {
		if (a[i] == 0) {
			continue;
		}
		if (a[i] == 2) {
			if (have[1].empty()) {
				panic();
			}
			nx[i] = have[1].back();
			cursed[nx[i]] = true;
			have[1].pop_back();
			have[2].push_back(i);
		} else if (a[i] == 1) {
			have[1].push_back(i);
		} else {
			assert(a[i] == 3);
			if (!have[3].empty()) {
				nx[i] = have[3].back();
				have[3].pop_back();
				have[3].push_back(i);
			} else if (!have[2].empty()) {
				nx[i] = have[2].back();
				have[2].pop_back();
				have[3].push_back(i);
			} else if (!have[1].empty()) {
				nx[i] = have[1].back();
				have[1].pop_back();
				have[3].push_back(i);
			} else {
				panic();
			}
		}
	}

	vector<pair<int, int>> ans;
	int cur = 0;
	for (int i = 0; i < n; ++i) {
		if (!a[i]) {
			continue;
		}
		if (nx[i] == -1) {
			assert(a[i] == 1);
			if (!cursed[i]) {
				ans.push_back({cur++, i});
			}
			continue;
		}
		ans.push_back({cur, i});
		ans.push_back({cur++, nx[i]});
	}
	cout << ans.size() << "\n";
	for (auto [x, y] : ans) {
		cout << x + 1 << " " << y + 1 << "\n";
	}

	return 0;
}