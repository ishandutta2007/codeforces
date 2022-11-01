#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2E5+10;
const int inf=1<<30;
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
int a[N],n;
ll sum;
bool check1()
{
	if(sum-a[n]==a[n-1]<<1)
	{
		for(int i=1;i<n-1;++i)
		{
			write(a[i],' ');
		}
		putchar('\n');
		return 1;
	}
	return 0;
}
bool check2()
{
	int i=1;
	sum-=a[n];
	while(i<n)
	{
		if(sum-a[i]==a[n])break;
		++i;
	}
	if(i==n)return 0;
	for(int j=1;j<n;++j)
	{
		if(j==i)continue;
		write(a[j],' ');
	}
	putchar('\n');
	return 1;
}
void solve()
{
	n=read()+2;
	sum=0;
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		sum+=a[i];
	}
	sort(a+1,a+1+n);
	if(!check1()&&!check2())
	{
		puts("-1");
	}
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}