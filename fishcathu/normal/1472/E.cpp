#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
struct st
{
	int l,r,w;
	bool operator<(const st m)const
	{
		return l<m.l;
	}
}a[N];
int ans[N];
void solve()
{
	int n=read();
	for(int i=1;i<=n;++i)
	{
		a[i].l=read();
		a[i].r=read();
		if(a[i].l>a[i].r)
		{
			swap(a[i].l,a[i].r);
		}
		a[i].w=i;
	}
	sort(a+1,a+1+n);
	int m1=0,m2=0;
	a[0].r=1<<30;
	for(int i=1;i<=n;++i)
	{
		if(a[i].l!=a[i-1].l)
		{
			if(a[m2].r<a[m1].r)m1=m2;
			m2=i;
		}
		else if(a[i].r<a[m2].r)m2=i;
		ans[a[i].w]=a[i].r>a[m1].r?a[m1].w:-1;
	}
	for(int i=1;i<=n;++i)write(ans[i],' ');
	putchar('\n');
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}