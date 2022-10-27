#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
vector<int> g[N];

int sz[N], bc[N], bl[N], dep[N], par[N];

void dfs1(int v, int p, int d = 0){
	sz[v] = 1; dep[v] = d; par[v] = p;
	for(int u : g[v]){
		if(u != p){
			dfs1(u, v, d + 1);
			sz[v] += sz[u];
		}
	}
}

void dfs2(int v, int p){
	bc[v] = -1; bl[v] = v;
	for(int u : g[v]){
		if(u != p){
			dfs2(u, v);
			if(bc[v] == -1 || sz[bc[v]] < sz[u]){
				bc[v] = u;
				bl[v] = bl[u];
			}
		}
	}
}

inline int query(char type, int v){
	cout << type << " " << v << endl;
	int x; cin >> x; return x;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	dfs1(1, 0); dfs2(1, 0);
	int cur = 1;
	int dist = query('d', 1);
	while(dist > 0){
		int leaf = bl[cur];
		int ndist = query('d', leaf);
		if(ndist == 0){
			cout << "! " << leaf << endl;
			exit(0);
		}
		if(ndist == dist + dep[leaf] - dep[cur]){
			cur = query('s', cur); dist--;
		}else{
			int lcadist = dist + dep[leaf] - dep[cur] - ndist;
			assert(lcadist >= 0 && lcadist%2 == 0);
			lcadist >>= 1;
			int lca = leaf;
			int climb = dep[leaf] - dep[cur] - lcadist;
			while(climb--){
				lca = par[lca];
			}
			dist -= lcadist;
			if(dist == 0){
				cout << "! " << lca << endl;
				exit(0);
			}else{
				cur = query('s', lca); dist--;
			}
		}
	}
	cout << "! " << cur << endl;

	return 0;
}