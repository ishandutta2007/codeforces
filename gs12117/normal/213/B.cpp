#include<stdio.h>
int n;
int cmb[110][110];
int mod=1000000007;
int a[12];
long long int dp[12][110];
long long int ans;
int main(){
	int i,j,k,cap;
	for(i=0;i<105;i++){
		cmb[i][0]=1;
		for(j=1;j<=i;j++){
			cmb[i][j]=cmb[i-1][j]+cmb[i-1][j-1];
			cmb[i][j]%=mod;
		}
	}
	scanf("%d",&n);
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	n--;
	for(cap=1;cap<10;cap++){
		a[cap]--;
		for(i=0;i<=10;i++){
			for(j=0;j<=n;j++){
				dp[i][j]=0;
			}
		}
		dp[0][0]=1;
		for(i=0;i<10;i++){
			for(j=a[i];j<=n;j++){
				for(k=j;k<=n;k++){
					dp[i+1][k]+=dp[i][k-j]*cmb[k][j];
					dp[i+1][k]%=mod;
				}
			}
		}
		for(i=0;i<=n;i++){
			ans+=dp[10][i];
			ans%=mod;
		}
		a[cap]++;
	}
	printf("%I64d",ans);
}