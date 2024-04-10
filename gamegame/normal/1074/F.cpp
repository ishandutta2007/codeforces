#include<iostream>
#include<queue>
#include<map>
using namespace std;
int n,q;
int f[200001];
int r[200001];
bool vis[200001];
vector<int>adj[200001];
map<int,int>m[200001];
int sz=0;
int par[200001][18];
int d[200001];
void dfs(int id,int p){
	sz++;
	f[id]=sz;
	d[f[id]]=d[f[p]]+1;
	vis[id]=true;
	for(auto cur:adj[id]){
		if(vis[cur]) continue;
		dfs(cur,id);
	}
	r[f[id]]=sz;
}
void dfs2(int id,int p){
	for(auto cur:adj[id]){
		if(cur==p) continue;
		par[f[cur]][0]=f[id];
		for(int i=1; i<=17 ;i++){
			par[f[cur]][i]=par[par[f[cur]][i-1]][i-1];
		}
		dfs2(cur,id);
	}
}
int cnt[524288],lazy[524288],mini[524288];
void build(int id,int cl,int cr){
	cnt[id]=cr-cl+1;
	if(cl==cr) return;
	int mid=(cl+cr)/2;
	build(id*2,cl,mid);
	build(id*2+1,mid+1,cr);
}
void upd(int id,int cl,int cr,int ll,int rr,int v){
	if(cr<ll || cl>rr) return;
	if(ll<=cl && cr<=rr){
		lazy[id]+=v;
		mini[id]+=v;
		return;
	}
	lazy[id*2]+=lazy[id];
	mini[id*2]+=lazy[id];
	lazy[id*2+1]+=lazy[id];
	mini[id*2+1]+=lazy[id];
	lazy[id]=0;
	int mid=(cl+cr)/2;
	upd(id*2,cl,mid,ll,rr,v);
	upd(id*2+1,mid+1,cr,ll,rr,v);
	mini[id]=min(mini[id*2],mini[id*2+1]);
	cnt[id]=0;
	if(mini[id*2]==mini[id]) cnt[id]+=cnt[id*2];
	if(mini[id*2+1]==mini[id]) cnt[id]+=cnt[id*2+1];
}
int kth_anc(int id,int k){
	for(int i=17; i>=0 ;i--){
		if(k&(1<<i)) id=par[id][i];
	}
	return id;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for(int i=1; i<n ;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,0);
	dfs2(1,0);
	build(1,1,n);
	for(int i=1; i<=q ;i++){
		int u,v;
		cin >> u >> v;
		u=f[u];v=f[v];
		if(u>v) swap(u,v);
		int t=m[u][v];
		m[u][v]=1-t;
		t=1-t*2;
		if(r[u]>=v){
			u=kth_anc(v,d[v]-d[u]-1);
			upd(1,1,n,u,r[u],t);
			upd(1,1,n,v,r[v],-t);
		}
		else{
			upd(1,1,n,1,n,t);
			upd(1,1,n,u,r[u],-t);
			upd(1,1,n,v,r[v],-t);
		}
		if(mini[1]!=0) cout << "0\n";
		else cout << cnt[1] << '\n';
	}
}