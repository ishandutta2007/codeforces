#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
ll T;
ll dis(ll a,ll b,ll c,ll d)
{
	return abs(a-c)+abs(b-d);
}
signed main(){
	T=read();
	while(T--)
	{
		ll n,m,r,c;
		n=read();
		m=read();
		r=read();
		c=read();
		printf("%lld\n",max(dis(1,1,r,c),max(dis(n,m,r,c),max(dis(1,m,r,c),dis(n,1,r,c)))));
	}
	return 0;
}