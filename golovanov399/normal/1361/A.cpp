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

const int N = 555555;
vector<int> a[N];
vector<int> by_t[N];
int last[N];

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), m = nxt();
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 0; i < n; ++i) {
		by_t[nxt()].push_back(i);
	}

	vector<int> ans;
	set<int> can_be;
	for (int i = 0; i < n; ++i) {
		can_be.insert(i);
	}
	for (int t = 1; t <= n; ++t) {
		set<int> new_can_be;
		for (int v : by_t[t]) {
			if (!can_be.count(v) || last[v] == t) {
				cout << "-1\n";
				return 0;
			}
			ans.push_back(v);
			for (int x : a[v]) {
				if (can_be.count(x)) {
					new_can_be.insert(x);
				}
				last[x] = t;
			}
		}
		can_be.swap(new_can_be);
	}

	for (int x : ans) {
		printf("%d ", x + 1);
	}
	printf("\n");

	return 0;
}