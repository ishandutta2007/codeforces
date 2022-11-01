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
void solve()
{
	int n=read();
	ll ans=0;
	for(int i=2;i<=n;++i)
	{
		int t=max(i-1,n-i);
		ans+=t*1ll*t;
	}
	write(ans,'\n');
	int m=n+1>>1;
	write(m+1,' ');
	for(int i=3;i<=m;++i)write(i,' ');
	printf("1 ");
	for(int i=m+2;i<=n;++i)write(i,' ');
	if(n!=2)printf("2 ");
	putchar('\n');
	write(n-1,'\n');
	for(int i=2;i<=n;++i)
	{
		int t=i-1>n-i?1:n;
		write(i,' ');
		write(t,'\n');
	}
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}