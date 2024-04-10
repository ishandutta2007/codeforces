#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 211111;
vector<int> a[N];
int sz[N];
int pr[N];
int old_pr[N];
int level[N];

void dfs(int v, int p = -1) {
	pr[v] = p;
	sz[v] = 1;
	for (int x : a[v]) {
		if (x == p) {
			continue;
		}
		dfs(x, v);
		sz[v] += sz[x];
	}
}

void dfs2(int v, int p = -1) {
	pr[v] = p;
	for (int x : a[v]) {
		if (x == p) {
			continue;
		}
		level[x] = level[v] + 1;
		dfs2(x, v);
	}
}

vector<vector<int>> ans;
void upd(int x, int y, int y_prime) {
	ans.push_back({x + 1, y + 1, y_prime + 1});
}

int main() {
	int n = nxt();
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	if (n == 1) {
		puts("0");
		return 0;
	}

	dfs(0);

	int cen = 0;
	while (2 * sz[cen] >= n) {
		int nx = -1;
		for (int x : a[cen]) {
			if (x == pr[cen]) {
				continue;
			}
			if (2 * sz[x] >= n) {
				nx = x;
			}
		}
		if (nx == -1) {
			break;
		} else {
			cen = nx;
		}
	}

	if (2 * sz[cen] == n) {
		int c2 = pr[cen];
		dfs2(cen, c2);
		dfs2(c2, cen);
	} else {
		dfs2(cen, -1);
	}

	memcpy(old_pr, pr, n * sizeof(int));

	vector<pair<int, int>> vs(n);
	for (int i = 0; i < n; ++i) {
		vs[i] = {level[i], i};
	}
	sort(all(vs));
	for (auto p : vs) {
		int v = p.second;
		if (level[v] >= 3) {
			pr[v] = pr[pr[v]];
		}
	}
	reverse(all(vs));

	vector<int> cur(n, -1);
	for (auto p : vs) {
		if (p.first == 1) {
			cur[p.second] = p.second;
		}
	}

	// cerr << cen + 1 << "\n";
	// for (int i = 0; i < n; ++i) {
	// 	cerr << level[i] << " ";
	// }
	// cerr << "\n";
	// for (int i = 0; i < n; ++i) {
	// 	cerr << pr[i] + 1 << " ";
	// }
	// cerr << "\n";

	for (auto p : vs) {
		if (p.first > 2) {
			int pp = pr[p.second];
			upd(pr[pp], cur[pp], p.second);
			upd(p.second, old_pr[p.second], pp);
			cur[pp] = p.second;
		}
	}

	for (int i = 0; i < n; ++i) {
		if (cur[i] == -1 || cur[i] == i) {
			continue;
		}

		upd(pr[i], cur[i], i);
	}

	printf("%d\n", (int)ans.size());
	for (auto v : ans) {
		for (auto x : v) {
			printf("%d ", x);
		}
		printf("\n");
	}

	return 0;
}