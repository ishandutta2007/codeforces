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

struct Edge {
	int to;
	int type;
};

const int N = 111111;
vector<Edge> a[N];

void dfs(vector<int>& p, vector<int>& tin, vector<int>& tout, int& timer, int mask, int v) {
	tin[v] = timer++;
	for (auto e : a[v]) {
		if (e.type & mask) {
			p[e.to] = p[v];
			dfs(p, tin, tout, timer, mask, e.to);
		}
	}
	tout[v] = timer++;
}

bool is_upper(const vector<int>& tin, const vector<int>& tout, int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int main() {
	int n = nxt();
	for (int i = 0; i < n; ++i) {
		int p = nxt(), type = nxt();
		if (p == -1) {
			continue;
		}
		--p;
		type = 1 << type;
		a[p].push_back({i, type});
	}

	vector<int> p[2], tin[2], tout[2];
	int timer[2];

	for (int j = 0; j < 2; ++j) {
		p[j].assign(n, -1);
		tin[j].assign(n, 0);
		tout[j].assign(n, 0);
		timer[j] = 0;
		int type = 1 << j;

		for (int i = 0; i < n; ++i) {
			if (p[j][i] == -1) {
				p[j][i] = i;
				dfs(p[j], tin[j], tout[j], timer[j], type, i);
			}
		}
	}

	int q = nxt();
	while (q--) {
		int t = nxt() - 1, u = nxt() - 1, v = nxt() - 1;
		if (is_upper(tin[0], tout[0], v, u) ||
			is_upper(tin[1], tout[1], v, u)) {
			puts("NO");
			continue;
		} else if (t == 0) {
			puts(is_upper(tin[0], tout[0], u, v) ? "YES" : "NO");
		} else {
			puts(is_upper(tin[0], tout[0], p[1][v], u) ||
				 is_upper(tin[1], tout[1], p[0][u], v) ? "YES" : "NO");
		}
	}

	return 0;
}