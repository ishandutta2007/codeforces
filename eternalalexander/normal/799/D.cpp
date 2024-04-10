#include <bits/stdc++.h>
const int inf=1e6;
#define ll long long
ll dp[45][100005];
int a,b,h,w,n,v[100005];

int solve(int a,int b){
	for(int i=0;i<=40;++i)for(int j=0;j<=100000;++j)dp[i][j]=-inf;
	dp[1][h]=w;
	for(int i=1;i<=n+1&&i<=41;++i){
		for(int j=0;j<=100000;++j){
			dp[i+1][j]=std::min((ll)inf,std::max(dp[i][j]*v[i],dp[i+1][j]));
			if (j<=b)dp[i+1][std::min((ll)j*v[i],(ll)b)]=std::max(dp[i][j],dp[i+1][std::min((ll)j*v[i],(ll)b)]);
			if (j>=b&&dp[i][j]>=a)return i-1;
		}
	}return 1e7;
}

int main(){
	scanf("%d%d%d%d%d",&a,&b,&h,&w,&n);
	for(int i=1;i<=n;++i)scanf("%d",&v[i]);
	std::sort(v+1,v+n+1);std::reverse(v+1,v+n+1);
	int d=std::min(solve(a,b),solve(b,a));
	if (d>1e6)printf("-1");
	else printf("%d",d);
	return 0;
}