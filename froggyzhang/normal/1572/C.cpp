#include<bits/stdc++.h>
using namespace std;
#define N 3005
typedef long long ll;
int n,a[N],dp[N][N];
vector<int> p[N],g[N];
int dfs(int l,int r){
	if(~dp[l][r])return dp[l][r];
	if(l>r)return dp[l][r]=0;
	dp[l][r]=dfs(l,r-1);
	for(auto p:g[r]){
		if(p>=l)dp[l][r]=max(dp[l][r],dfs(l,p-1)+dfs(p+1,r)+1);	
	}
	return dp[l][r];
}
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i)p[i].clear(),g[i].clear();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			dp[i][j]=-1;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		p[a[i]].push_back(i);
	}
	for(int i=1;i<=n;++i){
		if(p[i].size()>1){
			for(int j=0;j<(int)p[i].size();++j){
				for(int k=0;k<j;++k){
					g[p[i][j]].push_back(p[i][k]+1);	
				}
			}
		}
	}
	cout<<n-1-dfs(1,n)<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}