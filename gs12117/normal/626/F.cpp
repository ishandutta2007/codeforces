#include<stdio.h>
#include<algorithm>
int n,m;
int a[210];
int dp[210][210][1010];
int mod=1000000007;
int main(){
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	std::sort(a,a+n);
	a[n]=a[n-1];
	dp[0][0][0]=1;
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++){
			for(k=0;k<=m;k++){
				if(k+j*(a[i+1]-a[i])<=m){
					dp[i+1][j][k+j*(a[i+1]-a[i])]+=(((long long int)dp[i][j][k])*(j+1))%mod;
					dp[i+1][j][k+j*(a[i+1]-a[i])]%=mod;
				}
				if(k+(j+1)*(a[i+1]-a[i])<=m){
					dp[i+1][j+1][k+(j+1)*(a[i+1]-a[i])]+=dp[i][j][k];
					dp[i+1][j+1][k+(j+1)*(a[i+1]-a[i])]%=mod;
				}
				if(j!=0&&k+(j-1)*(a[i+1]-a[i])<=m){
					dp[i+1][j-1][k+(j-1)*(a[i+1]-a[i])]+=(long long int)dp[i][j][k]*j%mod;
					dp[i+1][j-1][k+(j-1)*(a[i+1]-a[i])]%=mod;
				}
			}
		}
	}
	int ans=0;
	for(i=0;i<=m;i++){
		ans+=dp[n][0][i];
		ans%=mod;
	}
	printf("%d",ans);
	return 0;
}