#include<iostream>
#include<vector>
using namespace std;
int n,x;
int cnta,cntb;
vector<int>adj[100001];
int c[100001];
bool vis[100001];
int u,v;
void dfs(int id){
	vis[id]=true;
	if(c[id]==0) cnta++;
	else cntb++;
	for(int i=0; i<adj[id].size() ;i++){
		int newi=adj[id][i];
		if(vis[adj[id][i]]) continue;
		c[newi]=1-c[id];
		dfs(newi);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<n ;i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	cout << 1LL*cnta*cntb-(n-1) << endl;
}