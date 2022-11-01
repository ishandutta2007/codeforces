#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1E6+10;
ll read()
{
    ll a=0;char b=1,c;
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
int p[78500];
int a[N],b[300010],c[N];
void begin()
{
	a[1]=1;
	for(int i=2,s=0;i<N;++i)
	{
		if(!a[i])p[++s]=i,a[i]=i;
		for(int j=1;j<=s&&i*p[j]<N;++j)
		{
			int t=__gcd(a[i],p[j]);
			a[i*p[j]]=a[i]*p[j]/t/t;
			if(!(i%p[j]))break;
		}
	}
}
void solve()
{
	int n=read(),mx=0;
	for(int i=1;i<=n;++i)
	{
		b[i]=a[read()];
		++c[b[i]];
		mx=max(mx,c[b[i]]);
	}
	for(int i=1;i<=n;++i)
	{
		if(b[i]!=1&&!(c[b[i]]&1))
		{
			c[1]+=c[b[i]];
			c[b[i]]=0;
		}
	}
	c[1]=max(c[1],mx);
	for(int x=read();x--;)
	{
		write(read()?c[1]:mx,'\n');
	}
	c[1]=0;
	for(int i=1;i<=n;++i)c[b[i]]=0;
}
int main()
{
	begin();
	for(int x=read();x--;)
	{
		solve();
	}
}