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

const int N=100005;
int a[N];
struct seg_tr{
	struct node{
		int ls,rs;
		ll sum,maxx;
	}f[N<<1];
	int node_cnt;
	Finline void PushUp(const int &x)
	{
		f[x].sum=f[f[x].ls].sum+f[f[x].rs].sum;
		f[x].maxx=max(f[f[x].ls].maxx,f[f[x].rs].maxx);
	}
	int build(const int &l,const int &r,int *arr)
	{
		int cur=++node_cnt;
		if(l==r)
		{
			f[cur].sum=arr[l];
			f[cur].maxx=arr[l];
			return cur;
		}
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid,arr);
		f[cur].rs=build(mid+1,r,arr);
		PushUp(cur);
		return cur;
	}
	void Update(const int &L,const int &R,const int &l,const int &r,const int &cur,const int &mod)
	{
		if(f[cur].maxx<mod) return;
		if(l==r)
		{
			f[cur].sum=f[cur].sum%mod;
			f[cur].maxx=f[cur].maxx%mod;
			return;
		}
		int mid=(l+r)>>1;
		if(L<=mid) Update(L,R,l,mid,f[cur].ls,mod);
		if(R>mid) Update(L,R,mid+1,r,f[cur].rs,mod);
		PushUp(cur);
	}
	void Modify(const int &pos,const int &l,const int &r,const int &cur,const int &C)
	{
		if(l==r)
		{
			f[cur].sum=C;
			f[cur].maxx=C;
			return;
		}
		int mid=(l+r)>>1;
		if(pos<=mid) Modify(pos,l,mid,f[cur].ls,C);
		else Modify(pos,mid+1,r,f[cur].rs,C);
		PushUp(cur);
	}
	ll Query(const int &L,const int &R,const int &l,const int &r,const int &cur)
	{
		if(L<=l&&r<=R) return f[cur].sum;
		int mid=(l+r)>>1;
		return (L<=mid?Query(L,R,l,mid,f[cur].ls):0)+(R>mid?Query(L,R,mid+1,r,f[cur].rs):0);
	}
}tr;
int main()
{
	int n,_;
	read(n,_);
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
	}
	int root=tr.build(1,n,a);
	int opt,l,r,x;
	while(_--)
	{
		read(opt);
		if(opt==1)
		{
			read(l,r);
			printf("%lld\n",tr.Query(l,r,1,n,root));
		}
		else if(opt==2)
		{
			read(l,r,x);
			tr.Update(l,r,1,n,root,x);
		}
		else
		{
			read(x,l);
			tr.Modify(x,1,n,root,l);
		}
	}
    return 0;
}
//