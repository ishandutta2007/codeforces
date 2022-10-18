#include <bits/stdc++.h>
#define maxn 1000005
int depth[maxn]={0},d[maxn]={0},n,k,u,v,ans=0,degr[maxn]={0};
std::vector<int>conj[maxn];

void dfs(int u,int f){
	depth[u]=depth[f]+1;
	d[u]=0;int flag=0;
	for(int i=0;i<conj[u].size();++i){
		int v=conj[u][i];
		if (v==f)continue;
		dfs(v,u);
		if (d[v]+d[u]<=k+2*depth[u])d[u]=std::max(d[u],d[v]);
		else {ans++;d[u]=std::min(d[u],d[v]);}
		flag=1;
	}if (!flag)d[u]=depth[u];
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		conj[u].push_back(v);conj[v].push_back(u);
		degr[u]++;degr[v]++;
	}for(int i=1;i<=n;++i){
		if (degr[i]==1)continue;
		dfs(i,0);if (d[i])ans++;
		break;
	}
	printf("%d",ans);
	return 0;
}