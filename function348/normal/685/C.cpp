#include<cstdio>
#include<iostream>
using namespace std;
typedef long long LL;
const LL inf=4e+18;
const int N=100010;
struct rec {LL a,b,c;};
int cas,n;
LL x[N],y[N],z[N];
rec get(LL la,LL ra,LL lb,LL rb,LL lc,LL rc,LL labc,LL rabc,int k)
{
	la-=k,ra-=k,lb-=k,rb-=k,lc-=k,rc-=k;
	labc-=3*k,rabc-=3*k;
	if (la%2!=0) la++;if (ra%2!=0) ra--;
	if (lb%2!=0) lb++;if (rb%2!=0) rb--;
	if (lc%2!=0) lc++;if (rc%2!=0) rc--;
	if (labc%2!=0) labc++;if (rabc%2!=0) rabc--;
	if (la>ra||lb>rb||lc>rc||labc>rabc) return (rec){inf,inf,inf};
//	printf("%lld %lld %lld %lld %lld %lld\n",la,ra,lb,rb,lc,rc);

	if (rabc<la+lb+lc) return (rec){inf,inf,inf};
	if (labc>ra+rb+rc) return (rec){inf,inf,inf};
	if (labc<=la+lb+lc&&la+lb+lc<=rabc) return (rec){la+k,lb+k,lc+k};
	if (labc<=ra+rb+rc&&ra+rb+rc<=rabc) return (rec){ra+k,rb+k,rc+k};
	if (labc<=la+lb+rc) return (rec){la+k,lb+k,labc-la-lb+k};
	if (labc<=la+rb+rc) return (rec){la+k,labc-la-rc+k,rc+k};
	return (rec){labc-rb-rc+k,rb+k,rc+k};
}
rec check(LL mid)
{
	LL la,lb,lc,labc,ra,rb,rc,rabc;
	la=lb=lc=labc=-inf;
	ra=rb=rc=rabc=inf;
	for (int i=1;i<=n;i++)
	{
		la=max(la,-x[i]+y[i]+z[i]-mid);
		ra=min(ra,-x[i]+y[i]+z[i]+mid);
		lb=max(lb, x[i]-y[i]+z[i]-mid);
		rb=min(rb, x[i]-y[i]+z[i]+mid);
		lc=max(lc, x[i]+y[i]-z[i]-mid);
		rc=min(rc, x[i]+y[i]-z[i]+mid);
		labc=max(labc,x[i]+y[i]+z[i]-mid);
		rabc=min(rabc,x[i]+y[i]+z[i]+mid);
	}
	if (la>ra||lb>rb||lc>rc||labc>rabc) return (rec){inf,inf,inf};
	rec tmp=get(la,ra,lb,rb,lc,rc,labc,rabc,0);
	if (tmp.a!=inf) return tmp;
	tmp=get(la,ra,lb,rb,lc,rc,labc,rabc,1);
	if (tmp.a!=inf) return tmp;
	return (rec){inf,inf,inf};
}
int main()
{
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
		LL l=0,r=inf;
		while (l<r)
		{
			LL mid=(l+r)>>1;
			if (check(mid).a!=inf) r=mid;else l=mid+1;
		}
		rec ans=check(l);
		printf("%lld %lld %lld\n",(ans.b+ans.c)/2,(ans.a+ans.c)/2,(ans.a+ans.b)/2);
	}
	return 0;
}