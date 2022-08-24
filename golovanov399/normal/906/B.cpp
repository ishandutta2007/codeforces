#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

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
	// cerr << "panic\n";
	puts("NO");
	exit(0);
}

void check(const vector<vector<int>>& a) {
	return;
	int n = a.size();
	int m = a[0].size();
	vector<set<int>> neig(n * m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m - 1; ++j) {
			neig[i * m + j].insert(i * m + j + 1);
			neig[i * m + j + 1].insert(i * m + j);
		}
	}
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < m; ++j) {
			neig[i * m + j].insert(i * m + j + m);
			neig[i * m + j + m].insert(i * m + j);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m - 1; ++j) {
			itn x = a[i][j] - 1, y = a[i][j + 1] - 1;
			if (neig[x].count(y)) {
				cerr << "bad\n";
				for (auto v : a) {
					for (int x : v) {
						cerr << x << " ";
					}
					cerr << "\n";
				}
				exit(1);
			}
		}
	}
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < m; ++j) {
			itn x = a[i][j] - 1, y = a[i + 1][j] - 1;
			if (neig[x].count(y)) {
				cerr << "bad\n";
				for (auto v : a) {
					for (int x : v) {
						cerr << x << " ";
					}
					cerr << "\n";
				}
				exit(1);
			}
		}
	}
	cerr << "ok\n";
}

int main() {
	int n = nxt(), m = nxt();

	if (n == 1 && m == 1) {
		puts("YES\n1");
		return 0;
	}

	if (n == 1) {
		if (m <= 3) {
			panic();
		}
		vector<int> ans(m);
		for (int i = 0; i < m; ++i) {
			if (2 * i + 1 < m) {
				ans[2 * i + 1] = i + 1;
			} else {
				ans[2 * (i - m / 2)] = i + 1;
			}
		}
		check({ans});
		printf("YES\n");
		for (int x : ans) {
			printf("%d ", x);
		}
		printf("\n");
		return 0;
	} else if (m == 1) {
		swap(n, m);
		if (m <= 3) {
			panic();
		}
		vector<int> ans(m);
		for (int i = 0; i < m; ++i) {
			if (2 * i + 1 < m) {
				ans[2 * i + 1] = i + 1;
			} else {
				ans[2 * (i - m / 2)] = i + 1;
			}
		}
		check({ans});
		printf("YES\n");
		for (int x : ans) {
			printf("%d\n", x);
		}
		return 0;
	} else if (m > 3) {
		vector<vector<int>> ans(n, vector<int>(m, 0));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (2 * j + 1 < m) {
					ans[i][2 * j + 1] = i * m + j + 1;
				} else {
					ans[i][2 * (j - m / 2)] = i * m + j + 1;
				}
			}
			if (i % 2) {
				if (m % 2) {
					reverse(all(ans[i]));
					for (int j = 0; j < m; ++j) {
						ans[i][j] = i * m + (m + 1) - ans[i][j] + i * m;
					}
				} else {
					reverse(all(ans[i]));
				}
			}
		}

		check(ans);
		printf("YES\n");
		for (auto v : ans) {
			for (int x : v) {
				printf("%d ", x);
			}
			printf("\n");
		}
	} else if (n > 3) {
		vector<vector<int>> ans(n, vector<int>(m, 0));
		for (int j = 0; j < m; ++j) {
			for (int i = 0; i < n; ++i) {
				if (2 * i + 1 < n) {
					ans[2 * i + 1][j] = i * m + j + 1;
				} else {
					ans[2 * (i - n / 2)][j] = i * m + j + 1;
				}
			}
			if (j % 2) {
				if (n % 2) {
					for (int k = 0; k * 2 < n; ++k) {
						swap(ans[k][j], ans[n - 1 - k][j]);
					}
					for (int i = 0; i < n; ++i) {
						ans[i][j] = j + 1 + (n - 1) * m - ans[i][j] + j + 1;
					}
				} else {
					for (int k = 0; k * 2 < n; ++k) {
						swap(ans[k][j], ans[n - 1 - k][j]);
					}
				}
			}
		}

		check(ans);
		printf("YES\n");
		for (auto v : ans) {
			for (int x : v) {
				printf("%d ", x);
			}
			printf("\n");
		}
	} else if (n == m && m == 3) {
		check({{2, 7, 6}, {9, 5, 1}, {4, 3, 8}});
		puts("YES\n2 7 6\n9 5 1\n4 3 8");
	} else {
		puts("NO");
	}

	return 0;
}