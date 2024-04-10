#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

void solve(void)
{
	ll n,r;
	scanf("%lld%lld",&n,&r);
	
	if(r<n) printf("%lld\n",r*(r+1)/2);
	else printf("%lld\n",n*(n-1)/2 + 1);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}