#include <bits/stdc++.h>
#define maxn 1000005
int f[maxn],fa[maxn],a[maxn],g[maxn],n,u,v;
std::vector<int>ch[maxn];
void dfs(int u,int pr){
	fa[u]=pr;f[u]=a[u];
	for(int v:ch[u]){
		if (v==pr)continue;
		dfs(v,u);
		if(f[v]>0)f[u]+=f[v];
	}
}

void dfs1(int u){
	g[u]=a[u];
	if(g[fa[u]]-std::max(0,f[u])>0)g[u]+=g[fa[u]]-std::max(0,f[u]);
	for(int v:ch[u])if(v!=fa[u])g[u]+=std::max(f[v],0);
	for(int v:ch[u]){
		if(v==fa[u])continue;
	//	g[u]+=std::max(f[v],0);
		dfs1(v);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if(a[i]==0)a[i]--;
	}for(int i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		ch[u].push_back(v);
		ch[v].push_back(u);
	}dfs(1,0);dfs1(1);
	//for(int i=1;i<=n;++i)printf("%d ",f[i]);printf("\n");
	//for(int i=1;i<=n;++i)printf("%d ",g[i]);printf("\n");
	for(int i=1;i<=n;++i)printf("%d ",f[i]+std::max(0,(fa[i]?g[fa[i]]-std::max(0,f[i]):0)));
	return 0;
}