#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 200020
inline int read(){
	int x=0,f=1;
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
int n,a[N],tot,b[N],mn[N],dp[N][2];
vector<int> G[N];
ll ans;
void dfs(int u,int fa){
	mn[u]=a[u];
	if(fa)mn[u]=min(mn[u],mn[fa]);
	if(b[u]==-1)++dp[u][0];
	else if(b[u]==1)++dp[u][1];
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);
		dp[u][0]+=dp[v][0];
		dp[u][1]+=dp[v][1];
	}
	int x=min(dp[u][0],dp[u][1]);
	ans+=2LL*x*mn[u];
	dp[u][0]-=x,dp[u][1]-=x;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		int p=read(),q=read();
		b[i]=p-q;
		tot+=b[i];
	}
	if(tot){
		printf("-1\n");return 0;
	}
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v),G[v].push_back(u);
	}
	dfs(1,0);
	printf("%I64d\n",ans);
	return 0;
}