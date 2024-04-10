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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
ll dp[1005][1005];
ll dpend[1005][1005];
ll ans[1005][1005];
ll c[1005][1005];
ll sum[1005][1005];
ll f[1005];
int main()
{
	srand((unsigned int)time(NULL));
	int t; cin >> t;
	for(int i=0;i<=1000;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(j==0 || i==j) c[i][j]=1LL;
			else c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		}
	}
	f[0]=1LL; for(int i=1;i<=1000;i++) f[i]=(f[i-1]*i)%mod;
	dp[0][0]=1;
	for(int i=1;i<=1000;i++)
	{
		for(int sum=0;sum<=1000;sum++)
		{
			if(!dp[sum][i-1]) continue;
			int tot=0;
			for(int k=sum;k<=1000;k+=i)
			{
				dpend[k][i]=(dpend[k][i]+dp[sum][i-1])%mod;
				if(k!=sum) dp[k][i]=(dp[k][i]+dp[sum][i-1])%mod;
			}
		}
	}
	for(int i=0;i<=1000;i++) for(int j=1;j<=1000;j++) dpend[i][j]=(dpend[i][j]*f[j])%mod;
	//kx+y
	//x k
	//dpend[x][k]*(y+1)
	//k2
	for(int k=2;k<=1000;k++)
	{
		sum[k][0]=dpend[0][k];
		ll tot=0;
		for(int xy=1;xy<=1000;xy++)
		{
			tot=(tot+dpend[xy-1][k])%mod;
			sum[k][xy]=sum[k][xy-1];
			sum[k][xy]+=tot;
			sum[k][xy]=(sum[k][xy]+dpend[xy][k])%mod;
		}
	}
	while(t--)
	{
		int n,k; scanf("%d %d",&n,&k);
		
		if(k==1)
		{
			printf("%d\n",n*(n+1)/2);
		}
		else
		{
			ll ret=0LL;
			for(int i=0;i<=n-k;i++)
			{
				ret=(ret+(sum[k][i]*c[n-i-2][k-2])%mod)%mod;
			}
			printf("%lld\n",ret);
		}
	}
}