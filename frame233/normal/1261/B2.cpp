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

const int N=200005;
struct node{
	int val,pos;
	Finline bool operator < (const node &o)const
	{
		return val==o.val?pos<o.pos:val>o.val;
	}
}a[N];
struct Qry{
	int k,pos,id;
	Finline bool operator < (const Qry &o)const
	{
		return k<o.k;
	}
}q[N];
int ans[N];
struct BIT{
	int c[N];
	Finline void add(int x,int C){for(;x<=200000;x+=lowbit(x))c[x]+=C;}
	Finline int sum(int x){int ans=0;for(;x;x-=lowbit(x))ans+=c[x];return ans;}
}tr;
int t[N];
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(a[i].val);
		t[i]=a[i].val;
		a[i].pos=i;
	}
	std::sort(a+1,a+n+1);
	int _;
	read(_);
	for(int i=1;i<=_;++i)
	{
		read(q[i].k,q[i].pos);
		q[i].id=i;
	}
	std::sort(q+1,q+_+1);
	int cur=0;
	for(int i=1;i<=_;++i)
	{
		while(cur<q[i].k)
		{
			++cur;
			tr.add(a[cur].pos,1);
		}
		int l=0,r=n;
		while(l<r)
		{
			int mid=(l+r+1)>>1;
			if(tr.sum(mid)<q[i].pos) l=mid;
			else r=mid-1;
		}
		ans[q[i].id]=t[l+1];
	}
	for(int i=1;i<=_;++i)
	{
		printf("%d\n",ans[i]);
	}
    return 0;
}