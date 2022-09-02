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
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int c[65][65][65];
int d[65][65][65];
int dp[65][65][125];
int main()
{
	srand((unsigned int)time(NULL));
	int n,m,r;
	cin >> n >> m >> r;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)for(int k=0;k<m;k++) if(i!=j) d[i][j][k]=INF;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)for(int k=0;k<=120;k++) dp[i][j][k]=INF;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				scanf("%d",&c[j][k][i]);
				d[j][k][i]=min(d[j][k][i],c[j][k][i]);
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int mid=0;mid<n;mid++)
		{
			for(int j=0;j<n;j++)
			{
				for(int k=0;k<n;k++)
				{
					d[j][k][i]=min(d[j][k][i],d[j][mid][i]+d[mid][k][i]);
				}
			}
		}
		
		{
			for(int j=0;j<n;j++)
			{
				for(int k=0;k<n;k++)
				{
					dp[j][k][0]=min(dp[j][k][0],d[j][k][i]);
				}
			}
		}
	}
	for(int i=1;i<=2*n;i++)
	{
		for(int mid=0;mid<n;mid++)
		{
			for(int j=0;j<n;j++)
			{
				for(int k=0;k<n;k++)
				{
					dp[j][k][i]=min(dp[j][k][i],dp[j][mid][i-1]+dp[mid][k][0]);
				}
			}
		}
	}
	while(r--)
	{
		int s,t,lim; cin >> s >> t >> lim;
		cout << dp[--s][--t][min(2*n,lim)] << endl;
	}
}