#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;

const int ms = 5005, me = 5005, sigma = 26;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9+7;
typedef vector<int> vi;

int adj[ms], to[me], ant[me], z, n;

void clear() {
    memset(adj, -1, sizeof adj);
    z = 0;
}

void add(int u, int v) {
    to[z] = v;
    ant[z] = adj[u];
    adj[u] = z++;
}

int vis[ms], topo[ms], topoLen;

void dfs(int v) {
    if(vis[v]) return;
    vis[v] = true;
    for(int i = adj[v]; i > -1; i = ant[i]) dfs(to[i]);
	assert(topoLen < 5000);
    topo[topoLen++] = v;
}

void toposort() {
    memset(vis, 0, sizeof vis);
    for(int i = 1; i <= n; i++) dfs(i);
    reverse(topo, topo + n);
}

void dfs2(int v) {
    if(vis[v]) return;
    vis[v] = true;
    for(int i = adj[v]; i > -1; i = ant[i]) dfs2(to[i]);
}

int solve(int s) {
	toposort();
	memset(vis, 0, sizeof vis);
	dfs2(s);
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int k = topo[i];
		//cout << k << endl;
		if(!vis[k]) {
			dfs2(k);
			ans++;
		}
	}
	return ans;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int m, s;
	cin >> n >> m >> s;
	clear();
	while(m--) {
		int u, v;
		cin >> u >> v;
		add(u, v);
	}
	cout << solve(s) << endl;
	return 0;
}