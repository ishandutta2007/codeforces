// Author -- Frame

#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<bitset>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7ffffffffffffff;

uint seed=19260817;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool ismax(_Tp &a,const _Tp &b){return a>b?1:a=b,0;}
template <typename _Tp>Finline bool ismin(_Tp &a,const _Tp &b){return a<b?1:a=b,0;}
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
	while(ch<65||ch>122||(ch>90&&ch<97)) ch=getchar();
	register char *tar=s;
	*tar=ch,ch=getchar();
	while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=5005;
struct node{
	int x1,y1,x2,y2;
}a[N],b[N];
std::bitset<5005> bt[2505];
int main()
{
	int n;
	int x1,y1,x2,y2;
	read(n);
	int pos1=0,pos2=0;
	for(int i=1;i<=n;++i)
	{
		read(x1,y1,x2,y2);
		if(x1>x2)
		{
			std::swap(x1,x2);
		}
		if(y1>y2)
		{
			std::swap(y1,y2);
		}
		if(y1==y2)
		{
			a[++pos1]=(node){x1,y1,x2,y2};
		}
		else
		{
			b[++pos2]=(node){x1,y1,x2,y2};
		}
	}
	if(pos1<pos2)
	{
		for(int i=1;i<=pos1;++i)
		{
			for(int j=1;j<=pos2;++j)
			{
				if(b[j].x1>=a[i].x1&&b[j].x1<=a[i].x2&&b[j].y1<=a[i].y1&&b[j].y2>=a[i].y2)
				{
					bt[i].set(j);
				}
			}
		}
		ll ans=0;
		for(int i=1;i<pos1;++i)
		{
			for(int j=i+1;j<=pos1;++j)
			{
				int tmp=(bt[i]&bt[j]).count();
				ans+=tmp*(tmp-1)>>1;
			}
		}
		printf("%lld\n",ans);
	}
	else
	{
		for(int i=1;i<=pos2;++i)
		{
			for(int j=1;j<=pos1;++j)
			{
				if(a[j].y1>=b[i].y1&&a[j].y1<=b[i].y2&&a[j].x1<=b[i].x1&&a[j].x2>=b[i].x1)
				{
					bt[i].set(j);
				}
			}
		}
		ll ans=0;
		for(int i=1;i<pos2;++i)
		{
			for(int j=i+1;j<=pos2;++j)
			{
				int tmp=(bt[i]&bt[j]).count();
				ans+=tmp*(tmp-1)>>1;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}