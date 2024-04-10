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

const int N = 101111;
list<int> up[N];
int cnt_down[N];

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), m = nxt();
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		if (u > v) {
			swap(u, v);
		}
		up[u].push_back(v);
		cnt_down[v] += 1;
	}

	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += 1ll * cnt_down[i] * (int)up[i].size();
	}
	printf("%lld\n", ans);

	int q = nxt();
	while (q--) {
		int v = nxt() - 1;
		ans -= 1ll * cnt_down[v] * (int)up[v].size();	// v was b
		for (int x : up[v]) {
			ans -= (int)up[x].size();	// v was c
			cnt_down[x] -= 1;
			ans += cnt_down[x];	// v became a
			up[x].push_back(v);
		}
		cnt_down[v] += (int)up[v].size();
		up[v].clear();
		printf("%lld\n", ans);
	}

	return 0;
}