// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-10;

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp &x)
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

const int N=1000005;
const int mod=1000000007;
struct vec{
	ll x,y;
	Finline vec operator + (const vec &o)const
	{
		return (vec){x+o.x,y+o.y};
	}
	Finline vec operator - (const vec &o)const
	{
		return (vec){x-o.x,y-o.y};
	}
	Finline ll operator * (const vec &o)const
	{
		return x*o.y-y*o.x;
	}
}a[N];
ll getS(vec *a,int n)
{
	ll ans=0;
	for(int i=2;i<n;++i)
	{
		ans+=a[i]*a[i+1];
	}
	return ans;
}
ll sumx[N],sumy[N];
ll tot[N],sum[N];
template<typename _Tp1,typename _Tp2>Finline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>Finline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(a[i].x,a[i].y);
	}
	std::reverse(a+1,a+n+1);
	for(int i=n;i>=1;--i)
	{
		a[i]=a[i]-a[1];
		a[i+n]=a[i];
	}
	for(int i=1;i<=n<<1;++i)
	{
		sumx[i]=(sumx[i-1]+a[i].x)%mod;
		sumy[i]=(sumy[i-1]+a[i].y)%mod;
		add(sumx[i],mod);
		add(sumy[i],mod);
	}
	for(int i=1;i<n<<1;++i)
	{
		sum[i]=(sum[i-1]+(a[i]*a[i+1])%mod+mod)%mod;
		tot[i]=(tot[i-1]+(a[i]*a[i+1])%mod*((n<<1)-i))%mod;
		add(tot[i],mod);
	}
	ll S=getS(a,n);
	int pos=1;
	ll tmp=0;
	ll ans=0,qwq;
	int cnt=0;
	ll lim=S>>1;
	for(int i=1;i<=n;++i)
	{
		while(pos+1<i+n&&(tmp+(qwq=((a[pos]-a[i])*(a[pos+1]-a[pos]))))<=lim)
		{
			tmp+=qwq;
			++pos;
		}
		if((tmp<<1)==S) ++cnt;
		(ans+=((tot[pos-1]-tot[i-1]+mod)-(sum[pos-1]-sum[i-1]+mod)*((n<<1)-pos)%mod+mod))%=mod;
		add(ans,(a[i].y*(sumx[pos]-sumx[i]+mod)%mod+mod)%mod);
		sub(ans,(a[i].x*(sumy[pos]-sumy[i]+mod)%mod+mod)%mod);
		tmp-=(a[i+1]-a[i])*(a[pos]-a[i]);
	}
	assert(!(cnt&1));
	sub(ans,1ll*(cnt>>1)*(lim%mod)%mod);
	ans=((1ll*n*(n-3)>>1)%mod*(S%mod)%mod-ans*2+mod*2)%mod;
	printf("%lld\n",ans);
	return 0;
}
//