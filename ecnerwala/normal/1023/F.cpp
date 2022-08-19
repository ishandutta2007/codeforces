#define NDEBUG
#include <bits/stdc++.h>
using namespace std;

namespace dsds {
template <int N> class ds {
	int par[N+1];
public:
	void reset() { memset(par, 0, sizeof(par)); }
	int get(int a) { return par[a] == 0 ? a : (par[a] = get(par[a])); }
	// merge a into b
	bool merge(int a, int b) {
		a = get(a), b = get(b);
		if (a == b) return false;
		par[a] = b;
		return true;
	}
};
}

const int MAXN = 6e5;
int N;
dsds::ds<MAXN> ds, ds2;
vector<int> adj[MAXN];
int depth[MAXN];
int par[MAXN];

void dfs(int cur) {
	for (int nxt : adj[cur]) {
		if (nxt == par[cur]) continue;
		depth[nxt] = depth[cur] + 1;
		par[nxt] = cur;
		dfs(nxt);
	}
}

void dfs() {
	dfs(1);
}

const int MAXK = MAXN - 1;
int K;

const int MAXM = 6e5;
int M;
pair<pair<int, int>, int> F[MAXM];

int main() {
	scanf("%d %d %d", &N, &K, &M);
	long long res = 0;
	
	for (int i = 0; i < K; i++) {
		int a,b; scanf("%d %d", &a, &b);
		int r = ds.merge(a,b);
		assert(r);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < M; i++) {
		int a,b,w; scanf("%d %d %d", &a, &b, &w);
		F[i].first = make_pair(a,b);
		F[i].second = w;
		if (ds.merge(a,b)) {
			adj[a].push_back(b);
			adj[b].push_back(a);
			res -= w;
		}
	}
	
	dfs();
	
	int cnt = N-1;
	
	for (int i = 0; i < M; i++) {
		int a = F[i].first.first, b = F[i].first.second;
		int w = F[i].second;
		a = ds2.get(a), b = ds2.get(b);
		while (a != b) {
			if (depth[a] < depth[b]) {
				swap(a,b);
			}
			res += w;
			cnt --;
			bool r = ds2.merge(a, par[a]);
			assert(r);
			a = ds2.get(a);
		}
	}
	if (cnt) {
		res = -1;
	}
	printf("%"PRId64"\n", res);
	return 0;
}