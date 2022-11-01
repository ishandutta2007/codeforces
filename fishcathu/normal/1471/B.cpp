#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1E5+10;
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
void solve()
{
	int n=read(),k=read();
	int mn=1<<30,w;
	for(int i=1;i<=n;++i)
	{
		int t=read(),x=0;
		a[i]=a[i-1]+t;
		while(!(t%k))
		{
			t/=k;
			++x;
		}
		if(x<mn)mn=x,w=i;
	}
	write(a[n]*(mn+1)+a[w-1],'\n');
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}