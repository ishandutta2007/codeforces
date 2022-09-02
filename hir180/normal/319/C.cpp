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
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2e16
long long dp[100005];
long long a[100005],b[100005];
int deq[100005];
int n;
long long f(int i,int x)
{
	return dp[i]+x*b[i];
}

bool check(int f1,int f2,int f3)
{
	double a1,a2,a3,b1,b2,b3;
	a1=1.0*b[f1];
	a2=1.0*b[f2];
	a3=1.0*b[f3];
	b1=1.0*dp[f1];
	b2=1.0*dp[f2];
	b3=1.0*dp[f3];
	return (a2-a1)*(b3-b2) >= (b2-b1)*(a3-a2);
}

void solve()
{
	int s=0,t=0;
	fill(dp,dp+n+1,INF);
	dp[1]=0;
	for(int i=1;i<n;i++)
	{
		while(s+1<t && check(deq[t-2],deq[t-1],i)) t--;
		deq[t++]=i;
		while(s+1<t && f(deq[s],a[i+1]) >= f(deq[s+1],a[i+1])) s++;
		dp[i+1]=f(deq[s],a[i+1]);
	}
	printf("%lld\n",dp[n]);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&b[i]);
	}
	solve();
}