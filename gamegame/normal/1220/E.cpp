#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll w[200001];
ll t[200001];
vector<int>adj[200001];
stack<int>s;
int st;
bool vis[200001];
int deg[200001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=n ;i++) cin >> w[i];
	for(int i=1; i<=m ;i++){
		int u,v;cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		deg[u]++;deg[v]++;
	}
	cin >> st;
	for(int i=1; i<=n ;i++){
		if(i!=st && deg[i]==1) s.push(i);
	}
	while(!s.empty()){
		int cur=s.top();s.pop();
		t[cur]+=w[cur];
		w[cur]=0;
		vis[cur]=true;
		for(auto duh:adj[cur]){
			if(vis[duh] || duh==st) continue;
			deg[duh]--;
			t[duh]=max(t[duh],t[cur]);
			if(deg[duh]==1) s.push(duh);
		}
	}
	ll ans=0;
	ll mx=0;
	for(int i=1; i<=n ;i++){
		ans+=w[i];
		if(vis[i]) mx=max(mx,t[i]);
	}
	cout << ans+mx << '\n';
}