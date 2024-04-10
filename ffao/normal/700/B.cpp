#include <bits/stdc++.h>
using namespace std;
 

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)


int n,k;
long long ans;
int mark[210000];
vector<int> adj[210000];

void dfs(int v, int p, int d) {
	if (mark[v]) ans += d;

	for (int x : adj[v]) if (x != p) {
		dfs(x,v,d+1);
		mark[v] += mark[x];
	}
}

void dfs2(int v, int p, int d, int pairs) {
	int max_child = 0;
	for (int x : adj[v]) if (x != p) {
		max_child = max(max_child, mark[x]);
	}

	int can_make = min(mark[v]/2, mark[v]-max_child);
	int will_make = min(pairs, can_make);
	
	ans -= d * 2ll * will_make;
	pairs -= will_make;

	if (pairs) {
		for (int x : adj[v]) if (x != p && mark[x] == max_child) {
			dfs2(x, v, d+1, pairs);
			return;
		}
	}
}

void solve() {
	scanf("%d %d", &n, &k);

	REP(i,2*k) {
		int u;
		scanf("%d", &u); u--;
		mark[u]=1;
	}

	REP(i,n-1) {
		int u,v;
		scanf("%d %d", &u, &v); u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}	

	dfs(0,-1,0);
	dfs2(0,-1,0,k);

	printf("%lld\n", ans);
}


int main() {
    solve();
}