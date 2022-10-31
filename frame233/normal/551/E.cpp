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

const int N=500005;
ll a[N];
int bel[N];
struct node{
	ll val;
	int pos;
	Finline node(const ll V=0,const int P=0):val(V),pos(P){}
	Finline bool operator < (const node &o)const
	{
		return val==o.val?pos<o.pos:val<o.val;
	}
	Finline bool operator < (const ll &x)const
	{
		return val<x;
	}
};
Finline bool cmp(const ll &x,const node &b)
{
	return x<b.val;
}
struct block{
	int l,r;
	std::vector<node> v;
	ll tag;
}f[675];
const int block_size=750;
int block_tot;
void build(int n)
{
	int tmp=block_size,cur=0;
	for(int i=1;i<=n;++i)
	{
		++tmp;
		if(tmp>block_size)
		{
			f[cur].r=i-1;
			tmp=1;
			f[++cur].l=i;
		}
		bel[i]=cur;
		f[cur].v.push_back(node(a[i],i));
	}
	f[cur].r=n;
	block_tot=cur;
	for(int i=1;i<=cur;++i)
	{
		std::sort(f[i].v.begin(),f[i].v.end());
		f[i].tag=0;
	}
}
void rebuild(int cur)
{
	f[cur].v.clear();
	for(int i=f[cur].l;i<=f[cur].r;++i)
	{
		f[cur].v.push_back(node(a[i]+f[cur].tag,i));
		a[i]+=f[cur].tag;
	}
	std::sort(f[cur].v.begin(),f[cur].v.end());
	f[cur].tag=0;
}
void Update(int l,int r,ll C)
{
	if(bel[l]==bel[r])
	{
		for(int i=l;i<=r;++i)
		{
			a[i]+=C;
		}
		rebuild(bel[l]);
		return;
	}
	for(int i=bel[l]+1;i<bel[r];++i)
	{
		f[i].tag+=C;
	}
	for(int i=l;i<=f[bel[l]].r;++i)
	{
		a[i]+=C;
	}
	rebuild(bel[l]);
	for(int i=f[bel[r]].l;i<=r;++i)
	{
		a[i]+=C;
	}
	rebuild(bel[r]);
}
int Query_left(ll x)
{
	for(int i=1;i<=block_tot;++i)
	{
		std::vector<node>::iterator it=std::lower_bound(f[i].v.begin(),f[i].v.end(),x-f[i].tag);
		if(it!=f[i].v.end())
		{
			if(it->val+f[i].tag==x)
			{
				return it->pos;
			}
		}
	}
	return -1;
}
int Query_right(ll x)
{
	for(int i=block_tot;i>=1;--i)
	{
		std::vector<node>::iterator it=std::upper_bound(f[i].v.begin(),f[i].v.end(),x-f[i].tag,cmp);
		if(it!=f[i].v.begin())
		{
			--it;
			if(it->val+f[i].tag==x)
			{
				return it->pos;
			}
		}
	}
	return -2;
}
int main()
{
	int n,_;
	read(n,_);
	for(int i=1;i<=n;++i) read(a[i]);
	build(n);
	int opt,l,r;
	ll x;
	while(_--)
	{
		read(opt);
		if(opt==1)
		{
			read(l,r,x);
			Update(l,r,x);
		}
		else
		{
			read(x);
			printf("%d\n",Query_right(x)-Query_left(x));
		}
	}
    return 0;
}
//