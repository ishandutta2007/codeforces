// luogu-judger-enable-o2
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
const double eps=1e-8;

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

const int N=200005;
struct node{
	int l,r,cost;
}a[N],b[N];
ll tmp[N];
Finline bool cmp1(const node &a,const node &b){return a.r>b.r;}
Finline bool cmp2(const node &a,const node &b){return a.l>b.l;}
int main()
{
	memset(tmp,63,sizeof(tmp));
	int n,m;
	read(n,m);
	for(int i=1;i<=n;++i)
	{
		read(a[i].l,a[i].r,a[i].cost);
		b[i]=a[i];
	}
	std::sort(a+1,a+n+1,cmp1);
	std::sort(b+1,b+n+1,cmp2);
	int pos=0;
	ll ans=1e18;
	for(int i=1;i<=n;++i)
	{
		while(pos<n&&b[pos+1].l>a[i].r)
		{
			++pos;
			chmin(tmp[b[pos].r-b[pos].l+1],(ll)b[pos].cost);
		}
		if(m-(a[i].r-a[i].l+1)>=0) chmin(ans,a[i].cost+tmp[m-(a[i].r-a[i].l+1)]);
	}
	printf("%lld\n",ans>=1e18?-1:ans);
    return 0;
}