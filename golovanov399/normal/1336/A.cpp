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
vector<int> a[N];
int sz[N];
int lvl[N];

void dfs(int v, int p) {
	for (int x : a[v]) {
		if (x == p) {
			continue;
		}
		lvl[x] = lvl[v] + 1;
		dfs(x, v);
		sz[v] += sz[x];
	}
	++sz[v];
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), k = nxt();
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	dfs(0, 0);
	vector<int> ar(n);
	for (int i = 0; i < n; ++i) {
		ar[i] = lvl[i] - sz[i] + 1;
	}
	sort(all(ar));
	reverse(all(ar));
	cout << accumulate(ar.begin(), ar.begin() + k, 0ll) << "\n";

	return 0;
}