#include<stdio.h>
#include<algorithm>
int n,m,s;
int a[200];
int ans;
int dp[200][50000];
int main(){
	int i,j,k;
	scanf("%d%d%d",&n,&m,&s);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	if(s>n*(n-1)/2){
		std::sort(a,a+n);
		for(i=0;i<m;i++){
			ans+=a[i];
		}
		printf("%d",ans);
		return 0;
	}
	s+=(m-1)*m/2;
	for(i=0;i<=m;i++){
		for(j=0;j<=s;j++){
			dp[i][j]=999999999;
		}
	}
	dp[0][0]=0;
	for(i=0;i<n;i++){
		for(j=i;j>=0;j--){
			if(j>=m)continue;
			for(k=0;k+i<=s&&k<=i*(i-1)/2;k++){
				if(dp[j+1][k+i]>dp[j][k]+a[i]){
					dp[j+1][k+i]=dp[j][k]+a[i];
				}
			}
		}
	}
	ans=999999999;
	for(i=0;i<=s;i++){
		if(ans>dp[m][i]){
			ans=dp[m][i];
		}
	}
	printf("%d",ans);
	return 0;
}