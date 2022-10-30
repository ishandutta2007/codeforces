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

const int N=100005;
struct seg_tr{
	struct Node{
		int ls,rs;
		int minn;
	}f[N<<2];
	int node_cnt;
	Finline void PushUp(int x)
	{
		f[x].minn=min(f[f[x].ls].minn,f[f[x].rs].minn);
	}
	int build(int l,int r)
	{
		int cur=++node_cnt;
		f[cur].minn=inf;
		if(l==r)
		{
			return cur;
		}
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		return cur;
	}
	void Update(int pos,int l,int r,int cur,int val)
	{
		if(l==r)
		{
			chmin(f[cur].minn,val);
			return;
		}
		int mid=(l+r)>>1;
		if(pos<=mid) Update(pos,l,mid,f[cur].ls,val);
		else Update(pos,mid+1,r,f[cur].rs,val);
		PushUp(cur);
	}
	int Query(int L,int R,int l,int r,int cur)
	{
		if(L<=l&&r<=R)
		{
			return f[cur].minn;
		}
		int mid=(l+r)>>1;
		return min(L<=mid?Query(L,R,l,mid,f[cur].ls):inf,R>mid?Query(L,R,mid+1,r,f[cur].rs):inf);
	}
}tr;
struct node{
	int x,s;
	Finline bool operator < (const node &o)const
	{
		return x<o.x;
	}
}a[N];
int main()
{
	int n,m;
	read(n,m);
	for(int i=1;i<=n;++i) read(a[i].x,a[i].s);
	std::sort(a+1,a+n+1);
	m<<=1;
	int root=tr.build(0,m);
	tr.Update(0,0,m,root,0);
	for(int i=1;i<=n;++i)
	{
		for(int j=a[i].x+a[i].s;j<=m;++j)
		{
			tr.Update(j,0,m,root,tr.Query(max(0,(a[i].x<<1)-j-1),j,0,m,root)+j-a[i].x-a[i].s);
		}
	}
	printf("%d\n",tr.Query(m>>1,m,0,m,root));
    return 0;
}