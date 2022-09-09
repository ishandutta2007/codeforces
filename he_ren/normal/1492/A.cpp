#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

inline ll calc(ll p,ll a)
{
	return p%a? a - p%a: 0;
}

void solve(void)
{
	ll p,a,b,c;
	scanf("%lld%lld%lld%lld",&p,&a,&b,&c); 
	
	printf("%lld\n",min(calc(p,a), min(calc(p, b), calc(p, c))));
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}