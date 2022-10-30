// Author -- Frame

#include<cstdio>
#include<cstring>
#include<algorithm>

#define Finline __inline__ __attribute__ ((always_inline))

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7ffffffffffffff;

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline void read(_Tp& x)
{
    register char ch(getchar());
    bool f(false);
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
    x=ch&15,ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp& t,Args&... args)
{
    read(t);read(args...);
}
Finline int read_str(char *s)
{
    register char ch(getchar());
    while(ch<65||ch>122||(ch>90&&ch<97)) ch=getchar();
    register char *tar=s;
    *tar=ch,ch=getchar();
    while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) *(++tar)=ch,ch=getchar();
    return tar-s+1;
}

const int N=100005;
ll f[7005];
ll a[N];
int main()
{
	memset(f,-63,sizeof(f));
	ll _=f[0];
	ll w;
	read(w);
	for(int i=1;i<=8;++i)
	{
		read(a[i]);
	}
	f[0]=0;
	for(int i=1;i<=8;++i)
	{
		int sum=min(a[i],840ll/i);
		for(int j=6720;j>=0;--j)
		{
			for(int k=0;k<=sum;++k)
			{
				if(j>=k*i)
				{
					chmax(f[j],f[j-k*i]+(a[i]*i-k*i)/840ll);
				}
			}
		}
	}
	ll ans=0;
	for(int i=0;i<=6720&&i<=w;++i)
	{
		if(f[i]!=_)
		{
			chmax(ans,i+min(f[i],(w-i)/840)*840);
		}
	}
	printf("%lld\n",ans);
    return 0;
}