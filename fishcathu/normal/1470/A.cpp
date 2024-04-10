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
int a[N],b[N];
void solve()
{
	int n=read(),m=read();
	ll ans=0;
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=m;++i)b[i]=read();
	sort(a+1,a+1+n,greater<int>());
	for(int i=1,j=1;i<=n;++i)
	{
		if(a[i]>j)
		{
			ans+=b[j];
			++j;
		}
		else ans+=b[a[i]];
	}
	write(ans,'\n');
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}