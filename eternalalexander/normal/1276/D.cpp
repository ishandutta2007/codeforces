#include <bits/stdc++.h>
#define ll long long
#define pii std::pair<int,int>
const int mod=998244353;
int n,u,v;
ll f[200005][4];
std::vector<pii>E[200005];

void dfs(int u,int fa){
	f[u][0]=f[u][3]=1;
	for(int i=0,s=1;i<E[u].size();++i){
		int v=E[u][i].second;
		if(v==fa){s++;continue;}
		dfs(v,u);
		f[u][s]=(f[u][0]*(f[v][2]+f[v][0])+f[u][s]*(f[v][0]+f[v][1]+f[v][2]))%mod;
		f[u][3-s]=(f[u][3-s]*(f[v][1]+(s==2?f[v][0]+f[v][2]:f[v][3])))%mod;
		f[u][0]=f[u][0]*(f[v][1]+f[v][3])%mod;
		if(s==1)f[u][3]=f[u][3]*(f[v][1]+f[v][3])%mod;
		else f[u][3]=f[u][3]*(f[v][0]+f[v][1]+f[v][2])%mod;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		E[u].push_back(pii(i,v));
		E[v].push_back(pii(i,u));
	}for(int i=1;i<=n;++i)std::sort(E[i].begin(),E[i].end());
	dfs(1,0);
	std::cout<<(f[1][0]+f[1][1]+f[1][2])%mod;
	return 0;
}