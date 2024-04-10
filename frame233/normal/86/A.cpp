#include<cstdio>
typedef long long ll;
inline ll max(ll a,ll b){return a>b?a:b;}
inline ll min(ll a,ll b){return a<b?a:b;}
int main()
{
	ll l,r;
	scanf("%lld %lld",&l,&r);
	ll t=1;
	while(t<=r) t*=10;
	ll p=min(max(t/2,l),r);
	printf("%lld\n",p*(t-1-p));
	return 0;
}