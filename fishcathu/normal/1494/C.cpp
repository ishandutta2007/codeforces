#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
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
int a[N],b[N],c[N],m;
int f(int l,int r)
{
	return upper_bound(b+1,b+1+m,r)-lower_bound(b+1,b+1+m,l);
}
void solve()
{
	int n=read();
	m=read();
	a[0]=-1<<30;
	a[n+1]=1<<30;
	c[m+1]=0;
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=m;++i)b[i]=read();
	int g=lower_bound(a+1,a+1+n,0)-a;
	int k=lower_bound(b+1,b+1+m,0)-b;
	for(int i=1;i<k;++i)
	{
		c[i]=c[i-1];
		if(*lower_bound(a+1,a+g,b[i])==b[i])++c[i];
	}
	for(int i=m;i>=k;--i)
	{
		c[i]=c[i+1];
		if(*lower_bound(a+g,a+1+n,b[i])==b[i])++c[i];
	}
	int mx1=0,mx2=0;
	for(int i=k,j=g-1;--i;)
	{
		while(a[j]>=b[i])--j;
		mx1=max(mx1,c[i-1]+f(b[i],b[i]+g-j-2));
	}
	for(int i=k,j=g;i<=m;++i)
	{
		while(a[j]<=b[i])++j;
		mx2=max(mx2,c[i+1]+f(b[i]+g-j+1,b[i]));
	}
	write(mx1+mx2,'\n');
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}