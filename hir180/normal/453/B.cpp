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
int dp[105][(1<<17)];
int a[105];
int b[105];
int mask[61];
bool cmp(const int &c,const int &d)
{
	return a[c] < a[d];
}
int main()
{
	int n; cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) b[i] = i;
	sort(b+1,b+n+1,cmp);
	sort(a+1,a+n+1);
	for(int i=0;i<105;i++) for(int j=0;j<(1<<17);j++) dp[i][j] = INF;
	dp[0][0] = 0;
	int p[17]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
	for(int i=1;i<=60;i++)
	{
		for(int j=0;j<17;j++)
		{
			if(i % p[j] == 0)
			{
				mask[i] |= (1<<j);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<(1<<17);j++)
		{
			if(dp[i-1][j] == INF) continue;
			for(int k=1;k<=60;k++)
			{
				if((mask[k] & j) > 0) continue;
				dp[i][j | mask[k]] = min(dp[i][j | mask[k]],dp[i-1][j]+abs(a[i]-k));
			}
		}
	}
	int bestmask = -1,bestres = INF;
	for(int j=0;j<(1<<17);j++)
	{
		if(bestres > dp[n][j])
		{
			bestres = dp[n][j];
			bestmask = j;
		}
	}
	int zip[105];
	for(int i=n;i>=1;i--)
	{
		for(int k=1;k<=60;k++)
		{
			if((bestmask & mask[k]) != mask[k]) continue;
			if(bestres == dp[i-1][bestmask-mask[k]]+abs(a[i]-k))
			{
				bestmask = bestmask-mask[k];
				bestres = dp[i-1][bestmask];
				zip[i] = k;
				break;
			}
		}
	}
	int res[105];
	for(int i=1;i<=n;i++) res[b[i]] = zip[i];
	for(int i=1;i<=n;i++) printf("%d%c",res[i],i==n?'\n':' ');
}