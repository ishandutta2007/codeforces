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

const int N=1005;
struct BIT{
	ll c[N][N];
	Finline void add(int x,int y,const ll &C)
	{
		for(;x<=1000;x+=lowbit(x))
		{
			for(int i=y;i<=1000;i+=lowbit(i))
			{
				c[x][i]^=C;
			}
		}
	}
	Finline ll sum(int x,int y)
	{
		ll ans=0;
		for(;x;x-=lowbit(x))
		{
			for(int i=y;i;i-=lowbit(i))
			{
				ans^=c[x][i];
			}
		}
		return ans;
	}
}tr[2][2];
Finline void Upd(const int &x1,const int &y1,const int &x2,const int &y2,const ll &C)
{
	tr[x1&1][y1&1].add(x1,y1,C);
	tr[x1&1][(y2+1)&1].add(x1,y2+1,C);
	tr[(x2+1)&1][y1&1].add(x2+1,y1,C);
	tr[(x2+1)&1][(y2+1)&1].add(x2+1,y2+1,C);
}
Finline ll Qry(const int &x1,const int &y1,const int &x2,const int &y2)
{
	return tr[x2&1][y2&1].sum(x2,y2)^tr[(x1-1)&1][y2&1].sum(x1-1,y2)^tr[x2&1][(y1-1)&1].sum(x2,y1-1)^tr[(x1-1)&1][(y1-1)&1].sum(x1-1,y1-1);
}
int main()
{
	int n,m;
	read(n,m);
	int x1,x2,y1,y2;
	ll C;
	int opt;
	while(m--)
	{
		read(opt);
		if(opt==1)
		{
			read(x1,y1,x2,y2);
			printf("%lld\n",Qry(x1,y1,x2,y2));
		}
		else
		{
			read(x1,y1,x2,y2,C);
			Upd(x1,y1,x2,y2,C);
		}
	}
    return 0;
}