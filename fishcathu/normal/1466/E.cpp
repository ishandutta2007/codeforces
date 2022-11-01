#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5E5+10;
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
ll a[N];
const int p=1E9+7,k=60;
int b[k],c[k];
void solve()
{
	int n=read(),sum=0;
	memset(c,0,sizeof c);
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		for(int j=0;j<k;++j)
		{
			if(a[i]&1ll<<j)++c[j];
		}
		sum=(sum+a[i]%p)%p;
	}
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		int f=0,g=sum;
		for(int j=0;j<k;++j)
		{
			if(a[i]&1ll<<j)
			{
				f=(f+c[j]*1ll*b[j])%p;
				g=(g+(n-c[j])*1ll*b[j])%p;
			}
		}
		ans=(ans+f*1ll*g)%p;
	}
	write(ans,'\n');
}
int main()
{
	for(int i=0;i<k;++i)
	{
		b[i]=(1ll<<i)%p;
	}
	for(int x=read();x--;)
	{
		solve();
	}
}