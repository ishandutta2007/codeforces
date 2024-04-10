#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 333333;
vector<int> a[N];
char used[N];
int level[N];
int par[N];

vector<int> st;
int min_path_length;
int min_cycles_cnt;
vector<vector<int>> cycles;
vector<int> on_level[N];

void dfs(int v) {
	used[v] = 1;
	st.push_back(v);

	if ((int)st.size() >= min_path_length) {
		printf("PATH\n%d\n", (int)st.size());
		for (int x : st) {
			printf("%d ", x + 1);
		}
		printf("\n");
		exit(0);
	}

	for (int x : a[v]) {
		if (used[x]) {
			continue;
		}
		level[x] = level[v] + 1;
		par[x] = v;
		dfs(x);
	}

	on_level[level[v]].push_back(v);

	st.pop_back();
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), m = nxt(), k = nxt();
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	min_path_length = (n + k - 1) / k;
	min_cycles_cnt = k;

	memset(par, -1, sizeof(par));

	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			dfs(i);
		}
	}

	int lvl = 0;
	for (int i = 0; i < n; ++i) {
		if (on_level[i].size() > on_level[lvl].size()) {
			lvl = i;
		}
	}

	assert((int)on_level[lvl].size() >= k);

	for (int v : on_level[lvl]) {
		int leaf = v;
		while (true) {
			int x = a[leaf][0];
			for (int y : a[leaf]) {
				if (level[y] >= level[x]) {
					x = y;
				}
			}
			if (level[x] > level[leaf]) {
				leaf = x;
			} else {
				break;
			}
		}
		int nb[2] = {-1, -1};
		for (int i = 0, j = 0; i < 2; ++i, ++j) {
			while (a[leaf][j] == par[leaf]) {
				++j;
			}
			nb[i] = a[leaf][j];
		}
		cycles.push_back({leaf});
		if ((level[leaf] - level[nb[0]]) % 3 != 2) {
			for (int w = leaf; w != nb[0]; w = par[w]) {
				cycles.back().push_back(par[w]);
			}
		} else if ((level[leaf] - level[nb[1]]) % 3 != 2) {
			for (int w = leaf; w != nb[1]; w = par[w]) {
				cycles.back().push_back(par[w]);
			}
		} else {
			if (level[nb[0]] > level[nb[1]]) {
				swap(nb[0], nb[1]);
			}
			cycles.back().push_back(nb[1]);
			for (int w = nb[1]; w != nb[0]; w = par[w]) {
				cycles.back().push_back(par[w]);
			}
		}

		if ((int)cycles.size() == min_cycles_cnt) {
			break;
		}
	}

	if ((int)cycles.size() < min_cycles_cnt) {
		printf("-1\n");
		return 0;
	}

	printf("CYCLES\n");
	for (const auto& v : cycles) {
		printf("%d\n", (int)v.size());
		for (int x : v) {
			printf("%d ", x + 1);
		}
		printf("\n");
	}

	return 0;
}