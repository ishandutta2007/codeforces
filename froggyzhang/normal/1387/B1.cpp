#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 100010
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,amn[N],amx[N];
ll mx,mn;
vector<int> G[N];
namespace Solve_mn{
	int p[N],ans,f[N];
	void dfs(int u){
		for(auto v:G[u]){
			if(v==f[u])continue;
			f[v]=u;
			dfs(v);
		}
		if(f[u]&&p[u]==u&&p[f[u]]==f[u]){
			swap(p[u],p[f[u]]);
			mn+=2;
		}
	}
	void Solve(){
		for(int i=1;i<=n;++i)p[i]=i;
		dfs(1);
		for(int i=2;i<=n;++i){
			if(p[i]==i)swap(p[i],p[f[i]]),mn+=2;
		}
		if(p[1]==1)swap(p[1],p[G[1][0]]),mn+=2;
		for(int i=1;i<=n;++i){
			amn[p[i]]=i;
		}
	}
}
namespace Solve_mx{
	int siz[N],root,maxp[N];
	int a[N],b[N],num;
	void dfs(int u,int fa){
		siz[u]=1;
		for(auto v:G[u]){
			if(v==fa)continue;
			dfs(v,u);
			siz[u]+=siz[v];
			maxp[u]=max(maxp[u],siz[v]);
		}
		mx+=2*min(siz[u],n-siz[u]);
		maxp[u]=max(maxp[u],n-siz[u]);
		if(!root||maxp[u]<maxp[root]){
			root=u;
		}
		++num;
		a[num]=b[num]=u;
	}
	void Solve(){
		dfs(1,0);
		rotate(b+1,b+maxp[root]+1,b+n+1);
		for(int i=1;i<=n;++i){
			amx[a[i]]=b[i];
		}
	}	
}
int main(){
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	Solve_mn::Solve();
//	Solve_mx::Solve();
	printf("%lld\n",mn);
	for(int i=1;i<=n;++i){
		printf("%d ",amn[i]);
	}
	printf("\n");
	return 0;
}