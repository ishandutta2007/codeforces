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
	int n=read(),ans=0;
	for(int i=1,j=0,k;i<=n;++i)
	{
		int t=read();
		if(t!=j)k=0;
		++k;
		ans=max(ans,k);
		j=t;
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