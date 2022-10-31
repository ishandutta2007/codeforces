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
const uint _RAND_MAX_=4294967295u;
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
    while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
    register char *tar=s;
    *tar=ch,ch=getchar();
    while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
    return tar-s+1;
}

const int N=100005;
struct Pair{
	int lenl,lenr,len;
	int l,r;
	Finline void print()
	{
		printf("[%d , %d] (%d , %d , %d)\n",l,r,lenl,lenr,len);
	}
	Finline void merge(const Pair &o)
	{
		chmax(len,max(o.len,lenr+o.lenl));
		if(lenl==r-l+1) lenl+=o.lenl;
		if(o.lenr==o.r-o.l+1) lenr=o.lenr+lenr;
		else lenr=o.lenr;
		r=o.r;
	}
};
struct seg_tr{
	struct Node{
		int ls,rs;
		Pair ans;
	}f[N<<6];
	int node_cnt;
	Finline void PushUp(const int &x)
	{
		f[x].ans=f[f[x].ls].ans;
		f[x].ans.merge(f[f[x].rs].ans);
	}
	int build(const int &l,const int &r)
	{
		int cur=++node_cnt;
		f[cur].ans.l=l,f[cur].ans.r=r;
		if(l==r) return cur;
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		return cur;
	}
	int Update(const int &pos,const int &l,const int &r,const int &rt)
	{
		int cur=++node_cnt;
		f[cur]=f[rt];
		if(l==r)
		{
			f[cur].ans.lenl=f[cur].ans.lenr=f[cur].ans.len=1;
			return cur;
		}
		int mid=(l+r)>>1;
		if(pos<=mid) f[cur].ls=Update(pos,l,mid,f[rt].ls);
		else f[cur].rs=Update(pos,mid+1,r,f[rt].rs);
		PushUp(cur);
		return cur;
	}
	Pair Query(const int &L,const int &R,const int &l,const int &r,const int &cur)
	{
		if(L<=l&&r<=R)
		{
			return f[cur].ans;
		}
		int mid=(l+r)>>1;
		if(L<=mid&&R>mid)
		{
			Pair lt=Query(L,R,l,mid,f[cur].ls);
			lt.merge(Query(L,R,mid+1,r,f[cur].rs));
			return lt;
		}
		if(L<=mid)
		{
			return Query(L,R,l,mid,f[cur].ls);
		}
		return Query(L,R,mid+1,r,f[cur].rs);
	}
}tr;
int t[N];
int a[N];
std::vector<int> v[N];
int n;
int root[N];
int main()
{
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
		t[i]=a[i];
	}
	std::sort(t+1,t+n+1);
	int len=std::unique(t+1,t+n+1)-t-1;
	for(int i=1;i<=n;++i)
	{
		a[i]=std::lower_bound(t+1,t+len+1,a[i])-t;
		v[a[i]].emplace_back(i);
	}
	root[len+1]=tr.build(1,n);
	int last=root[len+1];
	for(int i=len;i>=1;--i)
	{
		for(auto it:v[i])
		{
			last=tr.Update(it,1,n,last);
		}
		root[i]=last;
	}
	int _;
	read(_);
	int x,y,k;
	while(_--)
	{
		read(x,y,k);
		int l=1,r=len;
		while(l<r)
		{
			int mid=(l+r+1)>>1;
			if(tr.Query(x,y,1,n,root[mid]).len>=k) l=mid;
			else r=mid-1;
		}
		printf("%d\n",t[l]);
	}
    return 0;
}