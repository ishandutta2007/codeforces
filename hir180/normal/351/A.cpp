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
#define INF 1e12
#define f first
#define s second
#define rep(i,x) for(int i=0;i<x;i++)
double dp[4005][2005];
double sum[4005];
int main()
{
	srand((unsigned int)time(NULL));
	int n; vector<double>vec;
	scanf("%d",&n);
	for(int i=0;i<2*n;i++)
	{
		double x; scanf("%lf",&x);
		vec.pb(x);
	}
	for(int i=1;i<=2*n;i++) sum[i]=sum[i-1]+vec[i-1];
	for(int i=0;i<=2*n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			dp[i][j]=INF;
		}
	}
	dp[0][0]=0.0;
	for(int i=0;i<2*n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			double x=vec[i];
			if(dp[i][j]==INF) continue;
			if(abs(dp[i+1][j]-sum[i+1])>abs(dp[i][j]+(double)floor(x)-sum[i+1]))
			{
				dp[i+1][j]=dp[i][j]+(double)floor(x);
			}
			
			if(j!=n)
			{
				if(abs(dp[i+1][j+1]-sum[i+1])>abs(dp[i][j]+(double)ceil(x)-sum[i+1]))
				{
					dp[i+1][j+1]=dp[i][j]+(double)ceil(x);
				}
			}
		}
	}
	printf("%.3f\n",abs(sum[2*n]-dp[2*n][n]));
}