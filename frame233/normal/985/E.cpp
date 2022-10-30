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

const int N=500005;
bool f[N];
int a[N];
struct BIT{
	int c[N],n;
	Finline void add(int x,const int &C){for(;x<=n;x+=lowbit(x))c[x]+=C;}
	Finline int sum(int x){int ans=0;for(;x;x-=lowbit(x))ans+=c[x];return ans;}
}tr;
int main()
{
	int n,k,d;
	read(n,k,d);
	for(int i=1;i<=n;++i) read(a[i]);
	std::sort(a+1,a+n+1);
	f[0]=true;
	tr.n=n;
	tr.add(1,1);
	for(int i=1;i<=n;++i)
	{
		int l=std::lower_bound(a+1,a+i,a[i]-d)-a,r=i-k+1;
		if(l<=r) f[i]=!!(tr.sum(r)-(l>1?tr.sum(l-1):0));
		if(f[i]) tr.add(i+1,1);
	}
	printf(f[n]?"YES\n":"NO\n");
    return 0;
}