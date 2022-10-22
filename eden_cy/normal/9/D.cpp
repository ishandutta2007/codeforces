#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define N 40

typedef long long ll;

ll dp[N][N];
ll dfs(int n,int h) {
	if(h==0) return 0;
	if(n==1) return h==1;
	if(~dp[n][h]) return dp[n][h];
	dp[n][h]=dfs(n-1,h-1)<<1;
	FOR(i,1,n-2) FOR(h1,1,min(h-1,i)) {
		int j=n-1-i;
		if(h1==h-1) FOR(h2,1,min(h-1,j)) dp[n][h]+=dfs(i,h1)*dfs(j,h2);
		else if(j>=h-1) dp[n][h]+=dfs(i,h1)*dfs(j,h-1);
	}
	return dp[n][h];
}
int main() {
	memset(dp,-1,sizeof(dp));
	int n,h;
	scanf("%d%d",&n,&h);
	ll res=0;
	FOR(i,h,n) res+=dfs(n,i);
	printf("%lld\n",res);
	return 0;
}