#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
const int N=2E5+10;
ll read()
{
	ll a=0;
	char b=1,c;
	do if((c=getchar())==45)b=-1;while(c<48||c>57);
	do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
	return a*b;
}
void write(ll x,char c)
{
    if(x<0)putchar('-'),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
int a[N];
ll l[N];
pli b[N];
void solve()
{
	int n=read(),m=read(),s=0;
	ll mx=0;
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		l[i]=l[i-1]+a[i];
		mx=max(mx,l[i]);
		if(l[i]>b[s].fi)b[++s]=mp(l[i],i);
	}
	while(m--)
	{
		int x=read();
		if(x>mx&&l[n]<=0)
		{
			printf("-1 ");
			continue;
		}
		ll y=x-mx,t;
		if(y<=0||l[n]<=0)t=0;
		else 
		{
			t=y/l[n];
			if(y%l[n])++t;
		}
		write(t*n+lower_bound(b+1,b+1+s,mp(x-t*l[n],0))->se-1,' ');
	}
	putchar('\n');
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}