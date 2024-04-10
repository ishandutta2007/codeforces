#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1E5+10;
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
int a[N],b[N];
void solve()
{
	int n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=0;i<n;++i)b[i]=read();
	for(int i=0;i<n;++i)b[i]=abs(b[i]-read());
	ll mx=0;
	for(ll i=2,now=b[1];i<=n;++i)
	{
		now+=a[i]+1;
		mx=max(mx,now);
		now=b[i]?max(now-b[i],b[i]*1ll):0;
	}
	write(mx,'\n');
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}