#include<stdio.h>
#include<algorithm>
using namespace std;
int d[10];
long long dp[10][101];
int C[1000][1000];
int main(){
	int a;
	int mod=1000000007;
	scanf("%d",&a);
	for(int i=0;i<10;i++){
		scanf("%d",d+i);
	}
	C[0][0]=1;
	for(int i=0;i<999;i++){
		for(int j=0;j<=i;j++){
			C[i+1][j]=(C[i+1][j]+C[i][j])%mod;
			C[i+1][j+1]=(C[i+1][j+1]+C[i][j])%mod;
		}
	}
	int ret=0;
	for(int i=1;i<10;i++){
		int e=d[i];
		d[i]=max(0,d[i]-1);
		for(int j=0;j<10;j++)
			for(int k=0;k<100;k++)
				dp[j][k]=0LL;
		for(int j=d[0];j<a;j++)
			dp[0][j]=1LL;
		for(int j=0;j<9;j++){
			for(int k=0;k<a;k++){
				if(!dp[j][k])continue;
				for(int l=d[j+1];k+l<a;l++){
					dp[j+1][k+l]=(dp[j+1][k+l]+dp[j][k]*C[k+l][l])%mod;
				}
			}
		}
		for(int j=0;j<a;j++)ret=(ret+dp[9][j])%mod;
		d[i]=e;
	}
	printf("%d\n",ret);
}