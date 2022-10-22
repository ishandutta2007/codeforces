#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iostream>
#define MOD 1000000007
using namespace std;

int dp[2005][2005];

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i=1; i <= n; ++i)
		dp[1][i]=1;
	for(int i=2; i <= k; ++i)
		for(int j=1; j <= n; ++j)
			for(int m=j; m <= n; m += j){
				dp[i][m]=(dp[i][m]+dp[i-1][j])%MOD;
			}
	int ans=0;
	for(int i=1; i <= n; ++i)
		ans=(ans+dp[k][i])%MOD;
	printf("%d\n", ans);
	return 0;
}