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
vector<int>edge[2050];
int n;
int x[2050];
int dp[2050];
int val[2050];
int sub[2050];
void dfs(int v)
{
	int maxv = 0;
	int sum = 0;
	sub[v] = 1;
	for(int i=0;i<edge[v].size();i++)
	{
		dfs(edge[v][i]);
		maxv = max(maxv,val[edge[v][i]]+x[edge[v][i]]);
	}
	for(int i=0;i<edge[v].size();i++)
	{
		sum += dp[edge[v][i]] + (maxv-val[edge[v][i]]-x[edge[v][i]]);
	}
	dp[v] = sum;
	val[v] = maxv; 
	return;
}
int main()
{
	cin >> n;
	for(int i=0;i<(1<<n)*2-2;i++)
	{
		cin >> x[i+2];
	}
	for(int i=2;i<=(1<<n)*2-1;i++)
	{
		edge[i/2].pb(i);
	}
	dfs(1); cout << dp[1] << endl;
}