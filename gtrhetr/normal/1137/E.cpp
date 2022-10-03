#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb long double

struct node
{
	ll x,y;
	node(ll xx=0,ll yy=0):x(xx),y(yy) {}
}st[300010];

ll sum[300010],n,m,top;

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
	if (!x) { putchar('0');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
}

inline ll calc(node x,ll s,ll b) { return x.x*s+x.y+b; }

inline node operator -(node x,node y) { return node(x.x-y.x,x.y-y.y); }

inline ldb cross(node x,node y) { return (ldb)x.x*y.y-(ldb)x.y*y.x; }

inline void gao(ll s,ll b)
{
	ll l=1,r=top;
	while (r-l>=5)
	{
		ll h1=(l+l+r)/3,h2=(l+r+r)/3;
		if (calc(st[h1],s,b)<=calc(st[h2],s,b)) r=h2;
		else l=h1;
	}
	ll ans=l;
	for (ll i=l;i<=r;i++) if (calc(st[i],s,b)<calc(st[ans],s,b)) ans=i;
	while (ans>1&&calc(st[ans-1],s,b)==calc(st[ans],s,b)) ans--;
	print(sum[ans-1]+1);
	putchar(' ');
	print(calc(st[ans],s,b));
	putchar('\n');
}

int main()
{
	n=rd();m=rd();
	st[top=1]=node(0,0);sum[1]=n;
	ll snow=0,bnow=0,s=n;
	while (m--)
	{
		int p=rd();
		if (p==1)
		{
			ll x=rd();
			st[top=1]=node(0,0);sum[1]=s+x;
			s+=x;snow=bnow=0;
			gao(snow,bnow);
		}
		else if (p==2)
		{
			ll x=rd();
			ll hh=snow*s+bnow,hhh=s;
			node now(hhh,-hh);
			while (top>1&&cross(now-st[top-1],st[top]-st[top-1])>=0) sum[top-1]=sum[top],top--;
			st[++top]=node(hhh,-hh);
			sum[top]=s+x;s+=x;
			gao(snow,bnow);
		}
		else
		{
			ll b=rd(),s=rd();
			snow+=s;bnow+=b;
			gao(snow,bnow);
		}
	}
	return 0;
}