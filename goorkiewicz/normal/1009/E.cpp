//#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
using namespace std;

const long long mod = 998244353LL;
int n, i;
long long dp [1000001];
long long c [1000001];
long long SumDP, SumC;

int main ()
	{
	scanf ("%d",&n);
	for (i=1; i<=n; i++)
		scanf ("%lld",&c[i]);
	for (i=1; i<=n; i++)
		c[i]=((c[i]+c[i-1])%mod);
	dp[0]=0LL;
	for (i=1; i<=n; i++)
		{
		dp[i]=(SumDP+SumC+c[i])%mod;
		SumDP+=dp[i];
		SumDP%=mod;
		SumC*=2LL;
		SumC+=c[i];
		SumC%=mod;
		}
	printf ("%lld\n",dp[n]);
	return 0;
	}