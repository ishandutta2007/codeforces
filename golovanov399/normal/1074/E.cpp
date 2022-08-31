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

struct Field {
	int n, m;
	vector<vector<int>> a;
	vector<vector<int>> ans;

	void scan() {
		n = nxt(), m = nxt();
		a.assign(n, vector<int>(m, 0));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				a[i][j] = nxt();
			}
		}
	}

	void add(const vector<pair<int, int>>& cyc) {
		// printState();
		ans.push_back({});
		for (auto p : cyc) {
			ans.back().push_back(a[p.first][p.second]);
		}
		assert(cyc.size() >= 4);
		int lst = a[cyc.back().first][cyc.back().second];
		for (int i = (int)cyc.size() - 2; i >= 0; --i) {
			a[cyc[i + 1].first][cyc[i + 1].second] = a[cyc[i].first][cyc[i].second];
			assert(abs(cyc[i].first - cyc[i + 1].first) + abs(cyc[i].second - cyc[i + 1].second) == 1);
		}
		a[cyc[0].first][cyc[0].second] = lst;
		assert(abs(cyc[0].first - cyc.back().first) + abs(cyc[0].second - cyc.back().second) == 1);
	}

	bool check() {
		int cur = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (++cur != a[i][j]) {
					return false;
				}
			}
		}
		return true;
	}

	void print() {
		printf("%d\n", (int)ans.size());
		for (const auto& v : ans) {
			printf("%d", (int)v.size());
			for (int x : v) {
				printf(" %d", x);
			}
			printf("\n");
		}
	}

	void printState() {
		cerr << string(m, '=') << "\n";
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cerr << a[i][j] << " ";
			}
			cerr << "\n";
		}
		cerr << string(m, '=') << "\n";
	}
};

