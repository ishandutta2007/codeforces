#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>adj[5001];
int eu[5001],ev[5001];
int deg[5001];
stack<int>s;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m;
	for(int i=1; i<=m ;i++){
		int u,v;
		cin >> u >> v;
		eu[i]=u;ev[i]=v;
		adj[u].push_back(v);
		deg[v]++;
	}
	int d=0;
	for(int i=1; i<=n ;i++){
		if(deg[i]==0) s.push(i);
	}
	while(!s.empty()){
		d++;
		int cur=s.top();s.pop();
		for(auto x:adj[cur]){
			deg[x]--;
			if(deg[x]==0) s.push(x);
		}
	}
	if(d==n){
		cout << 1 << '\n';
		for(int i=1; i<=m ;i++) cout << "1 ";
		return 0;
	}
	cout << 2 << '\n';
	for(int i=1; i<=m ;i++){
		if(eu[i]<ev[i]) cout << "1 ";
		else cout << "2 ";
	}
}