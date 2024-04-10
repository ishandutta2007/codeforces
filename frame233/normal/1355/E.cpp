// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;

Finline uint rnd()
{
	static uint seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());
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
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=100005;
int h[N];
int n,A,R,M;
Finline ll calc(ll a,ll b)
{
	return min(a*A+b*R,min(a,b)*M+(a>b?(a-b)*A:(b-a)*R));
}
ll f(int i)
{
	ll a=0,b=0;
	for(int j=1;j<=n;++j)
	{
		if(h[j]<i)
		{
			a+=i-h[j];
		}
		else
		{
			b+=h[j]-i;
		}
	}
	return calc(a,b);
}
int main()
{
	read(n,A,R,M);
	for(int i=1;i<=n;++i) read(h[i]);
	int l=0,r=1e9;
	while(r-l>20)
	{
		for(int mid=((l+r)>>1)-5,ed=((l+r)>>1)+5;mid<=ed;++mid)
		{
			if(mid==ed) l=mid;
			ll a=f(mid);
			ll b=f(mid+1);
			if(a>b)
			{
				l=mid;
				break;
			}
			else if(a<b)
			{
				r=mid;
				break;
			}
		}
	}
	ll ans=1e18;
	for(int i=l;i<=r;++i)
	{
		chmin(ans,f(i));
	}
	printf("%lld\n",ans);
	return 0;
}