void solve(Field field) {
	int n = field.n, m = field.m;

	auto moveRight = [&](int x, int y) {
		if (x == n - 1) {
			field.add({{x, y}, {x, y + 1}, {x - 1, y + 1}, {x - 1, y}});
		} else {
			field.add({{x, y}, {x, y + 1}, {x + 1, y + 1}, {x + 1, y}});
		}
	};

	auto moveLeft = [&](int x, int y) {
		if (x == n - 1) {
			field.add({{x, y}, {x, y - 1}, {x - 1, y - 1}, {x - 1, y}});
		} else {
			field.add({{x, y}, {x, y - 1}, {x + 1, y - 1}, {x + 1, y}});
		}
	};

	auto findNeed = [&](int need, int& x, int& y) {
		x = y = 0;
		while (field.a[x][y] != need) {
			++y;
			if (y == m) {
				y = 0;
				++x;
			}
		}
	};

	auto swapHor = [&](int x, int y) {
		// swaps (x, y) and (x, y + 1)
		field.add({{x - 1, y}, {x - 1, y + 1}, {x, y + 1}, {x, y}});
		field.add({{x - 1, y}, {x, y}, {x + 1, y}, {x + 1, y + 1}, {x, y + 1}, {x - 1, y + 1}});
		field.add({{x, y}, {x, y + 1}, {x + 1, y + 1}, {x + 1, y}});
	};

	auto swapVer = [&](int x, int y) {
		// swaps (x, y) and (x + 1, y)
		field.add({{x, y - 1}, {x + 1, y - 1}, {x + 1, y}, {x, y}});
		field.add({{x, y - 1}, {x, y}, {x, y + 1}, {x + 1, y + 1}, {x + 1, y}, {x + 1, y - 1}});
		field.add({{x, y}, {x + 1, y}, {x + 1, y + 1}, {x, y + 1}});
	};

	auto moveGuyUp = [&](int need, int i, int j) {
		int x, y;
		findNeed(need, x, y);
		if (x == i) {
			while (y > j) {
				field.add({{x, y}, {x, y - 1}, {x + 1, y - 1}, {x + 1, y}});
				--y;
			}
			while (y < j) {
				field.add({{x, y}, {x, y + 1}, {x + 1, y + 1}, {x + 1, y}});
				++y;
			}
		} else {
			while (y < j) {
				moveRight(x, y);
				++y;
			}
			while (y > j) {
				moveLeft(x, y);
				--y;
			}
			while (x > i) {
				if (y < m - 1) {
					field.add({{x, y}, {x - 1, y}, {x - 1, y + 1}, {x, y + 1}});
				} else {
					field.add({{x, y}, {x - 1, y}, {x - 1, y - 1}, {x, y - 1}});
				}
				--x;
			}
		}
	};

	auto& a = field.a;

	for (int i = 0; i < n - 2; ++i) {
		// make one row
		for (int j = 0; j < m - 2; ++j) {
			int need = i * m + j + 1;
			moveGuyUp(need, i, j);
		}

		int need = i * m + m - 1;
		if (a[i][m - 2] == need && a[i][m - 1] == need + 1) {
			// pass;
		} else if (a[i][m - 2] == need + 1 && a[i][m - 1] == need) {
			if (i) {
				swapHor(i, m - 2);
			} else {
				field.add({{i, m - 2}, {i, m - 1}, {i + 1, m - 1}, {i + 1, m - 2}});
				field.add({{i, m - 2}, {i, m - 1}, {i + 1, m - 1}, {i + 1, m - 2}});
				swapHor(i + 1, m - 2);
				field.add({{i, m - 2}, {i, m - 1}, {i + 1, m - 1}, {i + 1, m - 2}});
				field.add({{i, m - 2}, {i, m - 1}, {i + 1, m - 1}, {i + 1, m - 2}});
			}
		} else if (a[i][m - 2] == need || a[i][m - 1] == need) {
			if (a[i][m - 2] == need) {
				if (a[i + 1][m - 2] == need + 1) {
					field.add({{i + 1, m - 2}, {i + 1, m - 1}, {i + 2, m - 1}, {i + 2, m - 2}});
				}
				field.add({{i, m - 2}, {i, m - 1}, {i + 1, m - 1}, {i + 1, m - 2}});
			}
			moveGuyUp(need + 1, i + 1, m - 1);
			field.add({{i + 1, m - 1}, {i, m - 1}, {i, m - 2}, {i + 1, m - 2}});
		} else if (a[i][m - 2] == need + 1 || a[i][m - 1] == need + 1) {
			if (a[i][m - 1] == need + 1) {
				if (a[i + 1][m - 1] == need) {
					field.add({{i + 1, m - 2}, {i + 1, m - 1}, {i + 2, m - 1}, {i + 2, m - 2}});
				}
				field.add({{i, m - 1}, {i, m - 2}, {i + 1, m - 2}, {i + 1, m - 1}});
			}
			moveGuyUp(need, i + 1, m - 2);
			field.add({{i + 1, m - 2}, {i, m - 2}, {i, m - 1}, {i + 1, m - 1}});
		} else {
			moveGuyUp(need + 1, i, m - 2);
			moveGuyUp(need, i + 1, m - 2);
			field.add({{i + 1, m - 2}, {i, m - 2}, {i, m - 1}, {i + 1, m - 1}});
		}
	}

	for (int j = 0; j < m - 2; ++j) {
		int need = (n - 2) * m + j + 1;
		int x, y;
		findNeed(need, x, y);
		if (x != n - 1) {
			assert(x == n - 2);
			if (y > j) {
				field.add({{x, y}, {x + 1, y}, {x + 1, y - 1}, {x, y - 1}});
			} else {
				field.add({{x, y}, {x + 1, y}, {x + 1, y + 1}, {x, y + 1}});
			}
			++x;
		}

		while (y > j) {
			moveLeft(x, y);
			--y;
		}

		if (field.a[n - 2][j] == need + m) {
			for (int _ = 0; _ < 2; ++_) {
				field.add({{n - 2, j}, {n - 2, j + 1}, {n - 1, j + 1}, {n - 1, j}});
			}
			swapVer(n - 2, j + 1);
			for (int _ = 0; _ < 2; ++_) {
				field.add({{n - 2, j}, {n - 2, j + 1}, {n - 1, j + 1}, {n - 1, j}});
			}
		} else {
			findNeed(need + m, x, y);
			if (x != n - 1) {
				assert(x == n - 2);
				if (y > j + 1) {
					field.add({{x, y}, {x + 1, y}, {x + 1, y - 1}, {x, y - 1}});
				} else {
					field.add({{x, y}, {x + 1, y}, {x + 1, y + 1}, {x, y + 1}});
				}
				++x;
			}
			while (y > j + 1) {
				moveLeft(x, y);
				--y;
			}
			field.add({{n - 1, j + 1}, {n - 1, j}, {n - 2, j}, {n - 2, j + 1}});
		}
	}

	while (a[n - 1][m - 1] != n * m) {
		field.add({{n - 2, m - 2}, {n - 2, m - 1}, {n - 1, m - 1}, {n - 1, m - 2}});
	}
	int x, y;
	findNeed(n * m - 1, x, y);
	if (y == m - 1) {
		swapHor(n - 2, m - 2);
		--y;
	}
	if (x == n - 2) {
		swapVer(n - 2, m - 2);
	}
	if (!field.check()) {
		swapHor(n - 2, m - 2);
	}
	field.print();
	// assert(field.check());
	// if (!field.check()) {
	// 	field.printState();
	// 	exit(11);
	// }
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#if 1
	Field field;
	field.scan();
	solve(field);
#else
	while (true) {
		Field field;
		int n = rand() % 3 + 3, m = rand() % 3 + 3;
		field.n = n, field.m = m;
		vector<int> perm(n * m);
		iota(all(perm), 1);
		random_shuffle(all(perm));
		field.a.assign(n, vector<int>(m, 0));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				field.a[i][j] = perm[i * m + j];
			}
		}
		field.printState();
		solve(field);
	}
#endif

	return 0;
}