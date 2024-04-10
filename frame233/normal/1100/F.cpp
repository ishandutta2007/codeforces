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
    while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
    register char *tar=s;
    *tar=ch,ch=getchar();
    while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
    return tar-s+1;
}

const int N=500005;
struct LBase{
	int d[21],id[N];
	void Insert(int x,int ID)
	{
		for(int i=20;~i;--i)
		{
			if((x>>i)&1)
			{
				if(d[i])
				{
					if(ID>id[i])
					{
						std::swap(id[i],ID);
						std::swap(d[i],x);
					}
					x^=d[i];
				}
				else
				{
					d[i]=x;
					id[i]=ID;
					return;
				}
			}
		}
	}
	int Query(int l)
	{
		int ans=0;
		for(int i=20;~i;--i)
		{
			if(id[i]>=l)
			{
				chmax(ans,ans^d[i]);
			}
		}
		return ans;
	}
}B;
struct node{
	int v,nxt,id;
}q[N];
int front[N],cnt;
Finline void add(const int &u,const int &v,const int &id)
{
	q[++cnt]=(node){v,front[u],id},front[u]=cnt;
}
int ans[N];
int a[N];
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i) read(a[i]);
	int _,x,y;
	read(_);
	for(int i=1;i<=_;++i)
	{
		read(x,y);
		add(y,x,i);
	}
	for(int i=1;i<=n;++i)
	{
		B.Insert(a[i],i);
		for(int j=front[i];j;j=q[j].nxt)
		{
			ans[q[j].id]=B.Query(q[j].v);
		}
	}
	for(int i=1;i<=_;++i) printf("%d\n",ans[i]);
    return 0;
}