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
int a[N],c[N];
bitset<N>b;
bool cmp(int l,int r)
{
	return a[l]<a[r];
}
void solve()
{
	int n=read(),m=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		b[i]=0;
		c[i]=i;
	}
	sort(c+1,c+1+n,cmp);
	ll ans=(n-1)*1LL*m;
	for(int i=1;i<=n;++i)
	{
		int w=c[i];
		if(a[w]>=m)break;
		if(b[w])continue;
		b[w]=1;
		for(int j=w;--j>=1;)
		{
			if(a[j]%a[w])break;
			ans-=m-a[w];
			if(b[j])break;
			b[j]=1;
		}
		for(int j=w;++j<=n;)
		{
			if(a[j]%a[w])break;
			ans-=m-a[w];
			if(b[j])break;
			b[j]=1;
		}
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