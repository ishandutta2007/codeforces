#include<bits/stdc++.h>
using namespace std;
#define N 300030
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
vector<int> G[N];
int pre[N],nxt[N],n,d[N],m,f[N],dfn[N],siz[N],p[N];
vector<int> ans;
inline int getf(int x){
	return f[x]==x?x:f[x]=getf(f[x]);
}
int num;
void dfs(int u){
	siz[u]=1;
	dfn[u]=++num;
	for(auto v:G[u])dfs(v),siz[u]+=siz[v];
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		f[i]=i;
		int t=read();
		if(t)G[t].push_back(i),++d[i];
	}
	for(int i=1;i<=n;++i){
		if(!d[i]&&!dfn[i])dfs(i);
	}
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		if(nxt[u]||pre[v])return !printf("0\n");
		nxt[u]=v;
		pre[v]=u;
		if(getf(u)==v||(dfn[u]>=dfn[v]&&dfn[u]<=dfn[v]+siz[v]-1))return !printf("0\n");
		f[v]=getf(u);
	}
	for(int i=1;i<=n;++i){
		if(getf(i)^i){
			d[f[i]]+=d[i],d[i]=0;
		}	
	}
	for(int u=1;u<=n;++u){
		for(auto v:G[u]){
			if(f[u]==f[v])--d[f[u]];
		}
	}
	deque<int> q;
	for(int i=1;i<=n;++i){
		if(!d[i]&&f[i]==i)q.push_back(i);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop_front();
		ans.push_back(u);
		p[u]=ans.size();
		if(nxt[u])q.push_front(nxt[u]);
		for(auto v:G[u]){
			if(!--d[f[v]])q.push_back(f[v]);
		}
	}
	for(int u=1;u<=n;++u){
		for(auto v:G[u]){
			if(p[v]<p[u])return !printf("0\n");
		}
	}
	if(ans.size()!=n)return !printf("0\n");
	for(auto x:ans)printf("%d ",x);
	return 0;
}