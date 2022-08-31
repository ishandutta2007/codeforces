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

long long sqr(long long x) {
	return x * x;
}

long long dist(const pair<int, int>& p, const pair<int, int>& q) {
	return sqr(p.first - q.first) + sqr(p.second - q.second);
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<pair<int, int>> pts(n);
	for (int i = 0; i < n; ++i) {
		pts[i].first = nxt();
		pts[i].second = nxt();
	}
	vector<int> ans(n);
	ans[0] = 0;
	vector<char> used(n);
	for (int i = 1; i < n; ++i) {
		int last = ans[i - 1];
		used[last] = true;
		int nx = -1;
		for (int j = 0; j < n; ++j) {
			if (used[j]) {
				continue;
			}
			if (nx == -1 || dist(pts[last], pts[j]) > dist(pts[last], pts[nx])) {
				nx = j;
			}
		}
		ans[i] = nx;
	}
	for (int x : ans) {
		cout << x + 1 << " ";
	}
	cout << "\n";

	return 0;
}