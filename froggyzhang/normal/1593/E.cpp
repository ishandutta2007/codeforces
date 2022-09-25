#include<bits/stdc++.h>
using namespace std;
#define N 400040
typedef long long ll;
const int inf=0x3f3f3f3f;
vector<int> G[N];
int n,dis[N],K,d[N];
void Solve(){
	cin>>n>>K;
	for(int i=1;i<=n;++i)G[i].clear(),dis[i]=0;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	queue<int> q;
	for(int i=1;i<=n;++i){
		d[i]=(int)G[i].size()-1;
		if(G[i].size()<=1)q.push(i),dis[i]=1;
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:G[u]){
			if(d[v]>0)dis[v]=max(dis[v],dis[u]+1);
			if(!--d[v])q.push(v);
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		if(dis[i]>K)++ans;
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}