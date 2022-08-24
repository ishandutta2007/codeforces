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

const int N = 1555;
int dp[N][N];
int dpsum[N][N];

bool check(const vector<int>& _a, int x, const vector<pair<int, int>>& segs, int limit, int k) {
	limit = min(limit, (int)segs.size());
	int n = _a.size();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = (_a[i] <= x);
	}
	vector<int> p(n + 1);
	for (int i = 0; i < n; ++i) {
		p[i + 1] = p[i] + a[i];
	}

	// cerr << "check for " << x << "\n";
	// cerr << "a: ";
	// for (int i = 0; i < n; ++i) {
	// 	cerr << a[i] << " ";
	// }
	// cerr << "\n";

	vector<int> next_guy(n + 1, N);
	for (int i = 0; i < (int)segs.size(); ++i) {
		next_guy[segs[i].second] = i;
	}
	for (int i = n; i > 0; --i) {
		next_guy[i - 1] = min(next_guy[i], next_guy[i - 1]);
	}

	// cerr << "last guy: ";
	// for (int i = 0; i < n; ++i) {
	// 	cerr << last_guy[i] << " ";
	// }
	// cerr << "\n";
	// cerr << "next guy: ";
	// for (int i = 0; i < n; ++i) {
	// 	cerr << next_guy[i] << " ";
	// }
	// cerr << "\n";
	// cerr << "k = " << k << "\n";

	int s = segs.size();
	for (int i = 0; i < s; ++i) {
		// at the place where i-th segment ends
		for (int j = 1; j <= i + 1; ++j) {
			// we took no more than j segments including it
			dp[i][j] = p[segs[i].second] - p[segs[i].first];

			if (j > 1) {
				assert(next_guy[segs[i].first] >= 0);
				int idx = next_guy[segs[i].first];
				if (idx > 0) {
					dp[i][j] += dpsum[idx - 1][j - 1];
				}

				if (idx < i) {
					dp[i][j] = max(dp[i][j], p[segs[i].second] - p[segs[idx].second] + dp[idx][j - 1]);
				}
			}
			dpsum[i][j] = dp[i][j];
			if (i >= j) {
				dpsum[i][j] = max(dpsum[i][j], dpsum[i - 1][j]);
			}
		}
	}
	for (int i = 1; i <= limit; ++i) {
		if (dpsum[s - 1][i] >= k) {
			return true;
		}
	}
	return false;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), s = nxt(), lim = nxt(), k = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	vector<int> un = a;
	make_unique(un);

	vector<pair<int, int>> segs(s);
	for (int i = 0; i < s; ++i) {
		segs[i].first = nxt() - 1;
		segs[i].second = nxt();
	}

	sort(all(segs), [](const pair<int, int>& p, const pair<int, int>& q) {
		if (p.first != q.first) {
			return p.first < q.first;
		} else {
			return p.second > q.second;
		}
	});
	vector<pair<int, int>> new_segs;
	for (int i = 0; i < (int)segs.size(); ++i) {
		if (i == 0 || segs[i].second > new_segs.back().second) {
			new_segs.push_back(segs[i]);
		}
	}
	segs.swap(new_segs);
	s = segs.size();

	if (!check(a, un.back(), segs, lim, k)) {
		cout << "-1\n";
		return 0;
	}

	int l = -1, r = (int)un.size() - 1;
	while (l + 1 < r) {
		int m = (l + r) / 2;
		if (check(a, un[m], segs, lim, k)) {
			r = m;
		} else {
			l = m;
		}
	}
	cout << un[r] << "\n";

	return 0;
}