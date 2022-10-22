#include <stdio.h>

using namespace std;

long long dp[1000005][3][2], k, n, wSum[1000005], bSum[1000005], mod=1000000007;
char input[1000005];

int main()
{
	scanf("%d%d", &n, &k);
	scanf("%s", input);
	input[n]='X';
	dp[0][0][0]=1;
	wSum[0]=0;
	bSum[0]=0;
	for(int i=1; i <= n; ++i){
		wSum[i]=wSum[i-1]+(input[i-1]=='W'?1:0);
		bSum[i]=bSum[i-1]+(input[i-1]=='B'?1:0);
	}
	for(int i=0; i < n; ++i){
		long long s[3];
		for(int j=0; j < 3; ++j)
			s[j]=dp[i][j][0]+dp[i][j][1];
		if(i+k <= n && input[i+k] != 'B' && wSum[i+k]-wSum[i] == 0)
			dp[i+k][1][1]=(dp[i+k][1][1]-dp[i][1][0]+s[0]+mod)%mod;
		if(i+k <= n && input[i+k] != 'W' && bSum[i+k]-bSum[i] == 0)
			dp[i+k][2][1]=(dp[i+k][2][1]-dp[i][2][0]+s[1]+mod)%mod;
		for(int j=0; j < 3; ++j){
			if(input[i] == 'X')
				dp[i+1][j][0]=(dp[i+1][j][0]+2*dp[i][j][0]+dp[i][j][1])%mod;
			else
				dp[i+1][j][0]=(dp[i+1][j][0]+s[j])%mod;
		}
	}
	printf("%I64d", (dp[n][2][0]+dp[n][2][1])%mod);
	return 0;
}