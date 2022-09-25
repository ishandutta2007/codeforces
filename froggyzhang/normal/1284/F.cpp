#include<bits/stdc++.h>
using namespace std;
#define N 250050
typedef long long ll;
int n,f[N],ff[N][19],dep[N];
vector<int> G[N],H[N];
vector<tuple<int,int,int,int> > ans;
void dfs1(int u){
	ff[u][0]=f[u];
	for(int i=1;i<=18;++i){
		ff[u][i]=ff[ff[u][i-1]][i-1];
	}
	for(auto v:G[u]){
		if(v==f[u])continue;
		f[v]=u;
		dep[v]=dep[u]+1;
		dfs1(v);
	}	
}
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
inline int Get_down(int u,int jb){
	for(int i=18;i>=0;--i){
		if(!ff[u][i]||S.getf(ff[u][i])^jb)continue;
		u=ff[u][i];
	}
	return u;
}
inline int Get_top(int u,int jb,int lim){
	for(int i=18;i>=0;--i){
		if(dep[ff[u][i]]>=lim&&S.getf(ff[u][i])^jb){
			u=ff[u][i];
		}
	}
	return u;
}
int LCA(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=18;i>=0;--i){
		if(dep[ff[u][i]]>=dep[v])u=ff[u][i];	
	}	
	if(u==v)return u;
	for(int i=18;i>=0;--i){
		if(ff[u][i]^ff[v][i])u=ff[u][i],v=ff[v][i];
	}
	return f[u];
}
pair<int,int> Get(int u,int v){
	int lca=LCA(u,v);
	u=Get_down(u,S.getf(u));
	if(dep[u]>dep[lca]){
		S.f[S.getf(u)]=S.getf(f[u]);
		return make_pair(u,f[u]);
	}
	v=Get_top(v,S.getf(u),dep[lca]);
	S.f[S.getf(u)]=S.getf(v);
	return make_pair(v,f[v]);
}
void dfs2(int u,int fa){
	for(auto v:H[u]){
		if(v==fa)continue;
		dfs2(v,u);
		auto [X,Y]=Get(v,u);
		ans.emplace_back(X,Y,v,u);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);	
	}
	S.init(n);
	dep[1]=1;
	dfs1(1);
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		H[u].push_back(v);
		H[v].push_back(u);
	}
	dfs2(1,0);
	cout<<n-1<<'\n';
	for(auto [X1,Y1,X2,Y2]:ans){
		cout<<X1<<' '<<Y1<<' '<<X2<<' '<<Y2<<'\n';	
	}
	return 0;
}