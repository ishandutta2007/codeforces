#include<bits/stdc++.h>
#define ll long long
using namespace std;
set<ll> s;
ll sum,rum;
int n,m,q,b[100001];
ll ask(ll x)
{
	set<ll>::iterator p=s.lower_bound(-x);
	ll r=1ll<<60;
	if(p!=s.end())r=min(r,*p+x);
	if(p!=s.begin())r=min(r,-(*--p+x));
	return r;
}
main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1,x;i<=n;++i)
	{
		scanf("%d",&x);
		sum+=i&1?x:-x;
	}
	for(int i=1;i<=m;++i)scanf("%d",&b[i]);
	for(int i=1;i<n;++i)rum+=i&1?-b[i]:b[i];
	for(int i=n;i<=m;++i)
	{
		rum+=n&1?-b[i]:b[i];
		s.insert(rum);
		rum=-b[i-n+1]-rum;
	}
	printf("%I64d\n",ask(sum));
	for(int a,b,c;q--;)
	{
		scanf("%d%d%d",&a,&b,&c);
		printf("%I64d\n",ask(sum+=(b-a)&1?0:(a&1?c:-c)));
	}
}