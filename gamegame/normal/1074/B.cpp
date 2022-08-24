#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
int t;
int n;
vector<int>adj[1001];
int k1,k2;
int x[1001];
int y[1001];
int d[1002];
bool isx[1001];
bool isy[1001];
void dfs(int id,int p){
	d[id]=d[p]+1;
	for(auto cur:adj[id]){
		if(cur==p) continue;
		dfs(cur,id);
	}
}
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++){
		adj[i].clear();
		isx[i]=isy[i]=false;
	}
	for(int i=1; i<n ;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cin >> k1;
	for(int i=1; i<=k1 ;i++){
		cin >> x[i];
		isx[x[i]]=true;
	}
	cin >> k2;
	for(int i=1; i<=k2 ;i++){
		cin >> y[i];
		isy[y[i]]=true;
	}
	cout << "B " << y[1] << endl;
	int res;
	cin >> res;
	if(isx[res]){
		cout << "C " << res << endl;
		return;
	}
	dfs(res,0);
	int best=1001;
	for(int i=1; i<=n ;i++){
		if(isx[i] && d[best]>d[i]) best=i;
	}
	cout << "A " << best << endl;
	cin >> res;
	if(isy[res]) cout << "C " << best << endl;
	else cout << "C -1" << endl;
}
int main(){
	ios::sync_with_stdio(false);
	d[1001]=1001;
	cin >> t;
	while(t--) solve();
}