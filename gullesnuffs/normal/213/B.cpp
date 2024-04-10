#include <stdio.h>
#include <vector>
#define MOD 1000000007LL

using namespace std;

int n, a[12];

long long NCR[201][201];

int main()
{
	long long ans=0, Ans;
	int N;
	scanf("%d", &N);
	for(int i=0; i < 10; ++i)
		scanf("%d", a+i);
	for(int i=0; i <= 200; ++i)
		NCR[0][i]=0;
	NCR[0][0]=1;
	for(int i=1; i <= 200; ++i)
		for(int j=0; j <= 200; ++j){
			NCR[i][j]=0;
			if(j > 0)
				NCR[i][j]=(NCR[i][j]+NCR[i-1][j-1])%MOD;
			if(j < i)
				NCR[i][j]=(NCR[i][j]+NCR[i-1][j])%MOD;
		}
	for(int n=1; n <= N; ++n){
		long long dp[201][15];
		for(int j=0; j < 111; ++j)
			for(int k=0; k < 11; ++k)
				dp[j][k]=0;
		dp[n][0]=1;
		for(int j=0; j < 10; ++j)
			for(int k=n; k >= 0; --k){
				for(int m=a[j]; m <= k; ++m){
					if(j == 0){
						if(k)
							dp[k-m][j+1]=(dp[k-m][j+1]+dp[k][j]*NCR[k-1][m])%MOD;
					}
					else
						dp[k-m][j+1]=(dp[k-m][j+1]+dp[k][j]*NCR[k][m])%MOD;
				}
			}
		ans=(ans+dp[0][10])%MOD;
	}
	printf("%I64d", ans);
	return 0;
}