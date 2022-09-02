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
int n,t;
vector<int>task[105];
int dp[105][1005];
int rec(int dep,int node)
{
	if(dp[dep][node] >= 0) return dp[dep][node];
	if(dep > t || node == 0) return 0;
	int &ret = dp[dep][node];
	int x = task[t-dep].size();
	int pl = 0;
	for(int i=0;i<=min(x,node);i++)
	{
		ret = max(ret,pl+rec(dep+1,min(n,(node-i)*2)));
		if(i!=x) pl += task[t-dep][i];
	}
	return ret;
}
int main()
{
	cin >> n >> t;
	for(int i=0;i<n;i++)
	{
		int a,b; cin >> a >> b;
		task[a].pb(b);
	}
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=t;i++) sort(task[i].begin(),task[i].end(),greater<int>());
	cout << rec(0,1) << endl;
}