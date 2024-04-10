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

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt() - 1;
		b[a[i]] = i;
	}

	vector<pair<int, int>> ans;

	auto myswap = [&](int i, int j) {
		swap(a[i], a[j]);
		swap(b[a[i]], b[a[j]]);
		ans.push_back({i, j});
	};

	auto swap_through_left = [&](int i, int j) {
		assert(i >= n / 2 && j >= n / 2);
		myswap(0, i);
		myswap(0, j);
		myswap(0, i);
	};

	auto swap_through_right = [&](int i, int j) {
		assert(i < n / 2 && j < n / 2);
		myswap(i, n - 1);
		myswap(j, n - 1);
		myswap(i, n - 1);
	};

	auto swap_through_both = [&](int i, int j) {
		if (i > j) {
			swap(i, j);
		}
		assert(i < n / 2 && j >= n / 2);
		myswap(i, n - 1);
		myswap(j, 0);
		myswap(0, n - 1);
		myswap(i, n - 1);
		myswap(j, 0);
	};

	auto general_swap = [&](int i, int j) {
		if (i > j) {
			swap(i, j);
		}
		if (i == j) {
			return;
		}
		if (i + n / 2 <= j) {
			myswap(i, j);
		} else if (j < n / 2) {
			swap_through_right(i, j);
		} else if (i >= n / 2) {
			swap_through_left(i, j);
		} else {
			swap_through_both(i, j);
		}
	};

	for (int i = 0; i < n; ++i) {
		general_swap(i, b[i]);
	}

	printf("%d\n", (int)ans.size());
	for (auto p : ans) {
		printf("%d %d\n", p.first + 1, p.second + 1);
	}

	return 0;
}