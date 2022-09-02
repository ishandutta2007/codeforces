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

int dp[30005][1005];

int n,m;
int a[30005];
int c[30005];

int main()
{
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		c[a[i]]++;
	}
	memset(dp,-1,sizeof(dp));
	dp[m][500] = c[m];
	int res = 0;
	for(int i=m;i<=30000;i++)
	{
		for(int j=0;j<=1000;j++)
		{
			if(dp[i][j] == -1) continue;
			res = max(res,dp[i][j]);
			int pre = m+j-500;
			if(pre != 1 && i+pre-1 <= 30000)
			{
				dp[i+pre-1][j-1] = max(dp[i+pre-1][j-1],dp[i][j]+c[i+pre-1]);
			}
			if(i+pre <= 30000)
			{
				dp[i+pre][j] = max(dp[i+pre][j],dp[i][j]+c[i+pre]);
			}
			if(i+pre+1 <= 30000)
			{
				dp[i+pre+1][j+1] = max(dp[i+pre+1][j+1],dp[i][j]+c[i+pre+1]);
			}
		}
	}
	cout << res << endl;
}