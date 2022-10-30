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
int cnt1[N],cnt2[N],cnt3[N];
int a[N],b[N],c[N];
int minn[N];
int main()
{
	int n1,n2,n3;
	read(n1),read(n2),read(n3);
	int n=n1+n2+n3;
	for(int i=1;i<=n1;++i)
	{
		read(a[i]);
		cnt1[a[i]]=1;
	}
	for(int i=1;i<=n2;++i)
	{
		read(b[i]);
		cnt2[b[i]]=1;
	}
	for(int i=1;i<=n3;++i)
	{
		read(c[i]);
		cnt3[c[i]]=1;
	}
	for(int i=1;i<=n;++i)
	{
		cnt1[i]+=cnt1[i-1];
		cnt2[i]+=cnt2[i-1];
		cnt3[i]+=cnt3[i-1];
	}
	for(int i=1;i<=n;++i)
	{
		minn[i]=min(minn[i-1],-cnt1[i]+cnt2[i]);
	}
	int ans=inf;
	for(int i=0;i<=n;++i)
	{
		chmin(ans,minn[i]-cnt2[i]+cnt3[i]);
	}
	printf("%d\n",ans+n1+n2);
    return 0;
}