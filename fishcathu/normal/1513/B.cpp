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
int a[N];
const int p=1E9+7;
void solve()
{
	int n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	sort(a+1,a+1+n);
	for(int i=2;i<=n;++i)
	{
		if((a[i]&a[1])!=a[1])
		{
			puts("0");
			return;
		}
	}
	int m=2;
	while(m<=n&&a[m]==a[1])++m;
	--m;
	int ans=m*1LL*(m-1)%p;
	for(int i=n-2;i>=1;--i)
	{
		ans=ans*1LL*i%p;
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