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
Finline bool _cmp(const double &a,const double &b){return abs(a-b)<=eps;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool ismax(_Tp &a,const _Tp &b){return a>=b?1:a=b,0;}
template <typename _Tp>Finline bool ismin(_Tp &a,const _Tp &b){return a<=b?1:a=b,0;}
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
 
const int N=100005;
ll a[N];
std::vector<ll> v[65];
ll mp[205][205];
ll dis[205][205];
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
	}
	int cnt=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<63;++j)
		{
			if((a[i]>>j)&1)
			{
				v[j].push_back(a[i]);
				++cnt;
			}
		}
	}
	for(int i=0;i<63;++i)
	{
		if((int)v[i].size()>=3)
		{
			printf("3\n");
			return 0;
		}
	}
	int pos=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i])
		{
			a[++pos]=a[i];
		}
	}
	n=pos;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(a[i]&a[j])
			{
				mp[i][j]=1;
				dis[i][j]=1;
			}
			else
			{
				mp[i][j]=dis[i][j]=inf;
			}
		}
		mp[i][i]=dis[i][i]=0;
	}
	ll mina=INF;
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<k;i++)
        {
            for(int j=i+1;j<k;j++)
            {  
                mina=min(dis[i][j]+mp[j][k]+mp[k][i],mina);
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)  
            {  
                if(dis[i][j]>dis[i][k]+dis[k][j])
                {
					dis[i][j]=dis[i][k]+dis[k][j];
			    }
            }
        }
    }
    if(mina<inf) printf("%lld\n",mina);
    else printf("-1\n");
	return 0;
}