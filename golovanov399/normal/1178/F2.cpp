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

const int N = 1010;
const int mod = 998244353;

long long dp[N][N];
int mn[N][N];

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), m = nxt();
	vector<int> a(m);
	for (int i = 0; i < m; ++i) {
		a[i] = nxt() - 1;
	}

	vector<int> le(n, m), ri(n);
	for (int i = 0; i < m; ++i) {
		le[a[i]] = min(le[a[i]], i);
		ri[a[i]] = max(ri[a[i]], i + 1);
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int j = i + 1; j < n; ++j) {
			if (le[j] >= ri[i] || le[i] >= ri[j]) {
				continue;
			}
			if (!(le[j] > le[i] && ri[j] < ri[i])) {
				cout << "0\n";
				return 0;
			}
		}
	}

	// vector<vector<int>> subs(n);
	{
		vector<int> st = {};
		for (int i = 0; i < m; ++i) {
			if (le[a[i]] == i) {
				// if (!st.empty()) {
				// 	subs[st.back()].push_back(a[i]);
				// }
				st.push_back(a[i]);
			}
			if (ri[a[i]] == i + 1) {
				assert(st.back() == a[i]);
				st.pop_back();
			}
			if (!st.empty() && !(le[st.back()] <= le[a[i]] && ri[st.back()] >= ri[a[i]])) {
				cout << "0\n";
				return 0;
			}
		}
	}

	vector<int> everything;
	for (int i = 0; i < n; ++i) {
		everything.push_back(le[i]);
		everything.push_back(ri[i]);
	}
	make_unique(everything);
	int sz = everything.size();
	for (int i = 0; i < n; ++i) {
		le[i] = lower_bound(all(everything), le[i]) - everything.begin();
		ri[i] = lower_bound(all(everything), ri[i]) - everything.begin();
	}

	memset(mn, -1, sizeof(mn));
	for (int i = n - 1; i >= 0; --i) {
		for (int l = 0; l <= le[i]; ++l) {
			for (int r = ri[i]; r <= sz; ++r) {
				mn[l][r] = i;
			}
		}
	}

	vector<vector<pair<int, int>>> subs(n);
	for (int i = 0; i < n; ++i) {
		vector<pair<int, int>> ev;
		for (int j = i + 1; j < n; ++j) {
			if (le[j] > le[i] && ri[j] < ri[i]) {
				ev.push_back({le[j], -1});
				ev.push_back({ri[j], 1});
			}
		}
		sort(all(ev));
		int bal = 0;
		for (auto [id, x] : ev) {
			if (bal == 0) {
				subs[i].push_back({id, 0});
			}
			if (x == -1) {
				++bal;
			} else {
				--bal;
			}
			if (bal == 0) {
				subs[i].back().second = id;
			}
		}
	}

	for (int i = 0; i <= sz; ++i) {
		dp[i][i] = 1;
	}
	for (int len = 1; len < sz; ++len) {
		for (int l = 0; l + len < sz; ++l) {
			int r = l + len;
			if (mn[l][r] == -1) {
				continue;
			}
			int idx = mn[l][r];

			long long t1 = 0, t2 = 0;
			for (int i = 0; i <= le[idx] - l; ++i) {
				t1 += dp[l][l + i] * dp[l + i][le[idx]] % mod;
			}
			for (int i = 0; i <= r - ri[idx]; ++i) {
				t2 += dp[ri[idx]][ri[idx] + i] * dp[ri[idx] + i][r] % mod;
			}
			t1 %= mod;
			t2 %= mod;
			dp[l][r] = t1 * t2 % mod;

			for (auto [ll, rr] : subs[idx]) {
				dp[l][r] = dp[l][r] * dp[ll][rr] % mod;
			}
			// cerr << l << " " << r << ": " << idx << ", " << dp[l][r] << "\n";
		}
	}

	// for (int i = 0; i < n; ++i) {
	// 	for (int j = i + 1; j <= n; ++j) {
	// 		cerr << dp[i][j] << " ";
	// 	}
	// 	cerr << "\n";
	// }
	cout << dp[0][sz - 1] << "\n";

	return 0;
}