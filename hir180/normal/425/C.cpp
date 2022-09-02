//IOI2014
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
#define geta 100000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int dp[100005][305];
int a[100005],b[100005],n,m,s,e;
vector<int>posa[100005];
vector<int>posb[100005];
int main()
{
	scanf("%d %d %d %d",&n,&m,&s,&e);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	for(int i=1;i<=n;i++) posa[a[i]].pb(i);
	for(int i=1;i<=m;i++) posb[b[i]].pb(i);
	
	int lim = s/e;
	for(int i=0;i<100005;i++) for(int j=0;j<305;j++) dp[i][j]=INF;
	dp[0][0]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=lim;j++)
		{
			dp[i+1][j] = dp[i][j];
		}
		for(int j=1;j<=lim;j++)
		{
			int x = upper_bound(posb[a[i+1]].begin(),posb[a[i+1]].end(),dp[i][j-1])-posb[a[i+1]].begin();
			if(x == posb[a[i+1]].size()) continue;
			x = posb[a[i+1]][x];
			dp[i+1][j] = min(dp[i+1][j],x);// cout << i+1 << " " << j << " " << x << endl;
		}
	}
	int res=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=lim;j>=0;j--)
		{
			ll cur=e*j+dp[i][j]+i;
			if(cur <= s) {res = max(res,j); break;}
		}
	}
	cout << res << endl;
}