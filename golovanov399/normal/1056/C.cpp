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

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), m = nxt();
	vector<int> opp(2 * n, -1);
	vector<int> a(2 * n);
	for (int i = 0; i < 2 * n; ++i) {
		a[i] = nxt();
	}
	for (int i = 0; i < m; ++i) {
		int x = nxt() - 1, y = nxt() - 1;
		opp[x] = y;
		opp[y] = x;
	}

	int t = nxt();
	vector<char> picked(2 * n, 0);

	auto readTurn = [&]() {
		int idx = nxt() - 1;
		assert(!picked[idx]);
		picked[idx] = 1;
	};

	auto pick = [&](int id) {
		cout << id + 1 << endl;
		picked[id] = 1;
	};

	auto move = [&]() {
		for (int i = 0; i < 2 * n; ++i) {
			if (opp[i] != -1 && picked[i] != picked[opp[i]]) {
				pick(picked[i] ? opp[i] : i);
				return;
			}
		}

		int diff = 0;
		int opt = -1;
		for (int i = 0; i < 2 * n; ++i) {
			if (opp[i] != -1 && !picked[i]) {
				if (a[opp[i]] - a[i] > diff) {
					diff = a[opp[i]] - a[i];
					opt = i;
				}
			}
		}

		if (opt > -1) {
			pick(opp[opt]);
			return;
		}

		opt = -1;
		for (int i = 0; i < 2 * n; ++i) {
			if (picked[i]) {
				continue;
			}
			if (opt == -1 || a[i] > a[opt]) {
				opt = i;
			}
		}
		assert(opt > -1);
		pick(opt);
	};

	for (int i = 0; i < n; ++i) {
		if (t == 2) {
			readTurn();
			move();
		} else {
			move();
			readTurn();
		}
	}

	return 0;
}