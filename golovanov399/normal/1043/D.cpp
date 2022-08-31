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

	int n = nxt(), m = nxt();
	vector<int> p(n, -1);
	for (int i = 0; i < m; ++i) {
		int lst = -1;
		for (int j = 0; j < n; ++j) {
			int x = nxt() - 1;
			if (lst != -1) {
				if (p[lst] == -1) {
					p[lst] = x;
				} else if (p[lst] != x) {
					p[lst] = -2;
				}
			}
			lst = x;
		}
		p[lst] = -2;
	}

	vector<char> start(n, 1);
	for (int i = 0; i < n; ++i) {
		if (p[i] >= 0) {
			start[p[i]] = false;
		}
	}

	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		if (!start[i]) {
			continue;
		}
		int len = 0;
		for (int v = i; v >= 0; v = p[v]) {
			++len;
		}
		ans += 1ll * len * (len + 1) / 2;
	}

	cout << ans << "\n";

	return 0;
}