#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int dp[5005][5005];

int main()
{
	int n,k,a,b;
	scanf("%d %d %d %d",&n,&a,&b,&k);
	dp[0][a] = 1;
	for(int i=0;i<k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(dp[i][j] == 0 || j == b) continue;
			int dif = (j>b?(j-b):(b-j));
			int und = max(1,j-dif+1);
			int up = min(n,j+dif-1);
			dp[i+1][und] = (dp[i+1][und]+dp[i][j])%mod;
			dp[i+1][up+1] = (dp[i+1][up+1]+(mod-dp[i][j])%mod)%mod;
		}
		for(int j=1;j<=n;j++)
		{
			dp[i+1][j] = (dp[i+1][j]+dp[i+1][j-1])%mod;
		}
		for(int j=1;j<=n;j++)
		{
			dp[i+1][j] = (dp[i+1][j]+(mod-dp[i][j])%mod)%mod;
		}
	}
	ll res = 0;
	for(int i=1;i<=n;i++)
	{
		if(i == b) continue;
		res = (res+1LL*dp[k][i])%mod;
	}
	printf("%lld\n",res);
}