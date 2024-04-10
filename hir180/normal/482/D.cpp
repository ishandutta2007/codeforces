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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)

int n;
vector<int>edge[100005];
ll dp[100005][2];
void calc(int v)
{
	ll tmp[2][2];
	int cur = 0,nxt = 1;
	tmp[cur][0] = 0;
	tmp[cur][1] = 1;
	for(int j=0;j<edge[v].size();j++)
	{
		tmp[nxt][0] = 0;
		tmp[nxt][1] = 0;
		calc(edge[v][j]);
		for(int a=0;a<2;a++)
		{
			for(int b=0;b<2;b++)
			{
				tmp[nxt][(a+b)%2] += (tmp[cur][a] * dp[edge[v][j]][b]);
			}
		}
		tmp[nxt][0] %= mod;
		tmp[nxt][1] %= mod;
		swap(cur,nxt);
	}
	dp[v][0] = tmp[cur][0]*2%mod;
	dp[v][1] = tmp[cur][1]*2%mod;
	//all the same
	ll x = 1;
	for(int j=0;j<edge[v].size();j++)
	{
		x = (x*dp[edge[v][j]][0])%mod;
	}
	dp[v][1] = (dp[v][1]+mod-x)%mod;

	ll y[2][2][3] = {};
	cur = 0,nxt = 1; y[0][1][0] = 1;
	for(int j=0;j<edge[v].size();j++)
	{
		for(int a=0;a<2;a++)for(int b=0;b<3;b++)y[nxt][a][b]=0;
		for(int jj=0;jj<2;jj++)
		{
			y[nxt][jj][0] += y[cur][jj][0];
			y[nxt][jj][1] += y[cur][jj][1];
			y[nxt][jj][2] += y[cur][jj][2];
			y[nxt][1-jj][1] += y[cur][jj][0] * dp[edge[v][j]][1]%mod;
			y[nxt][1-jj][2] += y[cur][jj][1] * dp[edge[v][j]][1]%mod;
			y[nxt][1-jj][1] += y[cur][jj][2] * dp[edge[v][j]][1]%mod;
		}
		for(int a=0;a<2;a++)for(int b=0;b<3;b++)y[nxt][a][b]%=mod;
		swap(cur,nxt);
	}

	dp[v][0] = (dp[v][0]+mod*2ll-y[cur][0][1]-y[cur][0][0]+1)%mod;
	dp[v][1] = (dp[v][1]+mod*2ll-y[cur][1][1]-y[cur][1][0]+1)%mod;
	return;
}
int main()
{
	cin >> n;
	for(int i=2;i<=n;i++)
	{
		int x; scanf("%d",&x);
		edge[x].pb(i);
	}
	calc(1);
	//for(int i=1;i<=n;i++) cout << dp[i][0] << "  " << dp[i][1] << endl;
	printf("%lld\n",(dp[1][0]+dp[1][1]+mod-1)%mod);
}