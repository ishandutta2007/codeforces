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

const int N=400005;
int a[N];
ll sum[23][23];
std::vector<int> v[23];
ll f[1<<20];
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
		--a[i];
		v[a[i]].emplace_back(i);
	}
	for(int i=0;i<20;++i)
	{
		for(int j=0;j<20;++j)
		{
			if(i==j) continue;
			int pos2=-1;
			for(int pos1=0;pos1<(int)v[i].size();++pos1)
			{
				while(pos2+1<(int)v[j].size()&&v[i][pos1]>=v[j][pos2+1])
				{
					++pos2;
				}
				sum[i][j]+=pos2+1;
			}
		}
	}
	memset(f,63,sizeof(f));
	f[0]=0;
	std::vector<int> c;
	for(int st=0;st<(1<<20);++st)
	{
		c.clear();
		for(int i=0;i<20;++i)
		{
			if((st>>i)&1)
			{
				c.emplace_back(i);
			}
		}
		for(int i=0;i<20;++i)
		{
			if((st>>i)&1)
			{
				continue;
			}
			ll cost=0;
			for(auto it:c)
			{
				cost+=sum[it][i];
			}
			chmin(f[st|(1<<i)],f[st]+cost);
		}
	}
	printf("%lld\n",f[(1<<20)-1]);
    return 0;
}