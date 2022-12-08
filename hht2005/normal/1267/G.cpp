#include<bits/stdc++.h>
using namespace std;
const int N=110,M=10010;
int c[N];
double dp[N][M],f[N],ans;
int main() {
	int n,m=0,x;
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++) {
		scanf("%d",c+i);
		m+=c[i];
	}
	for(int i=0;i<n;i++)
		f[i]=0.5*x*n/(n-i)+0.5*x;
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=i;j>=1;j--)
			for(int k=m;k>=c[i];k--)
				dp[j][k]+=dp[j-1][k-c[i]]/(n-j+1)*j;
	for(int i=0;i<n;i++)
		for(int j=0;j<=m;j++)
			ans+=dp[i][j]*min(1.0*(m-j)/(n-i),f[i]);
	printf("%.11lf\n",ans);
	return 0;
}