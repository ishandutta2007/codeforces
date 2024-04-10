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
int n;
int dp[500005];
int v[305],c[305];
vector<int>vec;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&v[i]);
	for(int i=0;i<n;i++) scanf("%d",&c[i]);
	int x = v[0];
	for(int i=1;i<n;i++) x = __gcd(x,v[i]);
	if(x > 1)
	{
		puts("-1"); return 0;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=1;j*j<=v[i];j++)
		{
			if(v[i]%j==0)
			{
				vec.pb(j);
				if(j*j != v[i]) vec.pb(v[i]/j);
			}
		}
	}
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	fill(dp,dp+500005,INF);
	for(int i=0;i<n;i++)
	{
		int a = lower_bound(vec.begin(),vec.end(),v[i])-vec.begin();
		dp[a] = min(dp[a],c[i]);
	}
	for(int i=vec.size()-1;i>=0;i--)
	{
		if(dp[i] == INF) continue;
		for(int j=0;j<n;j++)
		{
			int x = __gcd(vec[i],v[j]);
			if(x == v[j]) continue;
			int a = lower_bound(vec.begin(),vec.end(),x)-vec.begin();
			dp[a] = min(dp[a],dp[i]+c[j]);
		}
	}
	if(dp[0] == INF) puts("-1");
	else printf("%d\n",dp[0]);
}