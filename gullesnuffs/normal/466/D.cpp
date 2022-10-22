#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int a[2005];
long long dp[2005][2005];

int main(){
	int n, h;
	scanf("%d%d", &n, &h);
	for(int i=0; i < n; ++i)
		scanf("%d", a+i);
	dp[0][0]=1;
	for(int i=0; i < n; ++i)
		for(int j=0; j <= i; ++j){
			if(a[i]+j == h){
				dp[i+1][j]=(dp[i+1][j]+dp[i][j])%MOD;
				if(j)
					dp[i+1][j-1]=(dp[i+1][j-1]+j*dp[i][j])%MOD;
			}
			if(a[i]+j+1 == h){
				dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j])%MOD;
				dp[i+1][j]=(dp[i+1][j]+(j+1)*dp[i][j])%MOD;
			}

		}
	printf("%I64d\n", dp[n][0]);
}