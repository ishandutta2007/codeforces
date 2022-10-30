#include<cstdio>
#include<cstring>
#include<algorithm>
template<typename _Tp>inline _Tp max(const _Tp &a,const _Tp &b){return a>b?a:b;}
template<typename _Tp>void read(_Tp &x)
{
	register char ch(getchar());
	bool f(false);
	while(ch<48||ch>57) f|=ch=='-',ch=getchar();
	x=ch&15,ch=getchar();
	while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	if(f) x=-x;
}
typedef long long ll;
const int inf=0x3f3f3f3f;
const ll INF=1000000000000000000ll;
const int N=1000005;
bool vis[N];
ll mod;
int _(ll x,ll tar,ll x1,ll y1)
{
	memset(vis,0,sizeof(vis));
	int cnt=0;
	while(true)
	{
		++cnt;
		x=(x*x1+y1)%mod;
		if(vis[x]) return inf;
		vis[x]=true;
		if(x==tar) return cnt;
	}
}
ll __(ll x,ll x1,ll y1,int t)
{
	while(t--) x=(x*x1+y1)%mod;
	return x;
}
void exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b)
	{
		x=1,y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=(a/b)*x;
}
template<typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return !b?a:gcd(b,a%b);}
int main()
{
//	freopen("water.in","r",stdin);
//	freopen("water.out","w",stdout);
	ll h1,a1,x1,y1;
	ll h2,a2,x2,y2;
	read(mod);
	read(h1),read(a1),read(x1),read(y1);
	read(h2),read(a2),read(x2),read(y2);
	ll k1=_(a1,a1,x1,y1);
	ll b1=_(h1,a1,x1,y1);
	ll k2=_(a2,a2,x2,y2);
	ll b2=_(h2,a2,x2,y2);
	if(b1>=inf||b2>=inf)
	{
		printf("-1\n");
		return 0;
	}
	if(b1==b2)
	{
		printf("%lld\n",b1);
		return 0;
	}
	if(k1>=inf&&k2>=inf)
	{
		printf("-1\n");
		return 0;
	}
	if(k1>=inf||k2>=inf)
	{
		if(k1>=inf)
		{
			if(__(h2,x2,y2,b1)==a2)
			{
				printf("%lld\n",b1);
				return 0;
			}
		}
		else
		{
			if(__(h1,x1,y1,b2)==a1)
			{
				printf("%lld\n",b2);
				return 0;
			}
		}
		printf("-1\n");
		return 0;
	}
	ll g=gcd(k1,k2);
	ll k=b2-b1;
	if(k%g)
	{
		printf("-1\n");
		return 0;
	}
	ll t1=0,t2=0;
	exgcd(k1,k2,t1,t2);
	ll tmp=k2/gcd(k1,k2);
	t1*=k/g;
	t1=((t1%tmp)+tmp)%tmp;
	tmp=k1/gcd(k1,k2);
	t2*=k/g;
	t2=(t2%tmp-tmp)%tmp;
	printf("%lld\n",max(t1*k1+b1,-t2*k2+b2));
	return 0;
}