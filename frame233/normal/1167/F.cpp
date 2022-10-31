// Author -- Frame

#include<cstdio>
#include<cstring>
#include<algorithm>

#define Finline __inline__ __attribute__ ((always_inline))
#define lowbit(x) ((x)&(-x))

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
template <typename _Tp,typename... Args>Finline void read(_Tp& t, Args&... args)
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

const int N=500005,mod=1000000007;
int a[N],b[N];
Finline void add(int &a,const int &b){(a+=b)>=mod&&(a-=mod);}
int n;
struct BIT{
	int c[N];
	Finline void clear(){memset(c,0,sizeof(c));}
	Finline void Upd(int x,const int &C)
	{
		for(;x<=n;x+=lowbit(x))
		{
			add(c[x],C);
		}
	}
	Finline int sum(int x)
	{
		int ans=0;
		for(;x;x-=lowbit(x))
		{
			add(ans,c[x]);
		}
		return ans;
	}
}tr;
int main()
{
	int ans=0;
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
		b[i]=a[i];
	}
	std::sort(b+1,b+n+1);
	for(int i=1;i<=n;++i)
	{
		add(ans,1ll*i*(n-i+1)%mod*a[i]%mod);
		a[i]=std::lower_bound(b+1,b+n+1,a[i])-b;
	}
	for(int i=1;i<=n;++i)
	{
		add(ans,1ll*b[a[i]]*tr.sum(a[i])%mod*(n-i+1)%mod);
		tr.Upd(a[i],i);
	}
	tr.clear();
	for(int i=n;i>=1;--i)
	{
		add(ans,1ll*b[a[i]]*tr.sum(a[i])%mod*i%mod);
		tr.Upd(a[i],n-i+1);
	}
	printf("%d\n",ans);
	return 0;
}