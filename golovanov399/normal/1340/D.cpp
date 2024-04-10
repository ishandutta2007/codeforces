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

const int N = 111111;
vector<int> a[N];
vector<pair<int, int>> ans;

void dfs(int v, int p, int x, int d) {
	ans.push_back({v, x});
	int total = (int)a[v].size() - 1;
	int le = total + 1 - x;
	int ri = d - x;
	int opt = max(le, 0);
	assert(opt <= ri);
	for (int to : a[v]) {
		if (to == p) {
			continue;
		}
		if (opt == 0) {
			x -= total + 1;
			ans.push_back({v, x});
		}
		dfs(to, v, x + 1, d);
		x += 1;
		ans.push_back({v, x});
		opt -= 1;
	}
	if (opt == 0) {
		x -= total + 1;
		ans.push_back({v, x});
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	int d = 0;
	for (int i = 0; i < n; ++i) {
		d = max(d, (int)a[i].size());
	}
	ans.push_back({0, 0});
	int cur = 0;
	for (int x : a[0]) {
		dfs(x, 0, cur + 1, d);
		++cur;
		ans.push_back({0, cur});
	}
	cout << ans.size() << "\n";
	for (auto [v, i] : ans) {
		cout << v + 1 << " " << i << "\n";
	}

	return 0;
}