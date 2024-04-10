#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T,n,dp[N];
vector<int> G[N];
void dfs(int u,int fa,int x){
	dp[u]=0;
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u,x);
		if(dp[v]==-1){
			dp[u]=-1;
		}
		if(dp[u]==-1)continue;
		if(dp[u]){
			if(dp[v]==x){dp[u]=-1;continue;}
			if(dp[v]+1==x&&dp[u]==x){dp[u]=-1;continue;}
			int tp=n+1;
			if(dp[v]+2<=x){
				tp=min(tp,dp[u]);
			}
			if(dp[u]<x){
				tp=min(tp,dp[v]+1);
			}
			dp[u]=tp;
		}	
		else{
			dp[u]=dp[v]+1;
			if(dp[u]>x)dp[u]=-1;
		}
	}
}
bool check(int x){
	dfs(1,0,x);
	return dp[1]!=-1;
}
void Solve(){
	n=read();
	for(int i=1;i<=n;++i)G[i].clear();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int l=1,r=n,ans=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=r=mid;
		}
		else{
			l=mid+1;
		}
	}
	printf("%d\n",ans);
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}