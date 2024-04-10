#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

bool areRooked(const pair<int, int>& p, const pair<int, int>& q) {
	return p.first == q.first || p.second == q.second;
}

bool areQueened(const pair<int, int>& p, const pair<int, int>& q) {
	return p.first == q.first || p.second == q.second || p.first + p.second == q.first + q.second || p.first - p.second == q.first - q.second;
}

int getRook(int n, const vector<int>& a) {
	map<int, pair<int, int>> M;
	for (int i = 0; i < n * n; ++i) {
		M[a[i]] = {i / n, i % n};
	}
	int cost = 0;
	auto p = M[0];
	M.erase(0);
	while (!M.empty()) {
		int nx = -1;
		for (const auto& [i, q] : M) {
			if (areRooked(p, q)) {
				nx = i;
				break;
			}
		}
		if (nx > -1) {
			p = M[nx];
			M.erase(nx);
		} else {
			p = M.begin()->second;
			M.erase(M.begin());
			++cost;
		}
	}
	return cost;
}

int getQueen(int n, const vector<int>& a) {
	map<int, pair<int, int>> M;
	for (int i = 0; i < n * n; ++i) {
		M[a[i]] = {i / n, i % n};
	}
	int cost = 0;
	auto p = M[0];
	M.erase(0);
	while (!M.empty()) {
		int nx = -1;
		for (const auto& [i, q] : M) {
			if (areQueened(p, q)) {
				nx = i;
				break;
			}
		}
		if (nx > -1) {
			p = M[nx];
			M.erase(nx);
		} else {
			p = M.begin()->second;
			M.erase(M.begin());
			++cost;
		}
	}
	return cost;
}

int main() {
	int n = nxt();
	if (n < 3) {
		cout << "-1\n";
		return 0;
	}
	vector<vector<int>> a(n, vector<int>(n, 0));
	int x = 0, y = 0;
	int cur = 0;
	while (x < n - 3) {
		a[x][y] = ++cur;
		if (x % 2 == 0) {
			if (y == n - 1) {
				++x;
			} else {
				++y;
			}
		} else {
			if (y == 0) {
				++x;
			} else {
				--y;
			}
		}
	}
	int py = y;
	int dy = py > 0 ? -1 : 1;
	while (y != py + (n - 3) * dy) {
		a[x][y] = ++cur;
		if (y % 2 == py % 2) {
			if (x == n - 1) {
				y += dy;
			} else {
				++x;
			}
		} else {
			if (x == n - 3) {
				y += dy;
			} else {
				--x;
			}
		}
	}
	int dx = (x == n - 3) ? 1 : -1;
	a[x + 0 * dx][y + 0 * dy] = ++cur;
	a[x + 0 * dx][y + 1 * dy] = ++cur;
	a[x + 1 * dx][y + 1 * dy] = ++cur;
	a[x + 0 * dx][y + 2 * dy] = ++cur;
	a[x + 1 * dx][y + 0 * dy] = ++cur;
	a[x + 2 * dx][y + 1 * dy] = ++cur;
	a[x + 2 * dx][y + 2 * dy] = ++cur;
	a[x + 1 * dx][y + 2 * dy] = ++cur;
	a[x + 2 * dx][y + 0 * dy] = ++cur;

	// vector<int> to_check;
	for (const auto& v : a) {
		for (int x : v) {
			printf("%d ", x);
			// to_check.push_back(x - 1);
		}
		printf("\n");
	}

	// assert(getRook(n, to_check) < getQueen(n, to_check));

	// const int n = 3;
	// vector<int> a(n * n);
	// iota(all(a), 0);
	// do {
	// 	if (getQueen(n, a) > getRook(n, a)) {
	// 		for (int i = 0; i < n * n; ++i) {
	// 			cout << a[i] + 1 << " ";
	// 			if (i % n == n - 1) {
	// 				cout << "\n";
	// 			}
	// 		}
	// 		break;
	// 	}
	// } while (next_permutation(all(a)));

	return 0;
}