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
	ll a,b,c;
	scanf("%lld%lld%lld",&a,&b,&c);
	
	if(a < c) printf("1 ");
	else printf("-1 ");
	
	if(a*b <= c) printf("-1 ");
	else printf("%d ",b);
	
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}