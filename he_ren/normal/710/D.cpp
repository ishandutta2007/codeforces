#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
typedef long double ldb;
using namespace std;
typedef long long ll;

inline ll min(ll a,ll b){ return a<b? a: b;}
inline ll max(ll a,ll b){ return a>b? a: b;}
inline void chk_max(ll &a,ll b){ if(a<b) a=b;}
inline void error(void){ printf("0"); exit(0);}

inline ll Abs(ll x){ return x<0? -x: x;}
inline ll flr(ll a,ll b){ return floor((ldb)a/b);}
inline ll cl(ll a,ll b){ return ceil((ldb)a/b);}

ll exgcd(ll a,ll b,ll c,ll &x,ll &y)
{
	if(!b)
	{
		if(c%a) error();
		x=c/a; y=0;
		return a;
	}
	ll t = exgcd(b,a%b,c,y,x);
	y -= a/b*x;
	return t;
}

int main(void)
{
	ll a1,b1,a2,b2,l,r;
	cin>>a1>>b1>>a2>>b2>>l>>r;
	
	ll x,y;
	ll tmp = exgcd(a1,-a2,b2-b1,x,y);
	ll s=-a2/tmp, t=-a1/tmp;
	
	ll xl = cl(l-b1,a1), xr = flr(r-b1,a1);
	if(xr>=0) chk_max(xl,0);
	else error();
	if(s<0) swap(xl,xr);
	ll kl1 = cl(xl-x,s), kr1 = flr(xr-x,s);
	
	ll yl = cl(l-b2,a2), yr = flr(r-b2,a2);
	if(yr>=0) chk_max(yl,0);
	else error();
	if(t<0) swap(yl,yr);
	ll kl2 = cl(yl-y,t), kr2 = flr(yr-y,t);
	
	ll kl=max(kl1,kl2), kr=min(kr1,kr2);
	if(kl>kr) error();
	cout<<kr-kl+1;
	return 0;
}