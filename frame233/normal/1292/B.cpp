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

const int N=100005;
ll x[N],y[N];
int len;
ll calc(int cur,ll px,ll py,ll rest)
{
	ll tx=px,ty=py,qwq=rest,qaq=cur;
	ll res1=0;
	while(cur>=0)
	{
		if(rest>=abs(px-x[cur])+abs(py-y[cur]))
		{
			rest-=abs(px-x[cur])+abs(py-y[cur]);
			++res1;
			px=x[cur],py=y[cur];
			--cur;
		}
		else
		{
			break;
		}
	}
	px=tx,py=ty,rest=qwq,cur=qaq;
	ll res2=0;
	while(cur<=len)
	{
		if(rest>=abs(px-x[cur])+abs(py-y[cur]))
		{
			rest-=abs(px-x[cur])+abs(py-y[cur]);
			++res2;
			px=x[cur],py=y[cur];
			++cur;
		}
		else
		{
			break;
		}
	}
	return max(res1,res2);
}
int main()
{
	ll x0,y0,ax,ay,bx,by;
	read(x0,y0,ax,ay,bx,by);
	int cur=-1;
	while(x0<=1000000000000000000LL&&y0<=1000000000000000000LL)
	{
		++cur;
		x[cur]=x0,y[cur]=y0;
		if((double)x0*ax+bx<1e18&&(double)y0*ay+by<1e18) x0=(x0*ax+bx),y0=(y0*ay+by);
		else break;
	}
	len=cur;
	ll sx,sy,t;
	read(sx,sy,t);
	ll ans=0;
	for(int i=0;i<=cur;++i)
	{
		chmax(ans,calc(i,sx,sy,t));
	}
	printf("%lld\n",ans);
    return 0;
}