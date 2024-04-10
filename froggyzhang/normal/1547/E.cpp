#include<bits/stdc++.h>
using namespace std;
#define N 300030
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3f;
int T,n,k,a[N],b[N],vis[N];
ll dis[N];
void Solve(){
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		dis[i]=inf;	vis[i]=0;
	}
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
	for(int i=1;i<=k;++i){
		cin>>a[i];
	}
	for(int i=1;i<=k;++i){
		cin>>b[i];	
	}
	for(int i=1;i<=k;++i){
		dis[a[i]]=b[i];
		q.push(make_pair(b[i],a[i]));	
	}
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		if(u-1>=1&&dis[u-1]>dis[u]+1){
			dis[u-1]=dis[u]+1;
			q.push(make_pair(dis[u-1],u-1));
		}
		if(u+1<=n&&dis[u+1]>dis[u]+1){
			dis[u+1]=dis[u]+1;
			q.push(make_pair(dis[u+1],u+1));
		}
	}
	for(int i=1;i<=n;++i){
		cout<<dis[i]<<' ';	
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)Solve();
	return 0;
}