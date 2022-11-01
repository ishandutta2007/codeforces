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
const int N=5E5+10;
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
int f[N<<1];
ll g[N],v[N];
int main()
{
	int n=read(),m=read();
	ll k=read(),y=n*1ll*m/__gcd(n,m);
	for(ll i=0,j=1;1;j+=m)
	{
		g[i]=j;
		i=(i+m)%n;
		if(!i)break;
	}
	memset(f+1,-1,max(n,m)<<3);
	for(int i=0;i<n;++i)f[read()]=i;
	int cnt=0;
	for(int i=0;i<m;++i)
	{
		int t=f[read()];
		if(!~t)continue;
		t=(t-i%n+n)%n;
		if(!g[t])continue;
		v[++cnt]=i+g[t];
	}
	sort(v+1,v+1+cnt);
	v[cnt+1]=y+1;
	ll z=y-cnt;
	ll ans=(k-1)/z*y;
	k-=ans/y*z;
	int i=1;
	while(v[i]-i<k)++i;
	write(ans+k+i-1,'\n');
}