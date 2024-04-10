#include<stdio.h>
#include<algorithm>
int n,m;
int a[300100];
int gsize,lgn;
int dp[5010][5010];
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	std::sort(a,a+n);
	gsize=n/m;
	lgn=n%m;
	dp[0][0]=0;
	for(i=0;i<m;i++){
		for(j=0;j<=lgn&&j<=i;j++){
			if(i+j!=0)dp[i][j]+=a[i*gsize+j]-a[i*gsize+j-1];
			if(dp[i+1][j]<dp[i][j])dp[i+1][j]=dp[i][j];
			if(dp[i+1][j+1]<dp[i][j])dp[i+1][j+1]=dp[i][j];
		}
	}
	printf("%d",a[n-1]-a[0]-dp[m][lgn]);
}