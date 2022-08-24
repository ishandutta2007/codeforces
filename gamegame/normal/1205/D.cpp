#include<bits/stdc++.h>
using namespace std;
vector<int>adj[1001];
vector<int>ch[1001];
int n;
int sz[1001];
void dfs(int id,int p){
	sz[id]=1;
	for(auto cur:adj[id]){
		if(cur==p) continue;
		dfs(cur,id);
		sz[id]+=sz[cur];
		ch[id].push_back(cur);
	}
}
int ok=0;
int q=0,r;
int d[1001],e[1001];
void dfs3(int id,int p){
	++q;
	d[id]=q-d[p];
	cout << id << ' ' << p << ' ' << d[id] << endl;
	d[id]=q;
	for(auto cur:adj[id]){
		if(cur==p) continue;
		dfs3(cur,id);
	}
}

void dfs5(int id,int p){
	r+=q+1;
	d[id]=r-d[p];
	cout << id << ' ' << p << ' ' << d[id] << endl;
	d[id]=r;
	for(auto cur:adj[id]){
		if(cur==p) continue;
		dfs5(cur,id);
	}
}
void dfs4(int id){
	for(auto cur:adj[id]){
		if(!d[cur]) dfs5(cur,id);
	}
}
void dfs2(int id,int p){
	if(ok) return;
	for(auto cur:ch[id]){
		dfs2(cur,id);
		if(ok) return;
	}
	if(sz[id]*2<n) return;
	ok=1;
	if((n-sz[id])*3>=n){
		dfs3(p,id);
		dfs4(id);
		return;
	}
	for(auto cur:ch[id]){
		if(sz[cur]*3>=n){
			dfs3(cur,id);
			dfs4(id);
			return;
		}
	}
	int sum=0;
	for(auto cur:ch[id]){
		sum+=sz[cur];
		dfs3(cur,id);
		if(sum*3>=n){
			dfs4(id);
			return;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<n ;i++){
		int u,v;cin >> u >> v;
		adj[u].push_back(v);adj[v].push_back(u);
	}
	dfs(1,0);dfs2(1,0);
}