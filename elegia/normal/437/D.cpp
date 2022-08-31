#include <cstdio>

#include <algorithm>
#include <vector>
#include <functional>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

struct Node {
	int w, u;
	
	bool operator<(const Node& rhs) const { return w < rhs.w; }
	
	bool operator>(const Node& rhs) const { return w > rhs.w; }
};

typedef long long ll;

const int N = 100010;

int n, m;
ll ans;

int f[N], sz[N];
Node ver[N];

vector<int> adj[N];

int find(int x) { return f[x] == x ? f[x] : f[x] = find(f[x]); }

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &ver[i].w);
		ver[i].u = i;
	}
	while (m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	sort(ver + 1, ver + n + 1, greater<Node>());
	for (int i = 1; i <= n; ++i) {
		int u = ver[i].u;
		f[u] = u;
		sz[u] = 1;
		for (vector<int>::iterator it = adj[u].begin(); it != adj[u].end(); ++it)
			if (f[*it] != 0 && find(u) != find(*it)) {
				int fu = find(u), fv = find(*it);
				ans += (ll)ver[i].w * sz[fu] * sz[fv];
				sz[fu] += sz[fv];
				f[fv] = fu;
			}
	}
	printf("%.6lf\n", ans * 2.0D / n / (n - 1));
	return 0;
}