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
	ll a,b,n,m;
	scanf("%lld%lld%lld%lld",&a,&b,&n,&m);
	if(a>b) swap(a,b);
	
	if(a<m || a+b < n+m) printf("No\n");
	else printf("Yes\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}