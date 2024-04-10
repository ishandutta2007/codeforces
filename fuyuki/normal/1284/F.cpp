#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
const int N=3e5+1;
vector<int>e[N],E[N];
int n,f[20][N],dep[N],fa[N];
int find(int x){return !fa[x]?x:fa[x]=find(fa[x]);}
void init(int u){FOR(i,1,19)f[i][u]=f[i-1][f[i-1][u]];}
void dfs1(int u,int x){
	init(u);
	for(int v:e[u])if(v!=x)
		dep[v]=dep[u]+1,f[0][v]=u,dfs1(v,u);
}
void calc(int x,int y){
	x=find(x),y=find(y);
	ROF(i,19,0)if(dep[find(f[i][x])]>dep[y])
		x=find(f[i][x]);
	x=find(find(f[0][x])==y?x:y);
	cout<<x<<' '<<(fa[x]=f[0][x])<<' ';
}
void dfs2(int u,int x){
	for(int v:E[u])if(v!=x)
		dfs2(v,u),calc(u,v),cout<<u<<' '<<v<<'\n';
}
int main(){
	scanf("%d",&n),cout<<n-1<<'\n';int x,y;
	FOR(i,1,n-1)scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
	FOR(i,1,n-1)scanf("%d%d",&x,&y),E[x].push_back(y),E[y].push_back(x);
	dfs1(dep[1]=1,0),dfs2(1,0);
	return 0;
}