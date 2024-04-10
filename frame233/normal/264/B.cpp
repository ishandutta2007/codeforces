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

const int N=100005;
int t[N],f[N];
bool pr[N];
int a[N],pos;
int min_div[N];
int g[N];
void init(int n)
{
	pr[1]=1;
	for(int i=2;i<=n;++i)
	{
		if(!pr[i])
		{
			a[++pos]=i;
			min_div[i]=i;
		}
		for(int j=1;j<=pos&&i*a[j]<=n;++j)
		{
			pr[i*a[j]]=1;
			min_div[i*a[j]]=a[j];
			if(!(i%a[j]))
			{
				break;
			}
		}
	}
}
int main()
{
	init(100000);
	int n;
	read(n);
	for(int i=1;i<=n;++i) read(t[i]);
	std::sort(t+1,t+n+1);
	n=std::unique(t+1,t+n+1)-t-1;
	int x;
	int ans=1;
	for(int i=1;i<=n;++i)
	{
		x=t[i];
		while(x>1)
		{
			chmax(f[i],g[min_div[x]]+1);
			x/=min_div[x];
		}
		x=t[i];
		while(x>1)
		{
			chmax(g[min_div[x]],f[i]);
			x/=min_div[x];
		}
		chmax(ans,f[i]);
	}
	printf("%d\n",ans);
    return 0;
}