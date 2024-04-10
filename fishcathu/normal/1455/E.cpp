#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define fi first
#define se second
const int N=101;
int read()
{
    int a=0;char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(int x)
{
    if(x<0)putchar('-'),x=-x;
    char a[10],s=0;
    do a[s++]=x%10|48;while(x/=10);
    do putchar(a[--s]);while(s);
}
pll f(ll a,ll b,ll c,ll d)
{
	ll mx=max(a,b)-min(c,d);
	ll mn=min(a,b)-max(c,d);
	if(mx>=0&&mn<0)mx=max(mx,-mn),mn=0;
	else if(mn<0){ll t=-mx;mx=-mn,mn=t;}
	return make_pair(mx,mn);
}
int main()
{
	for(int x=read();x--;)
	{
		pll a[4];
		for(int i=0;i<4;++i)a[i].fi=read(),a[i].se=read();
		sort(a,a+4);
		ll ans=1ll<<62;
		do
		{
			ll s=abs(a[0].se-a[1].se)+abs(a[1].fi-a[2].fi)+abs(a[2].se-a[3].se)+abs(a[3].fi-a[0].fi);
			pll l=f(a[0].se,a[1].se,a[2].se,a[3].se);
			pll r=f(a[0].fi,a[3].fi,a[1].fi,a[2].fi);
			pll m=f(l.fi,l.se,r.fi,r.se);
			ans=min(ans,s+m.se*2);
		}while(next_permutation(a,a+4));
		printf("%lld\n",ans);
	}
}