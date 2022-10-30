// Author -- Frame

#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<algorithm>
#include<iostream>
#include<vector>
#include<bitset>
#include<queue>
#include<set>
#include<map>

#define pb push_back
#define Finline __inline__ __attribute__ ((always_inline))
#define err(x) cerr<<"% "<<x<<endl
#define DEBUG cerr<<"Running on Line "<<__LINE__<<" in Function "<<__FUNCTION__<<endl

using std::vector;
using std::bitset;
using std::set;
using std::map;
using std::priority_queue;
using std::pair;
using std::sort;
using std::unique;
using std::lower_bound;
using std::upper_bound;
using std::cerr;
using std::string;
using std::endl;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7ffffffffffffff;

void file()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline void read(_Tp& x)
{
    register char ch(getchar());
    bool f(false);
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
    x=ch&15,ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp& t,Args&... args)
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

const int N=1000005;
int dg[N],tmp[N];
int x[N],y[N];
int t[N];
bool rem[N];
Finline bool cmp(int a,int b){return min(dg[x[a]],dg[y[a]])<min(dg[x[b]],dg[y[b]]);}
int main()
{
	int n,m;
	read(n,m);
	for(int i=1;i<=m;++i)
	{
		read(x[i],y[i]);
		++dg[x[i]],++dg[y[i]];
		t[i]=i;
	}
	int maxx=(n+m+1)/2;
	while(1)
	{
		for(int i=1;i<=n;++i) tmp[i]=dg[i]>>1;
		int ans=0;
		for(int i=1;i<=m;++i)
		{
			int id=t[i];
			if(tmp[x[id]]>0&&tmp[y[id]]>0)
			{
				--tmp[x[id]];
				--tmp[y[id]];
				rem[id]=1;
			}
			else
			{
				++ans;
			}
		}
		if(ans<=maxx)
		{
			printf("%d\n",ans);
			for(int i=1;i<=m;++i)
			{
				if(!rem[i])
				{
					printf("%d %d\n",x[i],y[i]);
				}
			}
			return 0;
		}
		memset(rem,0,m+3);
		std::random_shuffle(t+1,t+m+1);
	}
	return 0;
}
//