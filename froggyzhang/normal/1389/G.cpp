#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
#define N 300030
inline int read(){
	int x=0,f=1;
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
int n,m,k,sp[N],w[N],o[N],root;
int dfn[N],low[N],num,tot,col[N],p[N];
ll dp[N],sum[N],g[N];
struct Union{
	int f[N];
	void init(int n){
		for(int i=1;i<=n;++i){
			f[i]=i;
		}
	}
	inline int getf(int x){
		return f[x]==x?x:f[x]=getf(f[x]);
	}
}S;
stack<int> st;
struct Edge{
	int to,id,val;
};
vector<Edge> G[N],T[N];
vector<int> rec[N];
void Tarjan(int u,int in_edge){
	low[u]=dfn[u]=++num;
	st.push(u);
	for(auto e:G[u]){
		int v=e.to;
		if(in_edge==e.id)continue;
		if(!dfn[v]){
			Tarjan(v,e.id);
			low[u]=min(low[u],low[v]);
		}
		else{
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u]){
		++tot;
		int t=0;
		while(t^u){
			t=st.top();
			st.pop();
			col[t]=tot;
			sum[tot]+=w[t];
			p[tot]|=sp[t];
			rec[tot].push_back(t);
		}
	}
}
void build(){
	for(int u=1;u<=n;++u){
		for(auto e:G[u]){
			int v=e.to;
			if(col[u]^col[v]){
				T[col[u]].push_back({col[v],e.id,e.val});
			}
		}
	}
}
bool init(int u,int fa){
	bool ok=p[u];
	for(auto e:T[u]){
		int v=e.to;
		if(v==fa)continue;
		ok|=init(v,u);
	}
	if(!ok){
		sum[fa]+=sum[u];
		S.f[u]=fa;
		sum[u]=0;
		rec[u].clear();
	}
	return ok;
}
void dfs1(int u,int fa){
	dp[u]=sum[u];
	for(auto e:T[u]){
		int v=e.to;
		if(v==fa||S.getf(v)^v)continue;
		dfs1(v,u);
		dp[u]+=max(0LL,dp[v]-e.val);
	}
}
void dfs2(int u,int fa){
	for(auto e:T[u]){
		int v=e.to;
		if(v==fa||S.getf(v)^v)continue;
		g[v]=dp[v]+max(0LL,g[u]-max(0LL,dp[v]-e.val)-e.val);
		dfs2(v,u);
	}
}
int main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=k;++i){
		sp[read()]=1;
	}
	for(int i=1;i<=n;++i){
		w[i]=read();
	}
	for(int i=1;i<=m;++i){
		o[i]=read();
	}
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		G[u].push_back({v,i,o[i]});
		G[v].push_back({u,i,o[i]});
	}
	Tarjan(1,0);
	build();
	S.init(tot);
	for(int i=1;i<=tot;++i){
		if(p[i]){
			init(i,0);
			break;
		}
	}
	for(int i=1;i<=tot;++i){
		if(!rec[i].empty()){
			root=i;break;
		}
	}
	dfs1(root,0);
	g[root]=dp[root];
	dfs2(root,0);
	for(int i=1;i<=n;++i){
		printf("%I64d ",g[S.getf(col[i])]);
	}
	return 0;
}