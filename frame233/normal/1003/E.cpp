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

const int N=500005;
std::vector<int> id[N];
std::vector<std::pair<int,int> > v;
int dg[N];
int n,d,k;
bool check()
{
	for(auto it:v)
	{
		++dg[it.first];
		++dg[it.second];
	}
	for(int i=1;i<=n;++i)
	{
		if(dg[i]>k)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	read(n,d,k);
	for(int i=1;i<=d;++i)
	{
		v.emplace_back(std::make_pair(i,i+1));
	}
	int rest=n-d-1;
	if(rest<0)
	{
		printf("NO\n");
		return 0;
	}
	int node_cnt=d+1;
	int maxx=0;
	for(int i=2;i<=d;++i)
	{
		id[min(i-1,d+1-i)].emplace_back(i);
		chmax(maxx,min(i-1,d+1-i));
	}
	for(int dis=maxx;dis>=1&&rest;--dis)
	{
		for(int _i=0;_i<(int)id[dis].size();++_i)
		{
			int i=id[dis][_i];
			for(int _=1;_<=k-2;++_)
			{
				int tmp=dis;
				if(rest>tmp)
				{
					rest-=tmp;
					int last=i;
					int cnt=tmp;
					while(tmp--)
					{
						--cnt;
						v.emplace_back(std::make_pair(last,++node_cnt));
						last=node_cnt;
						id[cnt].emplace_back(last);
					}
				}
				else
				{
					int last=i;
					while(rest--)
					{
						v.emplace_back(std::make_pair(last,++node_cnt));
						last=node_cnt;
					}
					if(check())
					{
						printf("YES\n");
						for(auto it:v)
						{
							printf("%d %d\n",it.first,it.second);
						}
					}
					else
					{
						printf("NO\n");
					}
					return 0;
				}
			}
		}
	}
	if(node_cnt==n&&check())
	{
		printf("YES\n");
		for(auto it:v)
		{
			printf("%d %d\n",it.first,it.second);
		}
	}
	else
	{	
		printf("NO\n");
	}
    return 0;
}