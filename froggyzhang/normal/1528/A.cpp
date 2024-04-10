#include<bits/stdc++.h>
using namespace std;
#define N 100010
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
int T,n,a[N][2];
vector<int> G[N];
ll dp[N][2];
void dfs(int u,int fa){
	dp[u][0]=dp[u][1]=0;
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);
		dp[u][0]+=max(dp[v][0]+abs(a[u][0]-a[v][0]),dp[v][1]+abs(a[u][0]-a[v][1]));
		dp[u][1]+=max(dp[v][0]+abs(a[u][1]-a[v][0]),dp[v][1]+abs(a[u][1]-a[v][1]));
	}
}
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		G[i].clear();
	}
	for(int i=1;i<=n;++i){
		a[i][0]=read();
		a[i][1]=read();
	}
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	printf("%lld\n",max(dp[1][0],dp[1][1]));	
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}