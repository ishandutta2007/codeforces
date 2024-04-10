#include <bits/stdc++.h>
const int mod=998244353;
int n,k,ans=0,a[1005],f[1005][1005],pre[1005][1005];

int solve(int lim){
	int ans=0;
	f[0][0]=pre[0][0]=1;
	int p=0;
	for(int i=1;i<=n;++i){
		while (a[i]-a[p+1]>=lim)p++;
		for(int j=1;j<=k;++j)f[i][j]=pre[p][j-1];
		for(int j=0;j<=k;++j)pre[i][j]=(pre[i-1][j]+f[i][j])%mod;
	}for(int i=1;i<=n;++i)ans=(ans+f[i][k])%mod;
	return ans;
}

int main(){
	scanf("%d%d",&n,&k);
	int max=0;
	for(int i=1;i<=n;++i){scanf("%d",&a[i]);max=std::max(max,a[i]);}
	std::sort(a+1,a+n+1);
	for(int i=1;i<=max/(k-1);++i)
		ans=(ans+solve(i))%mod;
	printf("%d",ans);
	return 0;
}