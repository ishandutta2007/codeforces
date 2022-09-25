#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,L,a[N],f[N],len[N],dp[N],ans[N];
ll S,d[N][19],ff[N][19];
vector<int> G[N];
void dfs1(int u){
	d[u][0]=a[u],ff[u][0]=f[u];
	for(int j=1;j<=18;++j){
		d[u][j]=d[u][j-1]+d[ff[u][j-1]][j-1];
		ff[u][j]=ff[ff[u][j-1]][j-1];
	}
	for(auto v:G[u]){
		dfs1(v);
	}	
}
void dfs2(int u){
	dp[u]=-1;
	for(auto v:G[u]){
		dfs2(v);
		dp[u]=max(dp[u],dp[v]-1);
		ans[u]+=ans[v];
	}
	if(!~dp[u])++ans[u],dp[u]=len[u];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>L>>S;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]>S){
			cout<<-1<<'\n';
			return 0;
		}
	}
	for(int i=2;i<=n;++i){
		cin>>f[i];
		G[f[i]].push_back(i);
	}
	dfs1(1);
	for(int i=1;i<=n;++i){
		int u=i;
		ll res=S;
		for(int j=18;j>=0;--j){
			if(res>=d[u][j]){
				res-=d[u][j];
				u=ff[u][j];
				len[i]+=1<<j;
			}
		}
		len[i]=min(len[i],L);
		--len[i];
	}
	dfs2(1);
	cout<<ans[1]<<'\n';
	return 0;
}