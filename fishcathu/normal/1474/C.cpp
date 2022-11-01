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
int a[2010],c[2010],n;
bitset<2010>b;
bool check(int x)
{
	memcpy(a,c,sizeof a);
	b=0;
	for(int m=n>>1,r=n;m--;)
	{
		while(b[r])--r;
		b[r]=1;
		int l=lower_bound(a+1,a+1+n,x-a[r])-a;
		if(a[l]+a[r]!=x||b[l])return 0;
		b[l]=1;
		--a[l];
		x=a[r];
	}
	return 1;
}
void print(int x)
{
	memcpy(a,c,sizeof a);
	write(x,'\n');
	b=0;
	for(int m=n>>1,r=n;m--;)
	{
		while(b[r])--r;
		b[r]=1;
		int l=lower_bound(a+1,a+1+n,x-a[r])-a;
		write(a[l],' ');
		write(a[r],'\n');
		b[l]=1;
		--a[l];
		x=a[r];
	}
}
void solve()
{
	n=read()<<1;
	for(int i=1;i<=n;++i)c[i]=read();
	c[n+1]=0;
	sort(c+1,c+1+n);
	int i=1;
	while(i<n&&!check(c[n]+c[i]))++i;
	if(i==n)puts("NO");
	else
	{
		puts("YES");
		print(c[n]+c[i]);
	}
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}