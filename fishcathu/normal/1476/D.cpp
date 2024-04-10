#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3E5+10;
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
int l[N],r[N];
void solve()
{
	int n=read();
	scanf("%s",a+1);
	a[n+1]=r[n+1]=0;
	for(int i=1;i<=n;++i)
	{
		l[i]=(a[i]==a[i-1]?0:l[i-1])+1;
	}
	for(int i=n;i>=1;--i)
	{
		r[i]=(a[i]==a[i+1]?0:r[i+1])+1;
	}
	for(int i=0;i<=n;++i)
	{
		int ans=0;
		if(a[i]=='L')ans+=l[i];
		if(a[i+1]=='R')ans+=r[i+1];
		write(ans+1,' ');
	}
	putchar('\n');
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}