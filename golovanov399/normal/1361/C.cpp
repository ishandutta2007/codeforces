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

struct Edge {
	int to, id;
};

const int maxm = 555555;
const int maxn = 1 << 20;

bool usedEdge[maxm];
vector<Edge> g[maxn];
int ptr[maxn];

vector<int> cycle;
void eulerCycle(int u) {
	while (ptr[u] < (int)g[u].size() && usedEdge[abs(g[u][ptr[u]].id)]) {
		++ptr[u];
	}
	if (ptr[u] == (int)g[u].size()) {
		return;
	}
	const Edge &e = g[u][ptr[u]];
	usedEdge[abs(e.id)] = true;
	eulerCycle(e.to);
	cycle.push_back(e.id);
	eulerCycle(u);
}

bool check(const vector<pair<int, int>>& a, int m) {
	const int M = (1 << m) - 1;
	for (int i = 0; i <= M; ++i) {
		g[i].clear();
	}
	memset(usedEdge, 0, sizeof(usedEdge));
	memset(ptr, 0, sizeof(ptr));
	for (int i = 0; i < (int)a.size(); ++i) {
		g[a[i].first & M].push_back({a[i].second & M, i + 1});
		g[a[i].second & M].push_back({a[i].first & M, -i - 1});
	}
	for (int i = 0; i < M; ++i) {
		if (g[i].size() & 1) {
			return false;
		}
	}
	cycle.clear();
	eulerCycle(a[0].first & M);
	return cycle.size() == a.size();
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		a[i].first = nxt();
		a[i].second = nxt();
	}

	int l = 0, r = 21;
	while (r > l + 1) {
		int m = (l + r) / 2;
		if (check(a, m)) {
			l = m;
		} else {
			r = m;
		}
	}
	assert(check(a, l));
	printf("%d\n", l);
	for (int x : cycle) {
		if (x > 0) {
			printf("%d %d ", 2 * x, 2 * x - 1);
		} else {
			printf("%d %d ", 2 * (-x) - 1, 2 * (-x));
		}
	}
	printf("\n");

	return 0;
}