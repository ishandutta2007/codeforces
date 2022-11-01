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
char a[N];
int l[N],r[N],now[N];
int d[N],u[N];
void solve()
{
	int n=read(),m=read();
	scanf("%s",a+1);
	l[n+1]=r[n+1]=d[n+1]=u[n+1]=0;
	for(int i=1;i<=n;++i)
	{
		now[i]=now[i-1]+(a[i]=='+'?1:-1);
		l[i]=min(l[i-1],now[i]);
		r[i]=max(r[i-1],now[i]);
	}
	for(int i=n;i>=1;--i)
	{
		d[i]=u[i]=a[i]=='+'?1:-1;
		d[i]=min(min(d[i],d[i]+d[i+1]),0);
		u[i]=max(max(u[i],u[i]+u[i+1]),0);
	}
	while(m--)
	{
		int b=read()-1,c=read()+1;
		int mn=l[b],mx=r[b];
		mn=min(mn,now[b]+d[c]);
		mx=max(mx,now[b]+u[c]);
		write(mx-mn+1,'\n');
	}
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}