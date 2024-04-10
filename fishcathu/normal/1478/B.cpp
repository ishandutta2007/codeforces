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
int m;
bool check(int x)
{
	if(x/m>=10)return 1;
	for(int i=1,j=x%10;i<=9;++i)
	{
		int t=m*i;
		if(t>x)break;
		if(t%10==j)return 1;
	}
	return 0;
}
void solve()
{
	int n=read();
	m=read();
	while(n--)
	{
		puts(check(read())?"YES":"NO");
	}
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}