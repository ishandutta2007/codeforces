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

const int N = 333333;
vector<int> a[N];
int c[N];

void dfs(int v, int p = -1) {
	for (int x : a[v]) {
		if (x == p) {
			continue;
		}
		c[x] = c[v] ^ 1;
		dfs(x, v);
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
	dfs(0);
	int cnt[2] = {0, 0};
	for (int i = 0; i < n; ++i) {
		cnt[c[i]] += 1;
	}
	cout << min(cnt[0], cnt[1]) - 1 << "\n";

	return 0;
}