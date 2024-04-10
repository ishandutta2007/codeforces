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

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt() - 2;
	}

	if (n == 1) {
		printf("%d\n", a[0] + 2);
		for (int i = 0; i < a[0] + 2; ++i) {
			printf("%d ", i + 1);
		}
		printf("\n");
		return 0;
	}
	vector<pair<int, int>> ar(n);
	for (int i = 0; i < n; ++i) {
		ar[i] = {a[i], i};
	}
	sort(all(ar));
	reverse(all(ar));

	int tr = accumulate(all(a), 0);
	// x + y = tr
	// 2 + x - y in {3, 4}
	// x - y in {1, 2}
	// 2x in {tr + 1, tr + 2}
	int x = (tr + 2) / 2;
	x = max(x, ar[0].first);

	vector<vector<int>> answer(n);
	int vert = x + 2;
	printf("%d\n", vert);
	int cur = 2;
	map<pair<int, int>, int> M;
	M[{0, 1}] = 1;
	auto has_edge = [&](int x, int y) {
		if (x > y) {
			swap(x, y);
		}
		pair p{x, y};
		return M.count(p) && M[p] > 1;
	};
	deque<int> ids = {0, 1};
	for (int i = 0; i < n; ++i) {
		int add = min(x, ar[i].first);
		int sub = ar[i].first - add;
		while (has_edge(ids[0], ids[(int)ids.size() - 1 - sub])) {
			ids.push_back(ids[0]);
			ids.pop_front();
		}
		x -= add;
		answer[ar[i].second] = {ids[0]};
		while (sub--) {
			answer[ar[i].second].push_back(ids.back());
			ids.pop_back();
		}
		answer[ar[i].second].push_back(ids.back());
		while (add--) {
			answer[ar[i].second].push_back(cur);
			ids.push_back(cur++);
		}
		for (int j = 0; j < (int)answer[ar[i].second].size(); ++j) {
			int x = answer[ar[i].second][j];
			int y = answer[ar[i].second][(j + 1) % (int)answer[ar[i].second].size()];
			if (x > y) {
				swap(x, y);
			}
			M[{x, y}] += 1;
		}
	}

	for (auto v : answer) {
		for (int x : v) {
			printf("%d ", x + 1);
		}
		printf("\n");
	}

	return 0;
}