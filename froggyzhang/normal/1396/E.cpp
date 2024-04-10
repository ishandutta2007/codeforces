#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef pair<int,int> pii;
typedef long long ll;
int n,rt,siz[N],maxp[N],vis[N],dep[N];
ll k,L,R;
vector<int> G[N],rem,H[N];
priority_queue<pii> q;
set<pii> s[N];
void get_root(int u,int fa){
	siz[u]=1;
	for(auto v:G[u]){
		if(v==fa)continue;
		get_root(v,u);
		siz[u]+=siz[v];
		maxp[u]=max(maxp[u],siz[v]);
		L+=siz[v]&1;
		R+=min(siz[v],n-siz[v]);
	}
	maxp[u]=max(maxp[u],n-siz[u]);
	if(!rt||maxp[u]<maxp[rt]){
		rt=u;
	}
}
void dfs0(int u,int fa){
	siz[u]=1;
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs0(v,u);
		siz[u]+=siz[v];
	}
}
void dfs1(int u,int fa,int anc){
	dep[u]=dep[fa]+1;
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs1(v,u,anc);
		H[u].push_back(v);
	}
	if(!H[u].empty()){
		s[anc].emplace(dep[u],u);	
	}
}
void dfs2(int u,int fa){
	if(!vis[u])rem.push_back(u);
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs2(v,u);	
	}	
}
inline void EMM(vector<int> &H){while(!H.empty()&&vis[H.back()])H.pop_back();}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	get_root(1,0);
	if(k<L||k>R||(k&1)^(L&1)){
		cout<<"NO\n";return 0;
	}
	cout<<"YES\n";
	dfs0(rt,0);
	for(auto v:G[rt]){
		q.emplace(siz[v],v);
		dfs1(v,rt,v);
	}
	ll jb=R-k;
	while(jb>0){
		int t=q.top().second;
		q.pop();
		int x,y,u;
		while(true){
			u=s[t].rbegin()->second;
			EMM(H[u]);
			if(H[u].empty())s[t].erase(--s[t].end());
			else break;
		}
		if((dep[u]<<1)>jb)u=s[t].lower_bound(make_pair(jb/2,0))->second;
		jb-=dep[u]<<1;
		x=H[u].back();
		H[u].pop_back();
		EMM(H[u]);
		if(H[u].empty())y=u;
		else y=H[u].back(),H[u].pop_back();
		EMM(H[u]);
		if(H[u].empty())s[t].erase(make_pair(dep[u],u));
		cout<<x<<' '<<y<<'\n';
		vis[x]=vis[y]=1;
		siz[t]-=2;
		q.emplace(siz[t],t);
	}
	dfs2(rt,0);
	for(int i=0;i<(int)rem.size()/2;++i){
		cout<<rem[i]<<' '<<rem[i+(int)rem.size()/2]<<'\n';
	}
	return 0;
}