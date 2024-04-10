#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,m,vis[N],rt;
vector<int> G[N],ans;
int ok;
mt19937 rnd(time(0));
void dfs1(int u){
	static int ins[N];
	ins[u]=vis[u]=1;
	for(auto v:G[u]){
		if(vis[v]){
			if(!ins[v])ok=0;
		}
		else dfs1(v);
	}
	ins[u]=0;
}
int s1[N],s2[N],isok[N],c[N],num;
void dfs2(int u){
	vis[u]=1;
	c[++num]=u;
	for(auto v:G[u]){
		if(!vis[v])dfs2(v),s1[u]+=s1[v],s2[u]^=s2[v];
		else{
			++s1[u],--s1[v];
			s2[u]^=v,s2[v]^=v;
		}
	}
}
void Solve(){
	cin>>n>>m;
	ans.clear();
	for(int i=1;i<=n;++i)G[i].clear();
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
	}
	int myh=50;
	rt=-1;
	while(myh--){
		int u=rnd()%n+1;
		ok=1;
		for(int i=1;i<=n;++i)vis[i]=0;
		dfs1(u);
		if(ok){rt=u;break;}
	}
	if(!~rt){cout<<-1<<'\n';return;}
	for(int i=1;i<=n;++i)vis[i]=s1[i]=s2[i]=isok[i]=0;
	num=0;
	dfs2(rt);
	ans.push_back(rt);
	isok[rt]=1;
	for(int i=2;i<=n;++i){
		int u=c[i];
		if(s1[u]==1&&isok[s2[u]])isok[u]=1,ans.push_back(u);	
	}
	if(ans.size()>=0.2*n){
		sort(ans.begin(),ans.end());
		for(auto u:ans)cout<<u<<' ';
		cout<<'\n';
	}
	else cout<<-1<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}