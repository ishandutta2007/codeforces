#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
int n,k,rt,dp[N],ans[N];
vector<int> G[N];
void dfs(int u,int fa){
	if(G[u].size()==1){
		dp[u]=0,ans[u]=0;
		return;
	}
	vector<int> A;
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);
		ans[u]+=ans[v];
		A.push_back(dp[v]+1);
	}
	sort(A.begin(),A.end());
	int p=0;
	while(p<(int)A.size()-1&&A[p]+A[p+1]<=k)++p;
	ans[u]+=(int)A.size()-p-1;
	dp[u]=A[p];
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
	for(int i=1;i<=n;++i){
		if(G[i].size()>=2){
			rt=i;
			break;
		}
	}
	dfs(rt,0);
	cout<<ans[rt]+1<<'\n';
	return 0;
}