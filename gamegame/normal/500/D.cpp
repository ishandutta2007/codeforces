#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
ll ans=0;
int n,q;
vector<pair<int,int> >adj[100001];
ll d[100001];
int sz[100001];
ll u[100001],v[100001],w[100001];
void dfs(int id,int p){
	sz[id]=1;
	for(auto cur:adj[id]){
		if(cur.se==p) continue;
		dfs(cur.se,id);
		sz[id]+=sz[cur.se];
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<n ;i++){
		cin >> u[i] >> v[i] >> w[i];
		adj[u[i]].push_back({w[i],v[i]});
		adj[v[i]].push_back({w[i],u[i]});
	}
	dfs(1,0);
	cin >> q;
	for(int i=1; i<n ;i++){
		if(sz[u[i]]<sz[v[i]]) swap(u[i],v[i]);
		ans+=w[i]*sz[v[i]]*(n-sz[v[i]]);
	}
	for(int i=1; i<=q ;i++){
		int r,wi;cin >> r >> wi;
		ans-=w[r]*sz[v[r]]*(n-sz[v[r]]);
		w[r]=wi;
		ans+=w[r]*sz[v[r]]*(n-sz[v[r]]);
		printf("%.10lf\n",1.0*ans/n/(n-1)*6);
	}
}