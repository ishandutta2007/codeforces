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

const int N = 222222;
set<int> a[N];
int ans;
int k;

char used[N];

void upd(int v) {
	used[v] = 1;
	--ans;
	for (int x : a[v]) {
		a[x].erase(v);
		if ((int)a[x].size() < k && !used[x]) {
			upd(x);
		}
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), m = nxt(); k = nxt();
	vector<pair<int, int>> ed;
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].insert(v);
		a[v].insert(u);
		ed.push_back({u, v});
	}

	ans = n;

	for (int i = 0; i < n; ++i) {
		if ((int)a[i].size() < k && !used[i]) {
			upd(i);
		}
	}

	vector<int> res;
	reverse(all(ed));
	for (auto [u, v] : ed) {
		res.push_back(ans);
		a[u].erase(v);
		a[v].erase(u);
		if ((int)a[u].size() < k && !used[u]) {
			upd(u);
		}
		if ((int)a[v].size() < k && !used[v]) {
			upd(v);
		}
	}

	reverse(all(res));
	for (int x : res) {
		printf("%d\n", x);
	}

	return 0;
}