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
 
const int N=300005;
int a[N],b[N];
struct node{
	int c[N];
	Finline void add(int x,const int &C){for(;x;x-=lowbit(x))chmax(c[x],C);}
	Finline int qry(int x){int ans=0;for(;x<N;x+=lowbit(x))chmax(ans,c[x]);return ans;}
}tr;
int t[N];
int pre[N];
int c[N];
int main()
{
	int n;
	read(n);
	int len=0;
	int maxx=0,minn=inf;
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
		t[++len]=a[i];
		t[++len]=(a[i]<<1)+1;
		b[i]=(a[i]<<1)+1;
		chmax(maxx,a[i]);
		chmin(minn,a[i]);
	}
	if(minn*2+1>maxx)
	{
		for(int i=1;i<=n;++i)
		{
			printf("-1 ");
		}
		printf("\n");
		return 0;
	}
	std::sort(t+1,t+len+1);
	len=std::unique(t+1,t+len+1)-t-1;
	for(int i=1;i<=n;++i)
	{
		a[i]=std::lower_bound(t+1,t+len+1,a[i])-t;
		b[i]=std::lower_bound(t+1,t+len+1,b[i])-t;
		a[i+n]=a[i];
		b[i+n]=b[i];
		a[i+n+n]=a[i];
		b[i+n+n]=b[i];
	}
	memset(c,63,sizeof(c));
	for(int i=1;i<=n*3;++i)
	{
		pre[i]=tr.qry(b[i]);
		tr.add(a[i],i); 
		if(pre[i])
		{
			chmin(c[pre[i]],i-1);
		}
	}
	for(int i=n*3;i>=1;--i)
	{
		chmin(c[i],c[i+1]);
	}
	for(int i=1;i<=n;++i)
	{
		printf("%d ",(c[i]-i+1)>=inf?-1:(c[i]-i+1));
	}
	printf("\n");
    return 0;
}