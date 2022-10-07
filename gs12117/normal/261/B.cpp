#include<stdio.h>
int n,p;
double dp[55][55];
double ans;
int a[55];
int main(){
	int i,j,k,l;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&p);
	for(i=1;i<=n;i++){
		for(j=0;j<=n;j++){
			for(k=0;k<=p;k++){
				dp[j][k]=0;
			}
		}
		dp[0][0]=1;
		for(j=0;j<n;j++){
			for(k=i;k>=0;k--){
				for(l=0;l<=p;l++){
					if(l+a[j]<=p)dp[k+1][l+a[j]]+=dp[k][l]*((double)i-k)/(n-j);
					dp[k][l]*=((double)n-i+k-j)/(n-j);
				}
			}
		}
		for(j=0;j<=p;j++){
			ans+=dp[i][j];
		}
	}
	printf("%.30lf",ans);
}