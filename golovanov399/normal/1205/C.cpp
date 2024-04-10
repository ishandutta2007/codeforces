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

bool ask(int x1, int y1, int x2, int y2) {
	cout << "? " << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1 << endl;
	return nxt() == 1;
}

const int N = 55;

int a[2][N][N];
char dp[2][N][N][N][N];

void fillDp(int t, int n) {
	for (int x1 = n - 1; x1 >= 0; --x1) {
		for (int y1 = n - 1; y1 >= 0; --y1) {
			for (int x2 = x1; x2 < n; ++x2) {
				for (int y2 = y1; y2 < n; ++y2) {
					char& res = dp[t][x1][y1][x2][y2];
					if (x1 == x2 && y1 == y2) {
						res = true;
					} else if (x2 - x1 + y2 - y1 == 1) {
						res = (a[t][x1][y1] == a[t][x2][y2]);
					} else {
						res = 0;
						if (a[t][x1][y1] != a[t][x2][y2]) {
							continue;
						}
						for (int i = 0; i < 4; ++i) {
							int nx1 = x1, ny1 = y1;
							int nx2 = x2, ny2 = y2;
							if (i & 1) {
								++nx1;
							} else {
								++ny1;
							}
							if (i & 2) {
								--nx2;
							} else {
								--ny2;
							}
							if (nx1 <= nx2 && ny1 <= ny2 && dp[t][nx1][ny1][nx2][ny2]) {
								res = 1;
								break;
							}
						}
					}
				}
			}
		}
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	a[0][0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i % 2 != j % 2) {
				continue;
			}
			if (!i && !j) {
				continue;
			}
			if (j > 1) {
				a[0][i][j] = a[0][i][j - 2] ^ ((int)!ask(i, j - 2, i, j));
			}
		}
		if (i) {
			int x1 = i - 1, y1 = (i - 1) % 2;
			int x2 = i, y2 = y1 + 1;
			if (ask(x1, y1, x2, y2) != (a[0][x1][y1] == a[0][x2][y2])) {
				for (int j = 0; j < n; ++j) {
					if (i % 2 == j % 2) {
						a[0][i][j] ^= 1;
					}
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i % 2 == j % 2) {
				continue;
			}
			if (j > 1) {
				a[0][i][j] = a[0][i][j - 2] ^ ((int)!ask(i, j - 2, i, j));
			}
		}
		if (i) {
			int x1 = i - 1, y1 = i % 2;
			int x2 = i, y2 = y1 + 1;
			if (ask(x1, y1, x2, y2) != (a[0][x1][y1] == a[0][x2][y2])) {
				for (int j = 0; j < n; ++j) {
					if (i % 2 != j % 2) {
						a[0][i][j] ^= 1;
					}
				}
			}
		}
	}
	memcpy(a[1], a[0], sizeof(a[0]));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i % 2 != j % 2) {
				a[1][i][j] ^= 1;
			}
		}
	}

	for (int i = 0; i < 2; ++i) {
		fillDp(i, n);
	}

	for (int x1 = n - 1; x1 >= 0; --x1) {
		for (int y1 = n - 1; y1 >= 0; --y1) {
			for (int x2 = x1; x2 < n; ++x2) {
				for (int y2 = y1; y2 < n; ++y2) {
					if (x2 - x1 + y2 - y1 <= 1) {
						continue;
					}
					if (dp[0][x1][y1][x2][y2] != dp[1][x1][y1][x2][y2]) {
						auto good = ask(x1, y1, x2, y2);
						int t = (good == dp[1][x1][y1][x2][y2]);
						cout << "!" << endl;
						for (int i = 0; i < n; ++i) {
							for (int j = 0; j < n; ++j) {
								cout << (int)a[t][i][j];
							}
							cout << endl;
						}
						return 0;
					}
				}
			}
		}
	}

	cout << "!" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << (int)a[0][i][j];
		}
		cout << endl;
	}

	return 0;
}