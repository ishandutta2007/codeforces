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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

pair<vector<int>, vector<int>> check(int n, const vector<array<int, 4>>& res) {
	vector<vector<pair<int, int>>> a(n, vector<pair<int, int>>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			a[i][j] = {i, j};
		}
	}
	for (const auto& v : res) {
		a[v[0]][v[1]] = {v[2], v[3]};
		a[v[2]][v[3]] = {v[0], v[1]};
	}
	vector<int> r(n), c(n);
	for (int i = 0; i < n; ++i) {
		int x = i, y = 0;
		while (y < n) {
			auto p = a[x][y];
			x = p.first, y = p.second;
			++y;
		}
		r[i] = x;
	}
	for (int i = 0; i < n; ++i) {
		int x = 0, y = i;
		while (x < n) {
			auto p = a[x][y];
			x = p.first, y = p.second;
			++x;
		}
		c[i] = y;
	}
	return {r, c};
}

map<pair<vector<int>, vector<int>>, vector<array<int, 4>>> get(int n) {
	vector<int> r(n), c(n);
	set<pair<vector<int>, vector<int>>> S;
	iota(all(r), 0);
	do {
		iota(all(c), 0);
		do {
			S.insert({r, c});
		} while (next_permutation(all(c)));
	} while (next_permutation(all(r)));
	map<pair<vector<int>, vector<int>>, vector<array<int, 4>>> M;
	while (!S.empty()) {
		vector<pair<int, int>> prs;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				prs.push_back({i, j});
			}
		}
		random_shuffle(all(prs));
		vector<array<int, 4>> ans;
		int mx = (int)prs.size() / 2;
		for (int i = 0; i < mx; ++i) {
			auto rc = check(n, ans);
			if (S.count(rc)) {
				S.erase(rc);
				M[rc] = ans;
			}
			int sz = prs.size();
			ans.push_back({prs[sz - 1].first, prs[sz - 1].second, prs[sz - 2].first, prs[sz - 2].second});
			prs.pop_back();
			prs.pop_back();
		}
	}
	return M;
}

void solve(int n, const vector<int>& r, const vector<int>& c) {
	vector<int> id(n);
	iota(all(id), 0);
	if (n == 1) {
		cout << "0\n";
		return;
	}
	if (n == 2) {
		if (r == id && c == id) {
			cout << "0\n";
		} else if (r == id) {
			cout << "1\n1 1 1 2\n";
		} else if (c == id) {
			cout << "1\n1 1 2 1\n";
		} else {
			cout << "1\n1 1 2 2\n";
		}
		return;
	}
	auto ans = get(n)[{r, c}];
	printf("%d\n", (int)ans.size());
	for (const auto& v : ans) {
		for (int x : v) {
			printf("%d ", x + 1);
		}
		printf("\n");
	}
}

void test() {
	int n = 10;
	vector<int> r(n), c(n);
	iota(all(r), 0);
	iota(all(c), 0);
	random_shuffle(all(r));
	random_shuffle(all(c));

	vector<array<int, 4>> ans;
	ans.push_back({0, 0, 1, 1});
	ans.push_back({n - 1, 0, n - 2, 1});
	ans.push_back({0, n - 1, 1, n - 2});
	ans.push_back({n - 2, n - 2, n - 1, n - 1});

	for (int i = 0; i < n; ++i) {
		int fx = i, fy = 0;
		if (fx == 0) {
			++fx, fy += 2;
		} else if (fx == n - 1) {
			--fx, fy += 2;
		}
		int tx = r[i], ty = n - 1;
		if (tx == 0) {
			++tx, ty -= 2;
		} else if (tx == n - 1) {
			--tx, ty -= 2;
		}
		ans.push_back({fx, fy, tx, ty});
	}

	for (int i = 0; i < n; ++i) {
		int fx = i, fy = 0;
		if (fx == 0) {
			++fx, fy += 2;
		} else if (fx == n - 1) {
			--fx, fy += 2;
		}
		int tx = c[i], ty = n - 1;
		if (tx == 0) {
			++tx, ty -= 2;
		} else if (tx == n - 1) {
			--tx, ty -= 2;
		}
		swap(fx, fy);
		swap(tx, ty);
		ans.push_back({fx, fy, tx, ty});
	}

	for (int x : r) {
		cout << x + 1 << " ";
	}
	cout << "\n";
	for (int x : c) {
		cout << x + 1 << " ";
	}
	cout << "\n";
	printf("%d\n", (int)ans.size());
	for (const auto& v : ans) {
		for (int x : v) {
			printf("%d ", x + 1);
		}
		printf("\n");
	}

	auto rc = check(n, ans);
	assert(rc.first == r);
	assert(rc.second == c);
	exit(0);
}

int main() {
	// test();

	int n = nxt();
	vector<int> r(n), c(n);
	for (int i = 0; i < n; ++i) {
		r[i] = nxt() - 1;
	}
	for (int i = 0; i < n; ++i) {
		c[i] = nxt() - 1;
	}

	if (n >= 6) {
		vector<array<int, 4>> ans;
		ans.push_back({0, 0, 1, 1});
		ans.push_back({n - 1, 0, n - 2, 1});
		ans.push_back({0, n - 1, 1, n - 2});
		ans.push_back({n - 2, n - 2, n - 1, n - 1});

		for (int i = 0; i < n; ++i) {
			int fx = i, fy = 0;
			if (fx == 0) {
				++fx, fy += 2;
			} else if (fx == n - 1) {
				--fx, fy += 2;
			}
			int tx = r[i], ty = n - 1;
			if (tx == 0) {
				++tx, ty -= 2;
			} else if (tx == n - 1) {
				--tx, ty -= 2;
			}
			ans.push_back({fx, fy, tx, ty});
		}

		for (int i = 0; i < n; ++i) {
			int fx = i, fy = 0;
			if (fx == 0) {
				++fx, fy += 2;
			} else if (fx == n - 1) {
				--fx, fy += 2;
			}
			int tx = c[i], ty = n - 1;
			if (tx == 0) {
				++tx, ty -= 2;
			} else if (tx == n - 1) {
				--tx, ty -= 2;
			}
			swap(fx, fy);
			swap(tx, ty);
			ans.push_back({fx, fy, tx, ty});
		}

		printf("%d\n", (int)ans.size());
		for (const auto& v : ans) {
			for (int x : v) {
				printf("%d ", x + 1);
			}
			printf("\n");
		}
	} else {
		solve(n, r, c);
	}

	return 0;
}