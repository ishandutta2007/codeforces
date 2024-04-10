//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
//HIR180
//IOI2014N
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
#define f first
#define s second
#define rep(i,x) for(int i=0;i<x;i++)
int val[2005],num[2005];
int n,k;
bool ok(ll rng)
{
	//dp[i][j]...
	int dp[2005];
	fill(dp,dp+2005,INF); dp[1]=0;
	for(int s=1;s<=n;s++) dp[s]=s-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=n;j>=i+1;j--)
		{
			//[i,j]
			if(abs(val[i]-val[j])<=(j-i)*rng)
			{
				dp[j]=min(dp[j],dp[i]+j-i-1);
			}
		}
	}
	for(int i=1;i<=n;i++) if(dp[i]+n-i<=k) return 1; return 0;
}
int main()
{
	srand((unsigned int)time(NULL));
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&val[i]);
	//(lb,ub]
	ll lb=-1;
	ll ub=1e10;
	while(ub-lb>1)
	{
		ll mid=(lb+ub)/2;
		if(ok(mid)) ub=mid;
		else lb=mid;
	}
	printf("%lld\n",ub);
}