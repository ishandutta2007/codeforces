#include<stdio.h>
#include<algorithm>
using namespace std;
long long C[1000][1000];
long long dp[101][10001];
long long ad[100][101];
int main(){
	C[0][0]=1LL;
	int mod=1000000007;
	for(int i=0;i<999;i++)
		for(int j=0;j<=i;j++){
			C[i+1][j]=(C[i+1][j]+C[i][j])%mod;
			C[i+1][j+1]=(C[i+1][j+1]+C[i][j])%mod;
		}
	int a,c;
	long long b;
	scanf("%d%I64d%d",&a,&b,&c);
	for(int i=0;i<a;i++){
		for(int j=0;j<=a;j++){
			long long v=C[a][j];
			long long s=1LL;
			long long t=(b-i-1)/a+1;
			while(t){
				if(t%2){
					s=s*v%mod;
				}
				v=v*v%mod;
				t/=2;
			}
			ad[i][j]=s;
		}
	}
	dp[0][0]=1LL;
	for(int i=0;i<a;i++){
		for(int j=0;j<=c;j++){
			if(!dp[i][j])continue;
			for(int k=0;k<=a&&j+k<=c;k++){
				dp[i+1][j+k]=(dp[i+1][j+k]+dp[i][j]*ad[i][k])%mod;
			}
		}
	}
	printf("%I64d\n",dp[a][c]);
}