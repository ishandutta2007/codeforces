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
int n,m,z;
ll all,ans;
struct Link{
	int x,y,z;
	friend bool operator < (const Link &a,const Link &b){
		return a.z<b.z;
	}
}L[N];
vector<Link> E;
vector<pair<int,int> > to[N];
vector<pair<int,int> > G[N];
struct Union_Set{
	int f[N];
	void init(int n){
		for(int i=1;i<=n;++i)f[i]=i;
	}
	inline int getf(int x){
		return f[x]==x?x:f[x]=getf(f[x]);
	}
}S;
set<int> s;
queue<int> q;
int g[N];
int top[N],f[N],son[N],siz[N],dep[N];
void dfs1(int u){
	dep[u]=dep[f[u]]+1;
	siz[u]=1;
	for(auto [v,w]:G[u]){
		if(v==f[u])continue;
		f[v]=u;
		g[v]=g[u]+w;
		dfs1(v);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]])son[u]=v;
	}
}
void dfs2(int u,int topf){
	top[u]=topf;
	if(!son[u])return;
	dfs2(son[u],topf);
	for(auto [v,w]:G[u]){
		if(v==f[u]||v==son[u])continue;
		dfs2(v,v);
	}
}
int LCA(int x,int y){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
inline bool Ask(int x,int y){
	return g[x]+g[x]-2*g[LCA(x,y)]>0;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		z^=w;
		to[u].emplace_back(v,w);
		to[v].emplace_back(u,w);
		L[i].x=u,L[i].y=v,L[i].z=w;
	}
	S.init(n);
	int cnt=0;
	for(int i=1;i<=n;++i)s.insert(i);
	while(!s.empty()){
		int u=0;
		if(q.empty()){
			u=*s.begin();s.erase(s.begin());
		}
		else{
			u=q.front();
			q.pop();
		}
		static int vis[N];
		for(auto [v,w]:to[u])vis[v]=1;
		static vector<int> bin;
		bin.clear();
		for(auto t:s){
			if(!vis[t]){
				q.push(t);
				bin.push_back(t);
			}
		}
		for(auto v:bin){
			s.erase(v);
			S.f[v]=u;
			G[u].push_back({v,1});
			G[v].push_back({u,1});
			++cnt;
		}
		for(auto [v,w]:to[u])vis[v]=0;
	}
	sort(L+1,L+m+1);
	for(int i=1;i<=m;++i){
		int x=S.getf(L[i].x),y=S.getf(L[i].y);
		if(x==y){
			E.push_back(L[i]);
			continue;
		}
		all+=L[i].z;
		S.f[y]=x;
		G[L[i].x].push_back({L[i].y,0});
		G[L[i].y].push_back({L[i].x,0});
	}
	dfs1(1);
	dfs2(1,1);
	if(cnt==1LL*n*(n-1)/2-m){
		ans=all+z;
		for(auto t:E){
			if(Ask(t.x,t.y)){
				ans=min(ans,all+t.z);
			}
		}
	}
	else ans=all;
	printf("%lld\n",ans);
	return 0;
}