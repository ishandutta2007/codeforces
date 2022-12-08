#include<bits/stdc++.h>
using namespace std;
const int maxn=1<<20;
int a[maxn],s[30];
long long f[20][maxn],dp[maxn];
int main() {
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	int n,m=0,S;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",a+i);
		m=max(m,a[i]);
		a[i]--;
	}
	S=(1<<m)-1;
	for(int i=1;i<=n;i++) {
		s[a[i]]++;
		for(int j=0;j<m;j++)
			if(a[i]!=j)f[a[i]][1<<j]+=s[j];
	}
	for(int i=0;i<m;i++)
		for(int j=1;j<1<<m;j++)
			f[i][j]=f[i][j-(j&-j)]+f[i][j&-j];
	for(int i=1;i<1<<m;i++)
		for(int j=0;j<m;j++)
			dp[i]=min(dp[i],dp[i^(1<<j)]+f[j][S^i]);
	printf("%lld\n",dp[S]);
	return 0;
}