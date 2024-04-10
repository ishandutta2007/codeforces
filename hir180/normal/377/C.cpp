//Daily Lunch Special Tanoshii !!
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
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
#define s(x) scanf("%d",&x)
#define rep(i,x) for(int i=0;i<x;i++)
int dp[1<<20];
int main()
{
	int n;
	scanf("%d",&n);
	vector<int>vec;
	for(int i=0;i<n;i++)
	{
		int f; scanf("%d",&f);
		vec.pb(f);
	}
	int m;
	vector<P>query;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		string a; int b;
		int c;
		cin >> a >> b;
		if(a=="p") c=1;
		else c=2;
		query.pb(mp(c,b));
	}
	sort(vec.begin(),vec.end(),greater<int>());
	while(vec.size()>m) vec.pop_back();
	int cur=0,nex=1;
	for(int i=0;i<(1<<m);i++)
	{
		int v=__builtin_popcount(i);
		if(v==0) dp[i]=0;
		else
		{
			if(query[m-v].second==1) dp[i]=-INF;
			else dp[i]=INF;
		}
	}
	for(int x=1;x<=(1<<m);x++)
	{
		int v=__builtin_popcount(x);
		for(int i=0;i<m;i++)
		{
			if(x&(1<<i))
			{
				if(query[m-v].second==1)
				{
					if(query[m-v].first==1)
					
					{
						dp[x]=max(dp[x],dp[x^(1<<i)]+vec[i]);
					}
					else
					{
						dp[x]=max(dp[x],dp[x^(1<<i)]);
					}
				}
				else
				{
					if(query[m-v].first==1)
					
					{
						dp[x]=min(dp[x],dp[x^(1<<i)]-vec[i]);
					}
					else
					{
						dp[x]=min(dp[x],dp[x^(1<<i)]);
					}
				}
			}
		}
	}
	cout << dp[(1<<m)-1] << endl;
}