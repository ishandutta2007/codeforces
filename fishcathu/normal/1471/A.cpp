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
ll f(ll a,ll b)
{
	return a/b+(a%b!=0);
}
void solve()
{
	int n=read(),k=read();
	ll a1=0,a2=0;
	for(int i=1;i<=n;++i)
	{
		int t=read();
		a1+=t;
		a2+=f(t,k);
	}
	write(f(a1,k),' ');
	write(a2,'\n');
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}