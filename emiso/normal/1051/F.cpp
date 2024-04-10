#include <bits/stdc++.h>

#define MN 100100
#define INF 1100000000000000ll

using namespace std;
typedef long long ll;

int n, m, a, b, q;

ll c;
vector<ll> dist[MN];

vector<pair<ll, ll> > adj[MN], adj2[MN];

void dijkstra(int no) {
    dist[no].resize(MN);
    for(int i = 0; i < MN; i++) dist[no][i] = INF;

    dist[no][no] = 0;

    priority_queue <pair<ll, ll> > pfila;
    pfila.push(pair<ll, ll>(-dist[no][no], no));

    while(!pfila.empty()) {
        ll dis = -pfila.top().first;
        int u = pfila.top().second;

        pfila.pop();
        if(dis > dist[no][u]) continue;

        for(int i = 0; i < adj2[u].size(); i++) {
            int v = adj2[u][i].first;
            if(dist[no][v] > dist[no][u] + adj2[u][i].second) {
                dist[no][v] = dist[no][u] + adj2[u][i].second;
                pfila.push(pair<ll, ll>(-dist[no][v], v));
            }
        }
    }
}

// ---------------------

int pai[MN], rnk[MN];
int find(int x) {
    if(x == pai[x]) return x;
    return pai[x] = find(pai[x]);
}

int merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return false;
    if(rnk[a] < rnk[b]) swap(a, b);
    pai[b] = a;
    if(rnk[a] == rnk[b]) rnk[a]++;
    return true;
}

// ---------------------

ll distT[MN];
int depth[MN];
int dp[MN][20];

void dfs(int u, int p = -1) {
    for (auto e : adj[u]) {
        int v = e.first;
        if (v != p) {
            distT[v] = e.second + distT[u];
            depth[v] = 1 + depth[u];
            dp[v][0] = u;
            dfs(v, u);
        }
    }
}

void build(int node) {
	dp[node][0] = node;
	for(int j = 1; (1 << j) < MN; j++)
		for(int i = 0; i < MN; i++)
			dp[i][j] = dp[dp[i][j-1]][j-1];
}

int query(int x, int y) {
	if(depth[x] < depth[y]) swap(x,y);

    int lg;
	for(lg = 1; (1 << lg) <= MN; lg++); lg--;

	for(int i = lg; i >= 0; i--)
		if(depth[x] - depth[y] >= (1 << i))
			x = dp[x][i];

	if(x == y) return x;

	for(int i = lg; i >= 0; i--)
		if(dp[x][i] != dp[y][i]) {
			x = dp[x][i];
			y = dp[y][i];
		}

	return dp[x][0];
}

set<int> used;
struct edg {
    ll a, b, c;
};
vector<edg> excess;

int main() {
    scanf("%d %d", &n, &m);

    for(int i = 0; i < MN; i++)
        pai[i] = i, rnk[i] = 0;

    for(int i=0; i<m; i++) {
        scanf("%d %d %lld", &a, &b, &c);

        if(merge(a, b)) {
            adj[a].push_back(make_pair(b, c));
            adj[b].push_back(make_pair(a, c));
        } else {
            used.insert(a);
            used.insert(b);
            excess.push_back({a, b, c});
        }
        adj2[a].push_back(make_pair(b, c));
        adj2[b].push_back(make_pair(a, c));
    }
    for(int v : used) {
        dijkstra(v);
    }

    dfs(1); build(1);
    scanf("%d", &q);
    for(int Q = 0; Q < q; Q++) {
        scanf("%d %d", &a, &b);
        ll ans = distT[a] + distT[b] - 2LL*distT[query(a,b)];

        for(edg e : excess) {
            ans = min(ans, dist[e.a][a] + dist[e.b][b] + e.c);
            ans = min(ans, dist[e.a][b] + dist[e.b][a] + e.c);
        }

        printf("%lld\n", ans);
    }

    return 0;
}