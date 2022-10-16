#include<bits/stdc++.h>
using namespace std;
#define N 600030
typedef long long ll;
int n,m,ans[N],jb[N],ANS,emm[N],d[N],_m,vis[N];
vector<pair<int,int> > G[N];
vector<int> tmp[N],qwq;
vector<tuple<int,int,int> > E;
int las;
void dfs1(int u){
	while(!G[u].empty()){
		auto [v,id]=G[u].back();
		G[u].pop_back();
		if(ans[abs(id)]||(!id&&vis[u|v]))continue;
		int op=id<0;
		if(id)emm[u]+=2*op,emm[v]-=2*op,ans[abs(id)]=1+op,qwq.push_back(abs(id));
		else vis[u|v]=1;
		if(!v){
			++_m;
			tmp[_m]=qwq;	
			qwq.clear();
			E.emplace_back(las,u,_m);
			++d[las],++d[u];
		//	cerr<<" jk! "<<las<<" "<<u<<" "<<_m<<endl;
		}
		else if(!u){
			las=v;	
		}
		dfs1(v);
	}	
}
void dfs2(int u){
	while(!G[u].empty()){
		auto [v,id]=G[u].back();
		G[u].pop_back();
		if(ans[abs(id)]||(!id&&vis[u|v]))continue;
		int op=id<0;
		if(id)ans[abs(id)]=1+op;
		else vis[u|v]=1;
		dfs2(v);
	}	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	_m=m;
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		if(w==2){
			G[u].emplace_back(v,i);
			G[v].emplace_back(u,-i);
			jb[u]^=1,jb[v]^=1;	
		}
		else{
			++d[u],++d[v];	
			E.emplace_back(u,v,i);
		}
	}
	for(int i=1;i<=n;++i){
		if(d[i]&1)++ANS;
	}
	for(int i=1;i<=n;++i){
		if(jb[i]&1)G[0].emplace_back(i,0),G[i].emplace_back(0,0);
	}
	for(int i=0;i<=n;++i){
		dfs1(i);	
	}
	for(auto [u,v,id]:E){
		G[u].emplace_back(v,id);
		G[v].emplace_back(u,-id);
	}
	for(int i=1;i<=n;++i){
		if(d[i]&1)G[0].emplace_back(i,0),G[i].emplace_back(0,0);
	}
	memset(vis,0,sizeof(vis));
	for(int i=0;i<=n;++i){
		dfs2(i);	
	}
	for(int i=m+1;i<=_m;++i){
		if(ans[i]==2){
			for(auto x:tmp[i]){
				ans[x]=(ans[x]==2?1:2);	
			}
		}	
	}
	
	cout<<ANS<<'\n';
	for(int i=1;i<=m;++i){
		cout<<ans[i];
	}
	cout<<'\n';
	return 0;
}