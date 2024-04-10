#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	ios_base::sync_with_stdio(0);
	int n = nxt();
	vector<vector<int>> a(n);
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		a[i].resize(n);
		for (int j = 0; j < n; ++j) {
			a[i][j] = s[j] - '0';
		}
	}
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < n; ++j) {
			a[i][j] ^= s[j] - '0';
		}
	}

	vector<int> b(n);
	{
		string s;
		cin >> s;
		for (int i = 0; i < n; ++i) {
			b[i] = s[i] - '0';
		}
	}
	vector<int> ans(n + n, -1);
	auto chg = [&](int i, int x) {
		if (ans[i] != x && ans[i] != -1) {
			puts("-1");
			exit(0);
		} else {
			ans[i] = x;
		}
	};
	vector<vector<pair<int, int>>> ed(n + n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			vector<int> can;
			if (b[i]) {
				can.push_back(j);
			}
			if (b[j]) {
				can.push_back(n + i);
			}
			if (can.empty()) {
				if (a[i][j]) {
					puts("-1");
					return 0;
				}
			} else if ((int)can.size() == 1) {
				chg(can[0], a[i][j]);
			} else {
				ed[can[0]].push_back({can[1], a[i][j]});
				ed[can[1]].push_back({can[0], a[i][j]});
			}
		}
	}

	// for (int i = 0; i < n + n; ++i) {
	// 	cerr << ans[i] << " ";
	// }
	// cerr << "\n";
	// for (int i = 0; i < n + n; ++i) {
	// 	cerr << i << ": ";
	// 	for (const auto& [to, x] : ed[i]) {
	// 		cerr << "(" << to << ", " << x << ") ";
	// 	}
	// 	cerr << "\n";
	// }

	vector<char> used(n + n);
	for (int i = 0; i < n + n; ++i) {
		if (ans[i] == -1) {
			continue;
		}
		if (used[i]) {
			continue;
		}
		used[i] = 1;
		vector<int> st = {i};
		while (!st.empty()) {
			int v = st.back();
			st.pop_back();
			for (const auto& [to, x] : ed[v]) {
				int val = ans[v] ^ x;
				chg(ans[to], val);
				if (!used[to]) {
					used[to] = 1;
					st.push_back(to);
				}
			}
		}
	}
	for (int i = 0; i < n + n; ++i) {
		if (used[i]) {
			continue;
		}
		used[i] = 1;
		ans[i] = 0;
		vector<int> st = {i};
		while (!st.empty()) {
			int v = st.back();
			st.pop_back();
			for (const auto& [to, x] : ed[v]) {
				int val = ans[v] ^ x;
				chg(to, val);
				if (!used[to]) {
					used[to] = 1;
					st.push_back(to);
				}
			}
		}
	}
	for (int i = 0; i < n + n; ++i) {
		if (ans[i] == -1) {
			ans[i] = 0;
		}
	}
	cout << accumulate(all(ans), 0) << "\n";
	for (int i = 0; i < n; ++i) {
		if (ans[i]) {
			cout << "col " << i << "\n";
		}
	}
	for (int i = 0; i < n; ++i) {
		if (ans[n + i]) {
			cout << "row " << i << "\n";
		}
	}

	return 0;
}