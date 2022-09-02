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
#define INF 1000000005
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int x[1000005],n;
ll dp[1000005];
vector<P>use[1000005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&x[i]);

	for(int i=1;i<=n;)
	{
		if(x[i] <= x[i+1])
		{
			int nx = i+1;
			while(nx <= n && x[nx-1] <= x[nx]) nx++;
			//[i,nx-1]
			use[nx-1].pb(mp(i,x[nx-1]-x[i]));
			if(i+1 <= nx-1) use[nx-1].pb(mp(i+1,x[nx-1]-x[i+1]));
			if(i <= nx-2) use[nx-2].pb(mp(i,x[nx-2]-x[i]));
			if(i+1 <= nx-2) use[nx-2].pb(mp(i+1,x[nx-2]-x[i+1]));
			if(nx != n+1) i = nx-1; else break;
		}
		else
		{
			int nx = i+1;
			while(nx <= n && x[nx-1] > x[nx]) nx++;
			//[i,nx-1]
			use[nx-1].pb(mp(i,x[i]-x[nx-1]));
			if(i+1 <= nx-1) use[nx-1].pb(mp(i+1,x[i+1]-x[nx-1]));
			if(i <= nx-2) use[nx-2].pb(mp(i,x[i]-x[nx-2]));
			if(i+1 <= nx-2) use[nx-2].pb(mp(i+1,x[i+1]-x[nx-2]));
			if(nx != n+1) i = nx-1; else break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		dp[i] = dp[i-1];
		for(int j=0;j<use[i].size();j++)
		{
			dp[i] = max(dp[i],dp[use[i][j].fi-1]+(ll)use[i][j].sc);
		}
	}
	cout << dp[n] << endl;
}