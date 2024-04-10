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
const ll INF=0x7ffffffffffffff;
const double eps=1e-8;
 
uint seed=19260817;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const double &a,const double &b){return abs(a-b)<=eps;}
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
 
const int N=200005;
struct edge{
	int v,nxt;
	int dir;
}c[N<<1];
int front[N],cnt=-1;
int n;
int _q[N],_l,_r;
bool used[N];
Finline void add(const int &u,const int &v)
{
	c[++cnt]=(edge){v,front[u],0},front[u]=cnt;
	c[++cnt]=(edge){u,front[v],0},front[v]=cnt;
}
void MAIN(int opt)
{
	for(int i=0;i<=cnt;++i) c[i].dir=0;
	memset(used,0,sizeof(used));
	_q[_l=_r=1]=1;
	used[1]=1;
	while(_l!=_r+1)
	{
		int i=_q[_l++];
		int tmp=0;
		for(int _=front[i];~_;_=c[_].nxt)
		{
			if(c[_].dir)
			{
				if(!tmp)
				{
					tmp=c[_].dir;
				}
				else
				{
					if(tmp!=c[_].dir)
					{
						return;
					}
				}
			}
		}
		if(!tmp) tmp=opt;
		for(int _=front[i];~_;_=c[_].nxt)
		{
			c[_].dir=tmp;
			c[_^1].dir=-tmp;
			if(!used[c[_].v])
			{
				used[c[_].v]=1;
				_q[++_r]=c[_].v;
			}
		}
	}
	printf("YES\n");
	for(int i=0;i<=cnt;i+=2)
	{
		if(~c[i].dir)
		{
			putchar('0');
		}
		else
		{
			putchar('1');
		}
	}
	exit(0);
}
int main()
{
	memset(front,255,sizeof(front));
	int m,x,y;
	read(n,m);
	for(int i=1;i<=m;++i)
	{
		read(x,y);
		add(x,y);
	}
	MAIN(1);
	MAIN(-1);
	printf("NO\n");
    return 0;
}
///