#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<n;i++)
#define repn(i, n) for(int i=1;i<=n;i++)
typedef pair<int, int> P;
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
const int INF = 100000000;

int ans = INF, ret[1000005], n, q, las, r;
vector<int>edge[1000005];

void dfs(int v, int u, int mn){
	mn = min(mn, v);
	ret[v] = mn;
	rep(i, edge[v].size()){
		if(edge[v][i] != u) dfs(edge[v][i], v, mn);
	}
}
int main(){
	scanf("%d%d", &n, &q);
	rep(i, n-1){
		int a, b; scanf("%d%d", &a, &b);
		edge[a].pb(b);
		edge[b].pb(a);
	}
	int aa; scanf("%d%d", &aa, &r);
	r = (r+las)%n+1;
	
	dfs(r, -1, INF);
	rep(i, q-1){
		int ty, x; scanf("%d%d", &ty, &x);
		x = (x+las)%n+1;
		if(ty == 1){
			ans = min(ans, ret[x]);
		}
		else{
			printf("%d\n", min(ans, ret[x]));
			las = min(ans, ret[x]);
		}
	}
}