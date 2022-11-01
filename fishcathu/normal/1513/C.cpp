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
    if(x<0)putchar(45),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
int f[N][10],sum[N];
const int p=1E9+7;
void init()
{
	f[0][0]=1;
	for(int i=1;i<N;++i)
	{
		for(int j=0;j<=9;++j)
		{
			f[i][(j+1)%10]=f[i-1][j];
		}
		f[i][1]=(f[i][1]+f[i][0])%p;
		for(int j=0;j<=9;++j)
		{
			sum[i]=(sum[i]+f[i][j])%p;
		}
	}
}
void solve()
{
	int n=read(),m=read();
	int ans=0;
	while(n)
	{
		ans=(ans+sum[n%10+m])%p;
		n/=10;
	}
	write(ans,'\n');
}
int main()
{
	init();
	for(int x=read();x--;)
	{
		solve();
	}
}