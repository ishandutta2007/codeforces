#include<bits/stdc++.h>
using namespace std;
#define N 300020
typedef long long ll;
#define int ll
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
int n,m,X,vis[N];
vector<pair<int,int> > G[N];
ll a[N];
set<pair<ll,int>,greater<pair<ll,int> > > s;
vector<int> g[N];
vector<int> ans;
struct Union_Set{
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

inline void Merge(int x,int y){
	if(g[x].size()<g[y].size())swap(x,y);
	reverse(g[y].begin(),g[y].end());
	for(auto z:g[y])g[x].push_back(z);
	g[y].clear();
	S.f[y]=x;
}
signed main(){
	n=read(),m=read(),X=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		s.insert(make_pair(a[i],i));
		g[i].push_back(i);
	}
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		G[u].emplace_back(v,i);
		G[v].emplace_back(u,i);
	}
	S.init(n);
	while(!s.empty()){
		int p=s.begin()->second;
		s.erase(s.begin());
		
		while(!g[p].empty()){
			int u=g[p].back();
			while(!G[u].empty()){
				int v=G[u].back().first,id=G[u].back().second;
				if(vis[id]){
					G[u].pop_back();
					continue;
				}
				v=S.getf(v);
				if(v==p){
					G[u].pop_back();
					continue;
				}
			//	cerr<<" ?? "<<p<<" "<<v<<endl;
				if(a[p]+a[v]>=X){
					vis[id]=1,ans.push_back(id);
					ll myh=a[p]+a[v]-X;
				//	cerr<<" myh: "<<myh<<endl;
					s.erase(make_pair(a[p],p));
					s.erase(make_pair(a[v],v));
				//	cerr<<" qwq "<<endl;
					Merge(p,v);
					a[S.getf(p)]=myh;
					break;
				}
				printf("NO\n");
				return 0;
			}
			if(!G[u].empty()){
				s.insert(make_pair(a[S.getf(p)],S.getf(p)));break;
			}
			g[p].pop_back();
		}
	}
	/*
	for(int T=1;T<n;){
		if(g.empty()){
			return !printf("NO\n");
		}
		auto [w,e]=*--g.end();
		if(w<x){
			return !printf("NO\n");
		}	
		g.erase(*--g.end());
		int x=S.getf(_x[e]),y=S.getf(_y[e]);
		if(x==y)continue;
		ans.push_back(e);
		++T;
		if(s[x].size()<s[y].size())swap(x,y);
		S.f[y]=x;
		
	}
	*/
	printf("YES\n");
	for(auto x:ans){
		printf("%d\n",x);
	}
	return 0;
}