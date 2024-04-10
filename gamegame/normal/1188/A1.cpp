#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>adj[100001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<n ;i++){
		int u,v;cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1; i<=n ;i++){
		if(adj[i].size()==2){
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
}