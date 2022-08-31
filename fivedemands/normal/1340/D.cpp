#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=1e6+1;
int n;
vector<int>adj[N];
vector<int>ax,ay;
void dfs(int id,int p,int t){
	ax.push_back(id);
	ay.push_back(t);
	bool ok=false;
	for(auto cur:adj[id]){
		if(cur==p) continue;
		if(!ok && t>=adj[id].size()){
			ok=true;
			t-=adj[id].size();
			ax.push_back(id);
			ay.push_back(t);
		}
		dfs(cur,id,t+1);
		t++;
		ax.push_back(id);
		ay.push_back(t);
	}
	if(!ok && t>=adj[id].size() && id!=1){
		t-=adj[id].size();
		ax.push_back(id);
		ay.push_back(t);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<n ;i++){
		int u,v;cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,0,0);
	cout << ax.size() << '\n';
	for(int i=0; i<ax.size() ;i++){
		cout << ax[i] << ' ' << ay[i] << '\n';
	}
}