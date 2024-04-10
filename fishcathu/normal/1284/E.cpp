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
const int N=2510;
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
struct st
{
	int l,r;
	bool operator<(const st m)const
	{
		if(!l&&r<0)return 1;
		if(!m.l&&m.r<0)return 0;
		if(l*1ll*m.l>=0)return l*1ll*m.r>r*1ll*m.l;
		return l>0;
	}
}a[N];
int u[N],v[N],n;
bool f(int j,int k)
{
	if(k==j+n-2)return 0;
	k=k%(n-1)+1;
	return a[j].l*1ll*a[k].r>=a[j].r*1ll*a[k].l;
}
ll c(int x,int k)
{
	ll res=1;
	for(int i=0;i<k;)
	{
		res*=x-i;
		res/=++i;
	}
	return res;
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		u[i]=read();
		v[i]=read();
	}
	ll ans=c(n,5)*5;
	for(int i=1;i<=n;++i)
	{
		for(int j=1,k=0;j<=n;++j)if(j!=i)
		{
			a[++k].l=u[j]-u[i];
			a[k].r=v[j]-v[i];
		}
		sort(a+1,a+n);
		for(int j=1,k=0;j<n;++j)
		{
			while(f(j,k))++k;
			ans-=c(k-j,3);
		}
	}
	write(ans,'\n');
}