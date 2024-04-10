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
int dp[5005][5005];
int num[5005];
int rui[5005];
int main()
{
	int n; scanf("%d",&n);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dp[i][j]=INF;
	for(int i=1;i<=n;i++) scanf("%d",&num[i]);
	for(int i=1;i<=n;i++) rui[i]=rui[i-1]+num[i];
	for(int i=1;i<=n;i++) dp[i][n]=n-i;
	for(int k=n-1;k>=1;k--)
	{
		int tail=n+1;
		int rval=INF;
		for(int i=1;i<=k;i++)
		{
			int cur=rui[k]-rui[i-1];
			while(tail>=k+1 && rui[tail-1]-rui[k]>=cur)
			{
				rval=min(rval,dp[k+1][tail-1]);
				tail--;
			}
			dp[i][k]=min(dp[i][k],rval+k-i);
		}
	}
	int ret=INF;
	for(int i=1;i<=n;i++) ret=min(ret,dp[1][i]);
	cout << ret << endl;
}