#include<bits/stdc++.h>
using namespace std;
#define N 200010
typedef long long ll;
int n,m,Q,f[N],ff[N][19],g[N],dep[N],gg[N][19],dfn[N],ans[N],num,kk[N],siz[N];
vector<int> G[N];
class Union_Set{
public:
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
void dfs1(int u){
	dfn[u]=++num;
	dep[u]=dep[f[u]]+1;
	siz[u]=1;
	ff[u][0]=f[u];
	for(int i=1;i<=18;++i){
		ff[u][i]=ff[ff[u][i-1]][i-1];
	}
	for(auto v:G[u]){
		dfs1(v);
		siz[u]+=siz[v];
	}	
}
inline tuple<int,int,int> LCA(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=18;i>=0;--i){
		if(dep[ff[u][i]]>=dep[v])u=ff[u][i];
	}
	if(u==v)return make_tuple(u,-1,-1);
	for(int i=18;i>=0;--i){
		if(ff[u][i]^ff[v][i])u=ff[u][i],v=ff[v][i];
	}
	return make_tuple(f[u],u,v);
}
void dfs2(int u){
	gg[u][0]=g[u];
	for(int i=1;i<=18;++i){
		gg[u][i]=gg[gg[u][i-1]][i-1];
	}
	for(auto v:G[u]){
		dfs2(v);
	}	
}
pair<int,int> Jump(int u,int lim){
	int step=0;
	for(int i=18;i>=0;--i){
		if(dep[gg[u][i]]>lim)step+=1<<i,u=gg[u][i];	
	}	
	return make_pair(step,u);
}
struct Data{
	int x,y,op;
	Data(int _x,int _y,int _op):x(_x),y(_y),op(_op){}
};
map<pair<int,int>,vector<Data> > mp; 
class BIT{
	int b[N];
	inline int lowbit(int x){
		return x&(-x);
	}	
public:
	void Add(int x,int d){
		while(x<=n)b[x]+=d,x+=lowbit(x);
	}
	int Ask(int x){
		int ans=0;
		while(x)ans+=b[x],x-=lowbit(x);
		return ans;
	}
}B;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	S.init(n);
	for(int i=2;i<=n;++i){
		cin>>f[i];
		G[f[i]].push_back(i);
	}
	for(int i=1;i<=n;++i){
		g[i]=i;
	}
	dfs1(1);
	cin>>m;
	vector<pair<int,int> > Chain;
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		if(dep[u]<dep[v])swap(u,v);
		auto [lca,tu,tv]=LCA(u,v);
		if(tu>tv)swap(tu,tv),swap(u,v);
		if(~tu)mp[make_pair(tu,tv)].emplace_back(dfn[u],dfn[v],0);
		Chain.emplace_back(lca,u);
		Chain.emplace_back(lca,v);
	}
	sort(Chain.begin(),Chain.end(),[&](pair<int,int> i,pair<int,int> j){return dep[i.first]<dep[j.first];});
	for(auto [tp,_u]:Chain){
		int u=S.getf(_u);
		while(dep[u]>=dep[tp]){
			g[u]=tp;
			S.f[u]=f[u];
			u=S.getf(u);
		}
	}
	dfs2(1);
	cin>>Q;
	for(int i=1;i<=Q;++i){
		int u,v;
		cin>>u>>v;
		if(dep[u]<dep[v])swap(u,v);
		auto [lca,tu,tv]=LCA(u,v);
		if(tu>tv)swap(tu,tv),swap(u,v);
		auto [d1,_u]=Jump(u,dep[lca]);
		auto [d2,_v]=Jump(v,dep[lca]);
		ans[i]=d1+d2+(_u!=lca)+(_v!=lca);
		if(ans[i]>n){
			ans[i]=-1;
			continue;
		}
		if(~tu){
			auto jb=make_pair(tu,tv);
			u=_u,v=_v;
			mp[jb].emplace_back(dfn[u]+siz[u]-1,dfn[v]+siz[v]-1,i);
			mp[jb].emplace_back(dfn[u]-1,dfn[v]+siz[v]-1,-i);
			mp[jb].emplace_back(dfn[u]+siz[u]-1,dfn[v]-1,-i);
			mp[jb].emplace_back(dfn[u]-1,dfn[v]-1,i);
		}
	}
	for(auto &[qwq,V]:mp){
		sort(V.begin(),V.end(),[&](Data a,Data b){return a.x==b.x?(a.y==b.y?abs(a.op)<abs(b.op):a.y<b.y):a.x<b.x;});
		for(auto [x,y,op]:V){
			if(!op)B.Add(y,1); 
			else kk[abs(op)]+=(op>0?1:-1)*B.Ask(y);	
		}
		for(auto [x,y,op]:V){
			if(!op)B.Add(y,-1);
		}
	}
	for(int i=1;i<=Q;++i){
		cout<<ans[i]-(kk[i]>0)<<'\n';
	}
	return 0;
}//mmst