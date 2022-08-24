#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
int n;
bool vis[100001];
double ans[100001];
vector<int>adj[100001],c[100001];
void dfs(int id){
	vis[id]=true;
	for(int i=0; i<adj[id].size() ;i++){
		int cur=adj[id][i];
		if(!vis[cur]){
			dfs(cur);
			c[id].push_back(cur);
		}
	}
}
void solve(int id){
	if(c[id].size()==0) return;
	for(int i=0; i<c[id].size() ;i++){
		int cur=c[id][i];
		solve(cur);
		ans[id]+=1+ans[cur];
	}
	ans[id]/=c[id].size();
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<n ;i++){
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	solve(1);
	cout << fixed << setprecision(20) << ans[1] << endl;
}