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
int n,m;
vector<pair<int,int> > G[N];
int dfn[N],low[N],vis[N],num,col[N],tot;
stack<int> st;
ll g[N];
void Tarjan(int u){
	low[u]=dfn[u]=++num;
	vis[u]=1;
	st.push(u);
	for(auto [v,w]:G[u]){
		if(!dfn[v]){
			Tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(vis[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(low[u]==dfn[u]){
		int t=0;
		++tot;
		while(t^u){
			t=st.top();
			st.pop();
			col[t]=tot;
			vis[t]=0;
		}
	}
}
ll dep[N];
void dfs(int u){
	vis[u]=1;
	for(auto [v,w]:G[u]){
		if(col[v]^col[u])continue;
		if(vis[v]){
			g[col[u]]=__gcd(g[col[u]],dep[u]-dep[v]+w);
		}
		else{
			dep[v]=dep[u]+w;
			dfs(v);
		}
	}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		G[u].emplace_back(v,w);
	}
	for(int i=1;i<=n;++i){
		if(!dfn[i])Tarjan(i);
	}
	for(int i=1;i<=n;++i){
		if(vis[i])continue;
		dfs(i);
	}
	int Q=read();
	while(Q--){
		int u=read();
		ll s=read(),t=read();
		u=col[u];
		t=__gcd(t,g[u]);
		printf((t-s)%t==0?"YES\n":"NO\n");
	}
	return 0;
}