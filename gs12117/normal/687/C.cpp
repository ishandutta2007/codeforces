#include<stdio.h>
int n,m;
int c[510];
int dp[510][510];
int dpb[1010][1010];
int ans;
int main(){
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&c[i]);
	}
	dp[0][0]=1;
	for(i=0;i<n;i++){
		for(j=0;j<=m;j++){
			for(k=0;k<=m;k++){
				if(dp[j][k]==1){
					dpb[j][k]=1;
					dpb[j+c[i]][k]=1;
					dpb[j][k+c[i]]=1;
				}
			}
		}
		for(j=0;j<=m;j++){
			for(k=0;k<=m;k++){
				dp[j][k]=dpb[j][k];
			}
		}
	}
	ans=0;
	for(i=0;i<=m;i++){
		if(dp[i][m-i]==1){
			ans++;
		}
	}
	printf("%d\n",ans);
	for(i=0;i<=m;i++){
		if(dp[i][m-i]==1){
			printf("%d ",i);
		}
	}
	return 0;
}