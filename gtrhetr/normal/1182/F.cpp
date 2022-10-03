#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll t,a,b,p,q;

inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void print(ll x)
{
	static char s[233];
	if (!x) { putchar('0');putchar('\n');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar('\n');
}

inline ll gcd(ll x,ll y) { return (!y)?x:gcd(y,x%y); }

inline void ex_gcd(ll a,ll b,ll &x,ll &y)
{
	if (!b) { x=1;y=0;return; }
	ex_gcd(b,a%b,x,y);
	ll hh=x;x=y;y=hh-y*(a/b);
}

inline ll anal_gcd(ll n,ll a,ll b,ll c)
{
	if (n<0) return 0;
	if (!a) return (b/c)*(n+1);
	if (a>=c||b>=c) return (a/c)*n*(n+1)/2+(b/c)*(n+1)+anal_gcd(n,a%c,b%c,c);
	ll hh=(a*n+b)/c;
	return hh*n-anal_gcd(hh-1,c,c-b-1,a);
}

inline ll getinv(ll a,ll b)
{
	ll x,y;
	ex_gcd(a,b,x,y);
	x=(x%b+b)%b;
	return x;
}

inline bool check(ll a,ll b,ll l,ll r)
{
	ll h1=anal_gcd(b,p,q-l,q)-anal_gcd(b,p,q-r-1,q);
	ll h2=anal_gcd(a-1,p,q-l,q)-anal_gcd(a-1,p,q-r-1,q);
	return h1-h2>0;
}

inline bool in(ll x,ll l,ll r) { return (x>=l&&x<=r); }

inline ll calc(ll hh,ll p,ll q)
{
	ll inv=getinv(p,q);
	ll res=hh*inv%q;
	res+=(a-res)/q*q;
	while (res<a) res+=q;
	while (res-q>=a) res-=q;
	return res;
}

inline void gao()
{
	a=rd();b=rd();p=rd();q=rd();p%=q;
	ll hhh=gcd(p,q);
	p/=hhh;q/=hhh;
	if (b>=a+q) b=a+q-1;
	p*=2;q*=2;
	ll l=0,r=q/2;
	while (l<r)
	{
		ll mid=(l+r)>>1;
		if (check(a,b,q/2-mid,q/2+mid)) r=mid;
		else l=mid+1;
	}
	ll h1=q/2-l,h2=q/2+l;
	p/=2;q/=2;h1/=2;h2/=2;
	ll res1=calc(h1%q,p,q),res2=calc(h2%q,p,q);
	if (!in(res1,a,b)) print(res2);
	else if (!in(res2,a,b)) print(res1);
	else print(min(res1,res2));
}

int main()
{
	t=rd();
	while (t--) gao();
	return 0;
}