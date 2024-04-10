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
#define INF 2000000000
#define mod 1000000007
#define f first

#define rep(i,x) for(int i=0;i<x;i++)
ll dp[2005][2005];
ll dp2[2005][2005];
int n,k; char s[2005];
int main()
{
	srand((unsigned int)time(NULL));
	scanf("%d %d %s",&n,&k,&s);
	dp[n][0]=dp2[n][0]=1;
	for(int i=n-1;i>=0;i--)
	{
		int bel=s[i]-'a';
		for(int j=0;j<=k;j++)
		{
			ll x=1LL*bel*dp[i+1][j]+dp2[i+1][j];
			x%=mod;
			dp[i][j]=dp2[i][j]=x;
		}
		for(int j=i;j<n;j++)
		{
			int a=(j-i+1)*(n-j);
			for(int kk=a;kk<=k;kk++)
			{
				dp[i][kk]=(dp[i][kk]+1LL*('z'-s[j])*dp[j+1][kk-a])%mod;
			}
		}
	}
	printf("%lld\n",dp[0][k]);
}