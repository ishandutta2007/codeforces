#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int mod = 998244353;

struct Edge {
	int to, x;
};

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	string s;
	cin >> s;
	int n = s.length();

	if (s.back() == '1') {
		cout << "0\n";
		return 0;
	}
	s.back() = '0';

	vector<int> deg(3 * n + 1, 1);
	for (int i = 1; i < (int)deg.size(); ++i) {
		deg[i] = deg[i - 1] * 2 % mod;
	}

	long long ans = 0;
	for (int l = 1; l < n; ++l) {
		vector<vector<Edge>> a(2 * n + 1);
		for (int i = 0; i < l; ++i) {
			int idx_a = min(i, l - 1 - i);
			int idx_b = min(i, n - 1 - i) + n;
			if (s[n - 1 - i] != '?') {
				int x = s[n - 1 - i] - '0';
				a[idx_a].push_back({idx_b, x});
				a[idx_b].push_back({idx_a, x});
			}
		}

		for (int i = l; i < n; ++i) {
			if (s[n - 1 - i] != '?') {
				int x = s[n - 1 - i] - '0';
				int idx_b = min(i, n - 1 - i) + n;
				int idx_a = 2 * n;
				a[idx_a].push_back({idx_b, x});
				a[idx_b].push_back({idx_a, x});
			}
		}

		for (int i = (n + 1) / 2; i < n; ++i) {
			int x = 0;
			int idx_a = 2 * n;
			int idx_b = i + n;
			a[idx_a].push_back({idx_b, x});
			a[idx_b].push_back({idx_a, x});
		}
		for (int i = (l + 1) / 2; i < n; ++i) {
			int x = 0;
			int idx_a = i;
			int idx_b = 2 * n;
			a[idx_a].push_back({idx_b, x});
			a[idx_b].push_back({idx_a, x});
		}

		vector<int> color(2 * n + 1, -1);
		bool ok = true;
		int cnt_comps = 0;
		for (int i = 0; i < 2 * n + 1; ++i) {
			if (color[i] > -1) {
				continue;
			}
			++cnt_comps;
			vector<int> st = {i};
			color[i] = 0;
			while (!st.empty()) {
				int v = st.back();
				st.pop_back();
				for (const auto& [to, x] : a[v]) {
					if (color[to] == -1) {
						color[to] = color[v] ^ x;
						st.push_back(to);
					} else if (color[to] != (color[v] ^ x)) {
						ok = false;
						break;
					}
				}
			}
		}

		if (ok) {
			ans += deg[cnt_comps - 1];
		}
		// cerr << ok << " " << cnt_comps << "\n";
	}

	cout << ans % mod << "\n";

	return 0;
}