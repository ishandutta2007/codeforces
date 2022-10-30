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

const int N=19;
int a[N];
int w[N][N];
ll f[1<<18][N];
int main()
{
	int n,m,k,x,y,z;
	read(n,m,k);
	int maxx=(1<<n)-1;
	for(int i=1;i<=n;++i) read(a[i]);
	for(int i=1;i<=k;++i)
	{
		read(x,y,z);
		w[x][y]+=z;
	}
	for(int i=1;i<=n;++i)
	{
		f[1<<(i-1)][i]=a[i];
	}
	for(int i=0;i<maxx;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if((i>>(j-1))&1)
			{
				for(int t=1;t<=n;++t)
				{
					if(!((i>>(t-1))&1))
					{
						chmax(f[i|(1<<(t-1))][t],f[i][j]+a[t]+w[j][t]);
					}
				}
			}
		}
	}
	ll ans=0;
	for(int i=0;i<=maxx;++i)
	{
		if(__builtin_popcount(i)==m)
		{
			for(int j=1;j<=n;++j)
			{
				if((i>>(j-1))&1)
				{
					chmax(ans,f[i][j]);
				}
			}
		}
	}
	printf("%lld\n",ans);
    return 0;
}