#include<stdio.h>
#include<algorithm>
using namespace std;
char b[100001];
char c[100001];
long long dp[100001][2][2];
int main(){
	int a;
	scanf("%d%s%s",&a,b,c);
	dp[0][0][0]=1;
	int mod=1000000007;
	for(int i=0;i<a;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				if(b[i]!='?'&&c[i]!='?'){
					if(b[i]<c[i])dp[i+1][j|1][k]=(dp[i+1][j|1][k]+dp[i][j][k])%mod;
					else if(b[i]>c[i])dp[i+1][j][k|1]=(dp[i+1][j][k|1]+dp[i][j][k])%mod;
					else dp[i+1][j][k]=(dp[i+1][j][k]+dp[i][j][k])%mod;
				}else if(c[i]!='?'){
					dp[i+1][j|1][k]=(dp[i+1][j|1][k]+dp[i][j][k]*(c[i]-'0'))%mod;
					dp[i+1][j][k]=(dp[i+1][j][k]+dp[i][j][k])%mod;
					dp[i+1][j][k|1]=(dp[i+1][j][k|1]+dp[i][j][k]*('9'-c[i]))%mod;
				}else if(b[i]!='?'){
					dp[i+1][j][k|1]=(dp[i+1][j][k|1]+dp[i][j][k]*(b[i]-'0'))%mod;
					dp[i+1][j][k]=(dp[i+1][j][k]+dp[i][j][k])%mod;
					dp[i+1][j|1][k]=(dp[i+1][j|1][k]+dp[i][j][k]*('9'-b[i]))%mod;
				}else{
					dp[i+1][j][k|1]=(dp[i+1][j][k|1]+dp[i][j][k]*45)%mod;
					dp[i+1][j|1][k]=(dp[i+1][j|1][k]+dp[i][j][k]*45)%mod;
					dp[i+1][j][k]=(dp[i+1][j][k]+dp[i][j][k]*10)%mod;
				}
			}
		}
	}
	printf("%d\n",(int)dp[a][1][1]);
}