#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2E5+1;
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
int l[N],r[N],a[2472114];
int b[N],sum[N];
void begin()
{
	for(int i=1,s=0;i<N;++i)
	{
		l[i]=s+1;
		for(int j=1;j*j<=i;++j)if(!(i%j))
		{
			a[++s]=j;
			if(j*j!=i)a[++s]=i/j;
		}
		r[i]=s;
	}
}
void solve()
{
	int n=read();
	for(int i=1;i<=n;++i)b[i]=read();
	sort(b+1,b+1+n);
	int mx=0;
	for(int i=1;i<=n;++i)
	{
		if(b[i]!=b[i-1])
		{
			for(int j=l[b[i]];j<=r[b[i]];++j)
			{
				sum[b[i]]=max(sum[b[i]],sum[a[j]]);
			}
		}
		++sum[b[i]];
		mx=max(mx,sum[b[i]]);
	}
	for(int i=1;i<=n;++i)sum[b[i]]=0;
	write(n-mx,'\n');
}
int main()
{
	begin();
	for(int x=read();x--;)
	{
		solve();
	}
}