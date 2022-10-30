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
struct node{
	int x,y;
}a[N];
struct seg_tr{
	struct Node{
		int ls,rs;
		int cnt,len;
	}f[N<<2];
	int node_cnt;
	Finline void PushUp(const int &x,const int &l,const int &r)
	{
		if(f[x].cnt)
		{
			f[x].len=r-l+1;
		}
		else
		{
			f[x].len=f[f[x].ls].len+f[f[x].rs].len;
		}
	}
	void Update(const int &L,const int &R,const int &l,const int &r,int &cur,const int &val)
	{
		if(!cur)
		{
			cur=++node_cnt;
			f[cur].cnt=f[cur].len=f[cur].ls=f[cur].rs=0;
		}
		if(L<=l&&r<=R)
		{
			f[cur].cnt+=val;
			PushUp(cur,l,r);
			return;
		}
		int mid=(l+r)>>1;
		if(L<=mid) Update(L,R,l,mid,f[cur].ls,val);
		if(R>mid) Update(L,R,mid+1,r,f[cur].rs,val);
		PushUp(cur,l,r);
	}
	Finline int Query(){return f[1].len;}
}tr;
int n,m,k;
struct qry{
	int x,y1,y2,opt;
	Finline bool operator < (const qry &o)const
	{
		return x<o.x;
	}
}q[N];
int cnt;
Finline void Push(const int &x1,const int &y1,const int &x2,const int &y2)
{
	q[++cnt]=(qry){x1,y1,y2,1};
	q[++cnt]=(qry){x2+1,y1,y2,-1};
}
bool check(int x)
{
	cnt=0;
	for(int i=1;i<=k;++i)
	{
		Push(max(1,a[i].x-x),max(1,a[i].y-x),min(n,a[i].x+x),min(m,a[i].y+x));
	}
	tr.node_cnt=0;
	int root=0;
	std::sort(q+1,q+cnt+1);
	int minx=inf,maxx=-inf;
	q[0].x=-inf;
	for(int i=1;i<=cnt;++i)
	{
		if(i==1&&q[i].x!=1)
		{
			chmin(minx,1);
		}
		if(tr.Query()!=m)
		{
			chmax(maxx,q[i].x-1);
		}
		int j=i;
		while(j<cnt&&q[j+1].x==q[i].x) ++j;
		for(int k=i;k<=j;++k)
		{
			tr.Update(q[k].y1,q[k].y2,1,1000000000,root,q[k].opt);
		}
		i=j;
		if(tr.Query()!=m)
		{
			chmin(minx,q[i].x);
		}
		if(i==cnt&&q[i].x!=n+1)
		{
			chmax(maxx,n);
		}
	}
	cnt=0;
	for(int i=1;i<=k;++i)
	{
		Push(max(1,a[i].y-x),max(1,a[i].x-x),min(m,a[i].y+x),min(n,a[i].x+x));
	}
	tr.node_cnt=0;
	root=0;
	std::sort(q+1,q+cnt+1);
	int miny=inf,maxy=-inf;
	q[0].x=-inf;
	for(int i=1;i<=cnt;++i)
	{
		if(i==1&&q[i].x!=1)
		{
			chmin(miny,1);
		}
		if(tr.Query()!=n)
		{
			chmax(maxy,q[i].x-1);
		}
		int j=i;
		while(j<cnt&&q[j+1].x==q[i].x) ++j;
		for(int k=i;k<=j;++k)
		{
			tr.Update(q[k].y1,q[k].y2,1,1000000000,root,q[k].opt);
		}
		i=j;
		if(tr.Query()!=n)
		{
			chmin(miny,q[i].x);
		}
		if(i==cnt&&q[i].x!=m+1)
		{
			chmax(maxy,m);
		}
	}
	return (maxx-minx)<=x*2&&(maxy-miny)<=x*2;
}
int main()
{
	read(n,m,k);
	for(int i=1;i<=k;++i)
	{
		read(a[i].x,a[i].y);
	}
	int l=0,r=max(n,m);
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
    return 0;
}
// i dd zz