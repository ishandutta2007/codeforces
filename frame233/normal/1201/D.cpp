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
int minn[N],maxx[N];
struct node{
	int x,y;
}a[N];
int t[N];
int l_min[N],r_min[N];
int b[N];
ll f[N][2];
int main()
{
	memset(minn,63,sizeof(minn));
	memset(maxx,-63,sizeof(maxx));
	int n,m,k,q,r,c,x;
	read(n,m,k,q);
	for(int i=1;i<=k;++i)
	{
		read(r,c);
		chmin(minn[r],c);
		chmax(maxx[r],c);
	}
	for(int i=1;i<=q;++i)
	{
		read(x);
		b[x]=1;
	}
	l_min[0]=-1;
	for(int i=1;i<=m;++i)
	{
		if(b[i])
		{
			l_min[i]=i;
		}
		else
		{
			l_min[i]=l_min[i-1];
		}
	}
	r_min[m+1]=-1;
	for(int i=m;i>=1;--i)
	{
		if(b[i])
		{
			r_min[i]=i;
		}
		else
		{
			r_min[i]=r_min[i+1];
		}
	}
	int pos=0;
	for(int i=1;i<=n;++i)
	{
		if(minn[i]<inf)
		{
			a[++pos]=(node){minn[i],maxx[i]};
			t[pos]=i;
		}
	}
	memset(f,63,sizeof(f));
	int p=0;
	if(t[1]==1)
	{
		f[1][0]=a[1].y-1+a[1].y-a[1].x,f[1][1]=a[1].y-1;
		p=1;
	}
	else
	{
		a[0].x=a[0].y=1;
		f[0][1]=0;
		t[0]=1;
	}
	for(int i=p;i<pos;++i)
	{
		if(~l_min[a[i].x])
		{
			chmin(f[i+1][0],a[i].x-l_min[a[i].x]+t[i+1]-t[i]+f[i][0]+abs(a[i+1].y-l_min[a[i].x])+abs(a[i+1].y-a[i+1].x));
			chmin(f[i+1][1],a[i].x-l_min[a[i].x]+t[i+1]-t[i]+f[i][0]+abs(a[i+1].x-l_min[a[i].x])+abs(a[i+1].x-a[i+1].y));
		}
		if(~r_min[a[i].x])
		{
			chmin(f[i+1][0],r_min[a[i].x]-a[i].x+t[i+1]-t[i]+f[i][0]+abs(a[i+1].y-r_min[a[i].x])+abs(a[i+1].y-a[i+1].x));
			chmin(f[i+1][1],r_min[a[i].x]-a[i].x+t[i+1]-t[i]+f[i][0]+abs(a[i+1].x-r_min[a[i].x])+abs(a[i+1].x-a[i+1].y));
		}
		if(~l_min[a[i].y])
		{
			chmin(f[i+1][0],a[i].y-l_min[a[i].y]+t[i+1]-t[i]+f[i][1]+abs(a[i+1].y-l_min[a[i].y])+abs(a[i+1].y-a[i+1].x));
			chmin(f[i+1][1],a[i].y-l_min[a[i].y]+t[i+1]-t[i]+f[i][1]+abs(a[i+1].x-l_min[a[i].y])+abs(a[i+1].x-a[i+1].y));
		}
		if(~r_min[a[i].y])
		{
			chmin(f[i+1][0],r_min[a[i].y]-a[i].y+t[i+1]-t[i]+f[i][1]+abs(a[i+1].y-r_min[a[i].y])+abs(a[i+1].y-a[i+1].x));
			chmin(f[i+1][1],r_min[a[i].y]-a[i].y+t[i+1]-t[i]+f[i][1]+abs(a[i+1].x-r_min[a[i].y])+abs(a[i+1].x-a[i+1].y));
		}
	}
	printf("%lld\n",min(f[pos][0],f[pos][1]));
    return 0;
}