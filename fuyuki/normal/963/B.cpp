#include<bits/stdc++.h>
using namespace std;
#define V inline void
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=2e5+1;
int n,x,siz[N];
vector<int>e[N];
V dfs0(int u,int fa=0){for(int v:e[u])if(v^fa)dfs0(v,u),siz[u]+=siz[v];}
V dfs1(int u,int fa=0){
	for(int v:e[u])if(v!=fa&&siz[v]%2==0)dfs1(v,u);
	cout<<u<<'\n';
	for(int v:e[u])if(v!=fa&&siz[v]%2==1)dfs1(v,u);
}
int main(){
	if(scanf("%d",&n),n%2==0)return cout<<"NO",0;
	FOR(i,1,n)if(scanf("%d",&x),siz[i]=1,x)e[x].push_back(i),e[i].push_back(x);
	return cout<<"YES\n",dfs0(1),dfs1(1),0;
}