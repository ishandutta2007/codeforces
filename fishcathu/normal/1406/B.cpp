#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
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
int a[N];
void solve()
{
	int n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	sort(a+1,a+1+n);
	int k=lower_bound(a+1,a+1+n,0)-a-1;
	ll ans=-1ll<<62;
	for(int i=1;i<=5;i+=2)
	{
		ll t=1;
		for(int j=5-i;j>=1;--j)t*=a[j];
		for(int j=n-i;++j<=n;)t*=a[j];
		ans=max(ans,t);
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