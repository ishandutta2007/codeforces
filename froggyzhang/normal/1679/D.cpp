#include<bits/stdc++.h>
using namespace std;
#define N 200010
typedef long long ll;
int n,m,a[N],dis[N],d[N];
ll k;
vector<int> G[N];
vector<pair<int,int> > E;
bool check(int lim){
	for(int i=1;i<=n;++i){
		G[i].clear();
		d[i]=0;dis[i]=-1;
	}
	for(auto [u,v]:E){
		if(a[u]<=lim&&a[v]<=lim){
			G[v].push_back(u);
			++d[u];
		}
	}
	queue<int> q;
	for(int i=1;i<=n;++i){
		if(!d[i]&&a[i]<=lim)q.push(i),dis[i]=1;
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:G[u]){
			dis[v]=max(dis[v],dis[u]+1);
			if(!--d[v])q.push(v);
		}
	}
	for(int i=1;i<=n;++i){
		if(a[i]<=lim&&(d[i]||dis[i]>=k)){
			return true;
		}
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		E.emplace_back(u,v);
	}
	int l=1,r=1e9+1,ans=-1;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid,r=mid;
		}
		else{
			l=mid+1;
		}
	}
	cout<<ans<<'\n';
	return 0;
}