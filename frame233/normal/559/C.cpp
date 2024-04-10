// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-10;

uint seed=19260817;
const uint _RAND_MAX_=4294967295u;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp& x)
{
    register char ch(getchar());
    bool f(false);
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
    x=ch&15,ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
    read(t);read(args...);
}
Finline int read_str(char *s)
{
    register char ch(getchar());
    while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
    register char *tar=s;
    *tar=ch,ch=getchar();
    while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
    return tar-s+1;
}

const int N=100005;
const int mod=1000000007;
struct node{
	int x,y;
	Finline bool operator < (const node &o)const
	{
		return x==o.x?y<o.y:x<o.x;
	}
}a[N];
ll fac[N<<1],inv[N<<1];
Finline void add(ll &a,const ll &b){(a+=b)>=mod&&(a-=mod);}
Finline void sub(ll &a,const ll &b){(a-=b)<0&&(a+=mod);}
Finline ll C(const int &n,const int &m)
{
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
ll res[N];
int main()
{
	int n,m,k;
	read(n,m,k);
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for(int i=2;i<=n+m;++i)
	{
		fac[i]=fac[i-1]*i%mod;
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	}
	for(int i=2;i<=n+m;++i)
	{
		inv[i]=inv[i-1]*inv[i]%mod;
	}
	for(int i=1;i<=k;++i)
	{
		read(a[i].x,a[i].y);
	}
	std::sort(a+1,a+k+1);
	ll ans=C(n+m-2,n-1);
	for(int i=1;i<=k;++i)
	{
		ll tmp=C(a[i].x+a[i].y-2,a[i].x-1);
		for(int j=1;j<i;++j)
		{
			if(a[j].x<=a[i].x&&a[j].y<=a[i].y)
			{
				sub(tmp,res[j]*C(a[i].x-a[j].x+a[i].y-a[j].y,a[i].x-a[j].x)%mod);
			}
		}
		res[i]=tmp;
		sub(ans,tmp*C(n-a[i].x+m-a[i].y,n-a[i].x)%mod);
	}
	printf("%lld\n",ans);
    return 0;
}