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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int xx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
const int yy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

vector<pair<int, int>> solve(int n) {
	vector<pair<int, int>> res;
	if (n < 16) {
		for (int i = 0; i < n; ++i) {
			res.push_back({i / 2, i % 2});
		}
	} /*else if (n < 50) {
		res.push_back({0, 0});
		res.push_back({1, 1});
		for (int i = 0; i < n - 2; ++i) {
			int x = i / 2 / 2, y = i / 2 % 2;
			x += 2;
			if (i % 2) {
				swap(x, y);
			}
			res.push_back({x, y});
		}
	}*/ else if (n < 100) {
		for (int i = 4; i < n - n % 2 + 4; ++i) {
			int x = i % 2;
			int y = 1 - x;
			x += (i - 4) / 8 + 1;
			y += (i - 4) / 8 + 1;
			for (int j = 0; j < i / 2 % 4; ++j) {
				swap(x, y);
				x = -x;
			}
			res.push_back({x, y});
		}
		if (n % 2 == 1) {
			res.push_back({(n + 3) / 8, (n + 3) / 8});
		}
	} else {
		const int k = (n < 100) ? 0 : n / 30;
		n += k;
		for (int i = 4; i < n - n % 2 + 4; ++i) {
			int x = i % 2;
			int y = 1 - x;
			x += (i - 4) / 8 + 1;
			y += (i - 4) / 8 + 1;
			for (int j = 0; j < i / 2 % 4; ++j) {
				swap(x, y);
				x = -x;
			}
			res.push_back({x, y});
		}
		if (n % 2 == 1) {
			res.push_back({(n + 6 + k) / 8, (n + 6 + k) / 8});
		}
		for (int i = 0; i < k; ++i) {
			res.erase(res.begin() + n / 2 + 4 * i);
		}
		n -= k;
	}
	make_unique(res);
	while ((int)res.size() < n) {
		auto p = res.back();
		p.first += 1;
		res.push_back(p);
	}
	return res;
}

void check(int n, const vector<pair<int, int>>& a) {
	assert((int)a.size() == n);
	int need = n * n / 10;
	map<pair<int, int>, int> M;
	vector<pair<int, int>> st;
	for (auto p : a) {
		M[p] = 5;
		st.push_back(p);
	}
	auto add = [&](int x, int y) {
		M[{x, y}] += 1;
		if (M[{x, y}] == 4) {
			st.push_back({x, y});
		}
	};
	int cnt = 0;
	while (!st.empty()) {
		auto p = st.back();
		st.pop_back();
		++cnt;
		for (int i = 0; i < 8; ++i) {
			add(p.first + xx[i], p.second + yy[i]);
		}
		if (cnt >= need) {
			break;
		}
	}
	if (cnt < need) {
		for (auto p : a) {
			cout << p.first << " " << p.second << " ";
		}
		cout << "red ";
		for (auto [p, v] : M) {
			if (v >= 4 && find(all(a), p) == a.end()) {
				cout << p.first << " " << p.second << " ";
			}
		}
		cout << "\n";
		cerr << "n = " << n << ", cnt = " << cnt << ", need = " << need << "\n";
		exit(0);
	} else {
		cerr << n << " is ok\n";
	}
}

int main() {
#if 0
	for (int n = 1; n <= 1000; ++n) {
		auto res = solve(n);
		check(n, res);
	}
#else
	auto res = solve(nxt());
	for (auto p : res) {
		cout << p.first << " " << p.second << "\n";
	}
#endif

	return 0;
}