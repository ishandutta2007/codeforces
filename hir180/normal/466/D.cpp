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
ll dp[2005][2005];
int main()
{
	int n,h;
	cin >> n >> h;
	int x[2005];
	for(int i=1;i<=n;i++) cin >> x[i];
	dp[0][0] = 1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(dp[i][j] == 0) continue;
			if(x[i+1]+j == h)
			{
				dp[i+1][j] = (dp[i+1][j]+dp[i][j])%mod;
				if(j>=1)
				{
					dp[i+1][j-1] = (dp[i+1][j-1]+dp[i][j]*j)%mod;
				}
			}
			if(x[i+1]+j+1 == h)
			{
				dp[i+1][j+1] = (dp[i+1][j+1]+dp[i][j])%mod;
				dp[i+1][j] = (dp[i+1][j]+dp[i][j]*(j+1LL))%mod;
			}
		}
	}
	cout << dp[n][0] << endl;
}