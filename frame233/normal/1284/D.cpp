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
 
const int N=400005;
struct node{
	int sa,ea,sb,eb;
	Finline bool operator < (const node &o)const
	{
		return sa==o.sa?ea<o.eb:sa<o.sa;
	}
}a[N];
int t[N];
struct BIT1{
	int c[N];
	Finline void clear(){memset(c,-63,sizeof(c));}
	Finline void add(int x,int C){for(;x;x-=lowbit(x))chmax(c[x],C);}
	Finline int qry(int x){int ans=-inf;for(;x<=400000;x+=lowbit(x))chmax(ans,c[x]);return ans;}
}tr1;
struct BIT2{
	int c[N];
	Finline void clear(){memset(c,63,sizeof(c));}
	Finline void add(int x,int C){for(;x;x-=lowbit(x))chmin(c[x],C);}
	Finline int qry(int x){int ans=inf;for(;x<=400000;x+=lowbit(x))chmin(ans,c[x]);return ans;}
}tr2;
int main()
{
	int n;
	read(n);
	int pos=0;
	for(int i=1;i<=n;++i)
	{
		read(a[i].sa,a[i].ea);
		read(a[i].sb,a[i].eb);
		t[++pos]=a[i].sa;
		t[++pos]=a[i].ea;
		t[++pos]=a[i].sb;
		t[++pos]=a[i].eb;
	}
	std::sort(t+1,t+pos+1);
	int len=std::unique(t+1,t+pos+1)-t-1;
	for(int i=1;i<=n;++i)
	{
		a[i].sa=std::lower_bound(t+1,t+len+1,a[i].sa)-t;
		a[i].ea=std::lower_bound(t+1,t+len+1,a[i].ea)-t;
		a[i].sb=std::lower_bound(t+1,t+len+1,a[i].sb)-t;
		a[i].eb=std::lower_bound(t+1,t+len+1,a[i].eb)-t;
	}
	std::sort(a+1,a+n+1);
	tr1.clear();
	tr2.clear();
	for(int i=1;i<=n;++i)
	{
		int maxl=tr1.qry(a[i].sa);
		int minr=tr2.qry(a[i].sa);
		if(maxl>a[i].eb||minr<a[i].sb)
		{
			printf("NO\n");
			return 0;
		}
		tr1.add(a[i].ea,a[i].sb);
		tr2.add(a[i].ea,a[i].eb);
	}
	for(int i=1;i<=n;++i)
	{
		std::swap(a[i].sa,a[i].sb);
		std::swap(a[i].ea,a[i].eb);
	}
	std::sort(a+1,a+n+1);
	tr1.clear();
	tr2.clear();
	for(int i=1;i<=n;++i)
	{
		int maxl=tr1.qry(a[i].sa);
		int minr=tr2.qry(a[i].sa);
		if(maxl>a[i].eb||minr<a[i].sb)
		{
			printf("NO\n");
			return 0;
		}
		tr1.add(a[i].ea,a[i].sb);
		tr2.add(a[i].ea,a[i].eb);
	}
	printf("YES\n");
    return 0;
}