#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
typedef pair<int,int> pii;
int n,k,f[N],rt,rt2,mxdep[N],dis1[N],dis2[N],ans[N];
vector<int> G[N];
pii dfs1(int u,int fa){
	f[u]=fa;
	pii mx=pii(0,u);
	for(auto v:G[u]){
		if(v==fa)continue;
		pii tmp=dfs1(v,u);
		++tmp.first;
		mx=max(mx,tmp);
	}
	return mx;
}
void get_dis(int u,int fa,int *dis){
	dis[u]=dis[fa]+1;
	for(auto v:G[u]){
		if(v==fa)continue;
		get_dis(v,u,dis);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	rt=dfs1(1,0).second;
	rt2=dfs1(rt,0).second;
	get_dis(rt,0,dis1);
	if(k==2){
		cout<<"Yes\n";
		for(int i=1;i<=n;++i){
			cout<<(dis1[i]&1?1:2)<<' ';
		}
		cout<<'\n';
		return 0;
	}
	get_dis(rt2,0,dis2);
	for(int i=1;i<=n;++i){
		if(dis1[i]>=k&&dis2[i]>=k&&dis1[i]+dis2[i]-1!=dis1[rt2]){
			cout<<"No\n";
			return 0;
		}	
		ans[i]=dis1[i]<=dis2[i]?dis1[rt2]-dis2[i]+1:dis1[i];
	}
	cout<<"Yes\n";
	for(int i=1;i<=n;++i){
		cout<<(ans[i]-1)%k+1<<' ';
	}
	cout<<'\n';
	return 0;
}