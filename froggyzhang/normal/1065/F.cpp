#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 1000100
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
int n,k,a[N],dp[N],up[N],dep[N],f[N];
int st[N],top;
vector<int> G[N],leaf;
void dfs0(int u){
	for(auto v:G[u]){
		dep[v]=dep[u]+1;
		f[v]=u;
		dfs0(v);
	}
}
void dfs1(int u){
	if(G[u].empty()){
		a[u]=1;
		--a[up[u]];
	}
	for(auto v:G[u]){
		dfs1(v);
		a[u]+=a[v];
	}
	--top;
}
void dfs2(int u){
	if(G[u].empty()){
		dp[u]=1;return;
	}
	int sum=0;
	for(auto v:G[u]){
		dfs2(v);
		sum+=a[v];
	}
	for(auto v:G[u]){
		dp[u]=max(dp[u],sum-a[v]+dp[v]);
	}
}
int main(){
	n=read(),k=read();
	for(int i=2;i<=n;++i){
		int fa=read();
		G[fa].push_back(i);
	}
	dfs0(1);
	for(int i=1;i<=n;++i){
		if(G[i].empty())leaf.push_back(i);
	}
	sort(leaf.begin(),leaf.end(),[&](int i,int j){return dep[i]<dep[j];});
	memset(up,255,sizeof(up));
	up[0]=0;
	for(auto x:leaf){
		int u=x,tmp=0;
		for(int i=1;i<=k;++i){
			u=f[u];
			tmp=u;
			if(~up[u]){
				tmp=up[u];break;
			}
		}
		up[x]=tmp;
		u=x;
		for(int i=1;i<=k;++i){
			u=f[u];
			if(~up[u])break;
			up[u]=tmp;
		}
	}		
	dfs1(1);
	dfs2(1);
	printf("%d\n",dp[1]);
	return 0;
}