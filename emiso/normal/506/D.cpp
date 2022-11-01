#include <bits/stdc++.h>
#define MN 100010
#define SQN 200

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef long long ll;

const ll TIME = chrono::high_resolution_clock::now().time_since_epoch().count();
const ll SEED = (ll)(new ll);
const ll RANDOM = TIME ^ SEED;
const ll MOD = (int)1e9+7;
const ll MUL = (int)1e6+3;
struct chash{
    ll operator()(ll x) const { return std::hash<ll>{}((x ^ RANDOM) % MOD * MUL); }
};

int n, m, a, b, c, deg[MN], q;

gp_hash_table<int, vector<int>, chash> adj[MN];
set<int> colours[MN];

struct query { int u, v, id; };
vector <query> v, brute[MN];
long long ans[MN];

// ----------------
int waycount[MN], lastidx[MN], foo;
void dfs(int node, int version, int colour) {
    if(lastidx[node] == version) return;
    lastidx[node] = version;
    waycount[node]++;
    for(int v : adj[colour][node])
        dfs(v, version, colour);
}
// ----------------
struct union_find {
    gp_hash_table<int, int, chash> parent, rnk;

    int read(int x) {
        auto p = parent.find(x);
        if(p == parent.end()) return parent[x] = x;
        if((*p).second == x) return x;
        else return (*p).second = read((*p).second);
    }

    int get_rank(int x) {
        auto r = rnk.find(x);
        if(r == rnk.end()) return 0;
        else return (*r).second;
    }

    void merge(int x, int y) {
        x = read(x), y = read(y);
        if(x == y) return;

        int rx = get_rank(x), ry = get_rank(y);
        if(rx < ry) swap(x, y);
        parent[y] = x;
        if(rx == ry) rnk[x]++;
    }
};
union_find dsu[MN];
// ----------------

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		adj[c][a].push_back(b);
		adj[c][b].push_back(a);
		deg[a]++;
		deg[b]++;
		colours[a].insert(c);
		colours[b].insert(c);
		dsu[c].merge(a, b);
	}

    scanf("%d", &q);
	for(int i = 0; i < q; i++) {
		scanf("%d %d", &a, &b);
		if(deg[a] > deg[b]) swap(a, b);

        if(deg[b] >= SQN) brute[b].push_back({a, a, i});
		else v.push_back({a, b, i});
	}

	for(int i = 1; i <= n; i++) {
        if(deg[i] < SQN) continue;
        memset(waycount, 0, sizeof waycount);
        for(int x : colours[i]) dfs(i, ++foo, x);
        for(query Q : brute[i]) ans[Q.id] += waycount[Q.v];
	}

	for(query Q : v)
        for(int x : colours[Q.u])
            if(dsu[x].read(Q.u) == dsu[x].read(Q.v))
                ans[Q.id]++;

	for(int i = 0; i < q; i++)
		printf("%lld\n", ans[i]);
	return 0;
}