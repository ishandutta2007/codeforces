#include<bits/stdc++.h>
#define l first
#define r second
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
pair<int,int>c[N];
int a[N],b[N];
void solve()
{
	read();
	read();
	int n=read();
	for(int i=1;i<=n;++i)
	{
		c[i].l=read();
		++a[c[i].l];
	}
	for(int i=1;i<=n;++i)
	{
		c[i].r=read();
		++b[c[i].r];
	}
	sort(c+1,c+1+n);
	ll ans=0;
	for(int i=1,t=n;i<=n;++i)
	{
		if(c[i].l!=c[i-1].l)
		{
			t-=a[c[i].l];
			a[c[i].l]=0;
		}
		--b[c[i].r];
		ans+=t-b[c[i].r];
	}
	write(ans,'\n');
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}