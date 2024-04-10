#include<bits/stdc++.h>
const int N=300005;
std::vector<int> e[N];int f[N],Fa[N];bool mark[N];
void dfs(int x,int fa){Fa[x]=fa;for(auto v:e[x])if(v!=fa)dfs(v,x),f[x]^=f[v]+1;}
int main(){
	int n;std::cin>>n;for(int i=1,x,y;i<n;++i)std::cin>>x>>y,e[x].push_back(y),e[y].push_back(x);
	dfs(1,0);int ans=f[1];putchar(ans?'1':'2'),mark[1]=1;
	for(int i=2;i<=n;++i){
		for(int u=i;!mark[u];u=Fa[u]){
			ans^=1,mark[u]=1;if(mark[Fa[u]])ans^=f[u]+1;
			for(auto v:e[u])if(v!=Fa[u]&&!mark[v])ans^=f[v]+1;
		}
		putchar(ans?'1':'2');
	}
	return 0;
}