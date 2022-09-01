#include <bits/stdc++.h>
using namespace std;
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define pb push_back

int n,q,a[50005],up[50005],UP[50005],dep[50005],cand[50005][64];
vector<int>edge[50005];

void dfs(int v,int u){
	up[v] = u;
	if(u == -1) dep[v] = 1;
	else dep[v] = dep[u]+1;
	for(int i=0;i<edge[v].size();i++){
		if(edge[v][i] == u) continue;
		dfs(edge[v][i],v);
	}
}
int main(){
	scanf("%d%d",&n,&q);
	repn(i,n) scanf("%d",&a[i]);
	rep(i,n-1){
		int a,b; scanf("%d%d",&a,&b);
		edge[a].pb(b);
		edge[b].pb(a);
	}
	dfs(1,-1);
	memset(cand,-1,sizeof(cand));
	for(int i=1;i<=n;i++){
		if(dep[i] < 1024) continue;
		int cur = 0;
		int pos = i;
		int zan = 1024;
		while(zan--){
			int V = a[pos]^cur;
			cand[i][V>>10] = max(cand[i][V>>10] ,V);
			pos = up[pos];
			cur++;
		}
		UP[i] = pos;
	}
	rep(i,q){
		int u,v; scanf("%d%d",&u,&v);
		int C = 0,ans = 0;
		while(dep[v]-dep[u]+1 >= 1024){
			rep(x,64){
				if(cand[v][x] == -1) continue;
				ans = max(ans,cand[v][x]^C);
			}
			C += 1024;
			v = UP[v];
		}
		while(dep[u] <= dep[v]){
			ans = max(ans,a[v]^C);
			v = up[v];
			C++;
		}
		printf("%d\n",ans);
	}
}