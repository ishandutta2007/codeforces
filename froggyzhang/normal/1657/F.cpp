#include<bits/stdc++.h>
using namespace std;
#define N 1600040
typedef long long ll;
int n,Q,dep[N],f[N],vis[N];
char c0[N],c1[N];
vector<int> G[N];
inline int yes(int x){return 2*x;}
inline int no(int x){return 2*x+1;}
inline void adde(int u,int v){
	G[u].push_back(v);
	G[v^1].push_back(u^1);
}
void dfs(int u,int fa){
	f[u]=fa;
	dep[u]=dep[fa]+1;
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);
	}
}
int dfn[N],low[N],col[N],tot,num;
void Tarjan(int u){
	static bool vis[N];
	static int st[N],top; 
	dfn[u]=low[u]=++num;
	st[++top]=u;
	vis[u]=1;
	for(auto v:G[u]){
		if(!dfn[v]){
			Tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(vis[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u]){
		++tot;
		int t=0;
		while(t^u){
			t=st[top--];
			vis[t]=0;
			col[t]=tot;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=n;++i){
		G[i].clear();
	}
	for(int q=1;q<=Q;++q){
		static char s[N];
		static int a[N],x,y;
		cin>>x>>y>>(s+1);
		int len=strlen(s+1);
		int l=0,r=len+1;
		for(int t=1;t<=len;++t){
			if(dep[x]>dep[y])a[++l]=x,x=f[x];
			else a[--r]=y,y=f[y];
		}
		for(int i=1;i<=len;++i){
			int u=a[i];
			if(!vis[u]){
				vis[u]=1;
				c0[u]=s[i],c1[u]=s[len-i+1];
			}
			if(c0[u]!=s[i])adde(no(u),yes(n+q));
			if(c1[u]!=s[i])adde(yes(u),yes(n+q));
			if(c0[u]!=s[len-i+1])adde(no(u),no(n+q));
			if(c1[u]!=s[len-i+1])adde(yes(u),no(n+q));
		}
	}
	for(int i=1;i<=2*(n+Q)+1;++i){
		if(!dfn[i])Tarjan(i);
	}
	for(int i=1;i<=n+Q;++i){
		if(col[yes(i)]==col[no(i)]){
			cout<<"NO\n";return 0;
		}
	}
	cout<<"YES\n";
	for(int i=1;i<=n;++i){
		cout<<(!vis[i]?'a':(col[yes(i)]>col[no(i)]?c0[i]:c1[i]));
	}
	return 0;
}