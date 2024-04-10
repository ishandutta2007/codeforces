#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define MOD 1000000007
using namespace std;

int dp[1005][60][1005];

int main(){
	for(int n=0; n < 1005; ++n)
		dp[n][0][n]=1;
	for(int n=1; n < 1004; ++n)
		for(int k=1; k*(k+1) <= 2*n; ++k)
			for(long long m=0; m <= n; ++m){
				dp[n][k][m]=(dp[n-k][k][m]+(m+1)*dp[n-k+1][k-1][m+1])%MOD;
			}
	int t;
	scanf("%d", &t);
	while(t--){
		int n, k;
		scanf("%d%d", &n, &k);
		int sum=0;
		if(k*(k+1) <= 2*n)
			for(int m=0; m <= n; ++m)
				sum=(sum+dp[n][k][m])%MOD;
		printf("%d\n", sum);
	}
	return 0;
}