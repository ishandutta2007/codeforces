#include <bits/stdc++.h>
#define INF 999999999999999999LL
using namespace std;

int p[10005];
long long dp[5005][5005];
long long S[10005];

int main(){
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	S[0]=0;
	for(int i=0; i < n; ++i){
		scanf("%d", p+i);
		S[i+1]=S[i]+p[i];
	}
	for(int i=0; i <= n; ++i)
	       for(int j=0; j <= k; ++j)
	       	dp[i][j]=-INF;	
 	dp[0][0]=0;	
	for(int i=0; i <= n; ++i)
		for(int j=0; j <= k; ++j){
			if(i+m <= n)dp[i+m][j+1]=max(dp[i+m][j+1], dp[i][j]+S[i+m]-S[i]);
			dp[i+1][j]=max(dp[i+1][j], dp[i][j]);
		}
	printf("%I64d\n", dp[n][k]);
}