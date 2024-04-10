#include<bits/stdc++.h>
using namespace std;
#define N 200020
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
int T,n,siz[N];
int son[N],f[N],dep[N],top[N];
ll ans[N];
vector<int> G[N];
void dfs1(int u){
	siz[u]=1;son[u]=0;
	for(auto v:G[u]){
		if(v==f[u])continue;
		dep[v]=dep[u]+1;
		f[v]=u;
		dfs1(v);
		if(siz[v]>siz[son[u]])son[u]=v;
		siz[u]+=siz[v];
	}
}
void dfs2(int u,int topf){
	top[u]=topf;
	if(!son[u])return;
	dfs2(son[u],topf);
	for(auto v:G[u]){
		if(v==f[u]||v==son[u])continue;
		dfs2(v,v);
	}
}
inline int LCA(int x,int y){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
inline int Get(int x,int y){
	while(top[x]^top[y]){
		if(f[top[x]]==y)return top[x];
		x=f[top[x]];
	}
	return son[y];
}
inline int Dis(int x,int y){
	return dep[x]+dep[y]-2*dep[LCA(x,y)];
}
inline int On(int x,int y,int z){
	return Dis(x,y)==Dis(x,z)+Dis(y,z);
}
void Solve(){
	n=read();
	for(int i=1;i<=n;++i)G[i].clear(),ans[i]=0;
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		++u,++v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1);
	dfs2(1,1);
	ans[1]=ans[0]=1LL*n*(n-1)/2;
	for(auto v:G[1])ans[1]-=1LL*siz[v]*(siz[v]-1)/2;
	int X=1,Y=1;
	for(int i=2;i<=n;++i){
		if(On(X,Y,i)){
			
		}
		else if(On(X,i,Y))Y=i;
		else if(On(Y,i,X))X=i;
		else break;
		if(dep[X]<dep[Y])swap(X,Y);
		if(LCA(X,Y)==Y){
			ans[i]=1LL*siz[X]*(n-siz[Get(X,Y)]);	
		}
		else{
			ans[i]=1LL*siz[X]*siz[Y];
		}
	}
	ans[n+1]=0;
	for(int i=0;i<=n;++i){	
		printf("%lld ",ans[i]-ans[i+1]);
	}
	printf("\n");
}
int main(){
	int cnt=0;
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}