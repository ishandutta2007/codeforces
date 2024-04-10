#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
typedef pair<int,int> pii;
int n,m,dep[N],f[N],s[N],p[N],ban[N];
vector<pii> G[N];
struct Union_Set{
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
	for(auto [v,id]:G[u]){
		if(v==f[u])continue;
		if(!dep[v]){
			dep[v]=dep[u]+1;
			f[v]=u;
			p[id]=v;
			dfs1(v);
		}
		else if(dep[v]<dep[u]){
			++s[u],--s[v];
			p[id]=u;
			for(int x=S.getf(u);dep[f[x]]>dep[v];x=S.getf(x)){
				S.f[x]=f[x];
			}
		}
	}	
}
void dfs2(int u){
	for(auto [v,id]:G[u]){
		if(f[v]^u)continue;
		dfs2(v);
		s[u]+=s[v];	
	}
	if(s[u]>1){
		ban[S.getf(u)]=1;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		G[u].emplace_back(v,i);
		G[v].emplace_back(u,i);
	}
	S.init(n);
	vector<int> rts;
	for(int i=1;i<=n;++i){
		if(!dep[i])dep[i]=1,dfs1(i),rts.push_back(i);
	}
	for(auto u:rts){
		dfs2(u);
	}
	vector<int> ans;
	for(int i=1;i<=m;++i){
		if(s[p[i]]==1&&!ban[S.getf(p[i])])ans.push_back(i);
	}
	cout<<ans.size()<<'\n';
	for(auto x:ans){
		cout<<x<<' ';
	}
	cout<<'\n';
	return 0;
}