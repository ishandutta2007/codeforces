#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN];
ll solve(ll f,ll t0,ll T,ll a1,ll t1,ll p1)
{
	//printf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d\n",f,t0,T,a1,t1,p1);
	if(f*t0<=T) return 0;
	if(t1>t0) return -1;
	if(f*t1>T) return -1;
	ll k=(f-1)/a1;
	if(k*t1+(f-k*a1)*t0>T) return (k+1)*p1;
	k=(f*t0-T-1)/(a1*t0-a1*t1)+1;
	return k*p1;
}
int main()
{
	ll f,T,t0,a1,t1,p1,a2,t2,p2;
	scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&f,&T,&t0,&a1,&t1,&p1,&a2,&t2,&p2);
	ll ans=INF;
	for(ll i=0;;i++)
	{
		if(i*t2>T||i*a2>f) break;
		ll x=solve(f-i*a2,t0,T-i*a2*t2,a1,t1,p1);
		if(x!=-1) ans=min(ans,x+i*p2);
		//printf("%I64d\n",ans);
	}
	for(ll i=0;;i++)
	{
		if(i*t1>T||i*a1>f) break;
		ll x=solve(f-i*a1,t0,T-i*a1*t1,a2,t2,p2);
		if(x!=-1) ans=min(ans,x+i*p1);
		//printf("%I64d\n",ans);
	}
	if(ans==INF) puts("-1"); else printf("%I64d\n",ans);
	return 0;
}