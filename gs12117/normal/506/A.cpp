#include<stdio.h>
const int m=30010;
int n,d;
int dp[1010][30100];
int gnum[30100];
int mind,maxd;
int ans;
int main(){
	int i,j,t;
	scanf("%d%d",&n,&d);
	j=0;
	for(i=d;i>1;i--){
		j+=i;
		if(j>m)break;
	}
	mind=i;
	j=0;
	for(i=d;;i++){
		j+=i;
		if(j>m)break;
	}
	maxd=i+10;
	for(i=0;i<n;i++){
		scanf("%d",&t);
		gnum[t]++;
	}
	for(i=mind;i<=maxd;i++){
		for(j=0;j<m;j++){
			dp[i-mind][j]=-999999999;
		}
	}
	dp[d-mind][d]=0;
	ans=0;
	for(i=0;i<m;i++){
		for(j=mind;j<=maxd;j++){
			dp[j-mind][i]+=gnum[i];
			if(ans<dp[j-mind][i])ans=dp[j-mind][i];
			if(j!=mind&&dp[j-mind-1][i+j-1]<dp[j-mind][i])dp[j-mind-1][i+j-1]=dp[j-mind][i];
			if(dp[j-mind][i+j]<dp[j-mind][i])dp[j-mind][i+j]=dp[j-mind][i];
			if(j!=maxd&&dp[j-mind+1][i+j+1]<dp[j-mind][i])dp[j-mind+1][i+j+1]=dp[j-mind][i];
		}
	}
	printf("%d",ans);
	return 0;
}