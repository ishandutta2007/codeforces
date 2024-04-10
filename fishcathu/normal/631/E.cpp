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
int a[N],b[N],q[N],n;
ll l[N],mx;
double f(int u,int v)
{
	return (l[v]-l[u])*1.0/(v-u);
}
void solve()
{
	for(int i=1;i<=n;++i)l[i]=l[i-1]+a[i-1];
	for(int i=2,s=0;i<=n;++i)
	{
		while(s&&a[i]<a[b[s]])--s;
		b[++s]=i;
	}
	q[1]=1;
	for(int i=2,j=1,u=1,v=1;i<=n;++i)
	{
		if(i==b[j])
		{
			while(u!=v&&f(q[u],q[u+1])<a[i])++u;
			mx=max(mx,l[i]-l[q[u]]-a[i]*1ll*(i-q[u]));
			++j;
		}
		while(u!=v&&f(q[v],i)<f(q[v-1],q[v]))--v;
		q[++v]=i;
	}
}
int main()
{
	n=read();
	ll ans=0;
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		ans+=a[i]*1ll*i;
	}
	solve();
	for(int i=1;i<=n+1>>1;++i)
	{
		int t=-a[i];
		a[i]=-a[n+1-i];
		a[n+1-i]=t;
	}
	solve();
	write(ans+mx,'\n');
}