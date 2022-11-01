#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5010;
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
int a[N][N],b[N],c[N];
int main()
{
	int n=read(),m=read(),x=read();
	for(int i=1;i<=n;++i)a[i][0]=1;
	const int p=1E9+7;
	for(int j=1;j<=m;++j)for(int i=1;i<=n;++i)
	{
		a[i][j]=(a[i-1][j-1]+a[i+1][j-1])%p;
	}
	for(int i=1;i<=n;++i)for(int j=m>>1;j>=0;--j)
	{
		b[i]=(b[i]+a[i][j]*(1ll+(j<<1!=m))*a[i][m-j])%p;
	}
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		c[i]=read();
		ans=(ans+c[i]*1ll*b[i])%p;
	}
	while(x--)
	{
		int w=read(),val=read();
		ans=(ans+(val-c[w])*1ll*b[w])%p;
		c[w]=val;
		write((ans+p)%p,'\n');
	}
}