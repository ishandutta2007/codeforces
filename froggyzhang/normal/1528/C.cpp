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
int T,n,ans;
vector<int> G[N],H[N];
int siz[N],num,dfn[N];
set<pair<int,int> > s;
void dfs1(int u){
	siz[u]=1;
	dfn[u]=++num;
	for(auto v:H[u]){
		dfs1(v);
		siz[u]+=siz[v];
	}
}
void dfs2(int u){
	auto it=s.upper_bound(make_pair(dfn[u],dfn[u]));
	pair<int,int> z=make_pair(0,0);
	if(it!=s.begin()){
		--it;
		if(it->first <=dfn[u] && it->second >=dfn[u]){
			z=*it;
			s.erase(it);
		}
	}
	s.insert(make_pair(dfn[u],dfn[u]+siz[u]-1));
	ans=max(ans,(int)s.size());
	for(auto v:G[u]){
		dfs2(v);
	}
	s.erase(make_pair(dfn[u],dfn[u]+siz[u]-1));
	if(z.first)s.insert(z);
}
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		G[i].clear();
		H[i].clear();
	}
	for(int i=2;i<=n;++i){
		int fa=read();
		G[fa].push_back(i);
	}
	for(int i=2;i<=n;++i){
		int fa=read();
		H[fa].push_back(i);
	}
	num=ans=0;
	s.clear();
	dfs1(1);
	dfs2(1);
	printf("%d\n",ans);
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}