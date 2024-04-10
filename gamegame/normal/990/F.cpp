#include<bits/stdc++.h>
//#define pc __builtin_popcountll
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n,m,q;
int dsu[200001];
bool use[200001];
ll ans[200001];
int find(int x){
	if(dsu[x]!=x) dsu[x]=find(dsu[x]);
	return dsu[x];
}
bool join(int x,int y){
	x=find(x);y=find(y);
	if(x==y) return false;
	dsu[x]=y;
	return true;
}
vector<pair<int,int> >adj[200001];
ll a[200001];
bool vis[200001];
void dfs(int id,int p){
	vis[id]=true;
	for(auto cur:adj[id]){
		if(cur.se==p) continue;
		dfs(cur.se,id);
		ans[abs(cur.fi)]=a[cur.se]*(2*(cur.fi<0)-1);
		a[id]+=a[cur.se];
		a[cur.se]=0;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		dsu[i]=i;
	}
	cin >> m;
	for(int i=1; i<=m ;i++){
		int u,v;
		cin >> u >> v;
		
		if(join(u,v)) use[i]=true;
		if(use[i]){
			adj[u].push_back({i,v});
			adj[v].push_back({-i,u});
		}
	}
	for(int i=1; i<=n ;i++){
		if(!vis[i]) dfs(i,0);
		if(a[i]!=0) return cout << "Impossible\n",0;
	}
	cout << "Possible\n";
	for(int i=1; i<=m ;i++){
		cout << -ans[i] << '\n';
	}
}