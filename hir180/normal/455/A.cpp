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
int num[100005];
int a[100005];
ll dp[100005][2];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
		a[num[i]]++;
	}
	ll x=0,y=0,res=0;
	bool f = true;
	for(int i=1;i<=100000;i++)
	{
		dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
		dp[i][1] = dp[i-1][0] + 1LL*i*a[i];
	}
	printf("%lld\n",max(dp[100000][0],dp[100000][1]));
}