#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

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

const int N = 111111;
vector<int> a[N];
int color[N];
char used[N];
int curcolor = 0;
int lowlink[N];
#define index jshhlsdf
int index[N];
int idx = 0;
vector<int> st;
vector<vector<int>> comps;

void dfs(int v) {
	used[v] = 1;
	st.push_back(v);
	index[v] = lowlink[v] = idx++;
	for (int x : a[v]) {
		if (used[x] == 2) {
			continue;
		} else if (used[x] == 1) {
			lowlink[v] = min(lowlink[v], index[x]);
		} else {
			dfs(x);
			lowlink[v] = min(lowlink[v], lowlink[x]);
		}
	}
	if (index[v] == lowlink[v]) {
		comps.push_back({});
		int x = -1;
		while (x != v) {
			x = st.back();
			st.pop_back();
			used[x] = 2;
			comps.back().push_back(x);
			color[x] = curcolor;
		}
		++curcolor;
	}
}

int main() {
	int n = nxt(), m = nxt(), h = nxt();
	vector<int> c(n);
	for (int i = 0; i < n; ++i) {
		c[i] = nxt();
	}

	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		if ((c[u] + 1) % h == c[v]) {
			a[u].push_back(v);
		}
		swap(u, v);
		if ((c[u] + 1) % h == c[v]) {
			a[u].push_back(v);
		}
	}

	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			dfs(i);
		}
	}

	// for (int i = 0; i < n; ++i) {
	// 	cerr << i + 1 << ":";
	// 	for (int x : a[i]) {
	// 		cerr << " " << x + 1;
	// 	}
	// 	cerr << "\n";
	// }

	// for (int i = 0; i < n; ++i) {
	// 	cerr << color[i] << " ";
	// }
	// cerr << "\n";

	vector<int> out_deg(curcolor);
	for (int i = 0; i < n; ++i) {
		for (int x : a[i]) {
			if (color[x] != color[i]) {
				out_deg[color[i]] += 1;
			}
		}
	}
	int opt = -1;
	for (int i = 0; i < curcolor; ++i) {
		if (out_deg[i]) {
			continue;
		}
		if (opt == -1 || comps[i].size() < comps[opt].size()) {
			opt = i;
		}
	}
	printf("%d\n", (int)comps[opt].size());
	for (int x : comps[opt]) {
		printf("%d ", x + 1);
	}
	printf("\n");

	return 0;
}