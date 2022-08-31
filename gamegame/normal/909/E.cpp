#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m;
int e[1000001];
int in[1000001];
vector<int>adj[1000001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=n ;i++) cin >> e[i];
	for(int i=1; i<=m ;i++){
		int u,v;
		cin >> u >> v;
		u++;
		v++;
		in[u]++;
		adj[v].push_back(u);
	}
	queue<int>q,r;
	for(int i=1; i<=n ;i++){
		if(in[i]==0 && e[i]==0) q.push(i);
		if(in[i]==0 && e[i]==1) r.push(i);
	}
	int cnt=n;
	int ans=0;
	while(cnt>0){
		while(!q.empty()){
			int cur=q.front();
			q.pop();
			cnt--;
			for(int i=0; i<adj[cur].size() ;i++){
				int newi=adj[cur][i];
				in[newi]--;
				if(in[newi]==0 && e[newi]==0) q.push(newi);
				if(in[newi]==0 && e[newi]==1) r.push(newi);
			}
		}
		if(cnt==0) break;
		ans++;
		while(!r.empty()){
			int cur=r.front();
			r.pop();
			cnt--;
			for(int i=0; i<adj[cur].size() ;i++){
				int newi=adj[cur][i];
				in[newi]--;
				if(in[newi]==0 && e[newi]==0) q.push(newi);
				if(in[newi]==0 && e[newi]==1) r.push(newi);
			}
		}
	}
	cout << ans << endl;
}