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
int dp[2005][2005];
int rui[2005][2005];
string s,p;
vector<int>x,y,v;
int res[2005];
int main()
{
	cin >> s >> p;
	for(int i=0;i<s.size();i++)
	{
		if(s[i] != p[0]) continue;
		int nx = 0;
		for(int j=i;j<s.size();j++)
		{
			if(s[j] == p[nx])
			{
				nx++;
				if(nx == p.size())
				{
					x.pb(i);
					y.pb(j);
					v.pb(j-i+1-p.size());
					break;
				}
			}
		}
	}
	for(int i=0;i<2005;i++) for(int j=0;j<2005;j++) dp[i][j] = INF;
	for(int i=0;i<2005;i++) for(int j=1;j<2005;j++) rui[i][j] = INF;
	dp[0][0] = 0;
	for(int i=1;i<=v.size();i++)
	{
		for(int j=1;j<=i;j++)
		{
			int beg = x[i-1];
			int d = lower_bound(y.begin(),y.end(),beg)-y.begin();
			dp[i][j] = min(dp[i][j],rui[d][j-1]+v[i-1]);
			rui[i][j] = min(rui[i-1][j],dp[i][j]);
		}
	}
	for(int i=1;i<=v.size();i++)
	{
		int a = INF;
		for(int j=1;j<=v.size();j++) a = min(a,dp[j][i]);
		if(a != INF)
		{
			int x = s.size();
			int y = i*p.size();
			for(int j=a;j<=x-y;j++) res[j] = i;
		}
	}
	for(int i=0;i<=s.size();i++) printf("%d%c",res[i],i==s.size()?'\n':' ');
}