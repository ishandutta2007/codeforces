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
std::vector<int> v[N];
struct seg_tr{
	struct Node{
		int ls,rs;
		int minn,pos;
		int tag;
	}f[N<<1];
	int node_cnt;
	Finline void PushUp(const int &x)
	{
		f[x].minn=f[f[x].ls].minn;
		f[x].pos=f[f[x].ls].pos;
		if(f[f[x].rs].minn<f[x].minn)
		{
			f[x].minn=f[f[x].rs].minn;
			f[x].pos=f[f[x].rs].pos;
		}
	}
	int build(const int &l,const int &r)
	{
		int cur=++node_cnt;
		if(l==r)
		{
			f[cur].minn=1;
			f[cur].pos=l;
			return cur;
		}
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		PushUp(cur);
		return cur;
	}
	Finline void add(const int &x,const int &val)
	{
		f[x].tag+=val;
		f[x].minn+=val;
	}
	Finline void PushDown(const int &x)
	{
		if(f[x].tag)
		{
			add(f[x].ls,f[x].tag);
			add(f[x].rs,f[x].tag);
			f[x].tag=0;
		}
	}
	void Update(const int &L,const int &R,const int &l,const int &r,const int &cur,const int &C)
	{
		if(L<=l&&r<=R)
		{
			add(cur,C);
			return;
		}
		PushDown(cur);
		int mid=(l+r)>>1;
		if(L<=mid) Update(L,R,l,mid,f[cur].ls,C);
		if(R>mid) Update(L,R,mid+1,r,f[cur].rs,C);
		PushUp(cur);
	}
	void Update(const int &pos,const int &l,const int &r,const int &cur)
	{
		if(l==r)
		{
			f[cur].minn=inf;
			return;
		}
		PushDown(cur);
		int mid=(l+r)>>1;
		if(pos<=mid) Update(pos,l,mid,f[cur].ls);
		else Update(pos,mid+1,r,f[cur].rs);
		PushUp(cur);
	}
	Finline int Query_nd(){return f[1].pos;}
	Finline int Query_cost(){return f[1].minn;}
}tr;
int main()
{
	int n,m;
	read(n,m);
	int x,y;
	for(int i=1;i<=m;++i)
	{
		read(x,y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;++i)
	{
		std::sort(v[i].begin(),v[i].end());
	}
	int ans=0;
	int root=tr.build(1,n);
	for(int i=1;i<=n;++i)
	{
		ans+=max(0,tr.Query_cost());
		int nd=tr.Query_nd();
		int last=1;
		for(auto it:v[nd])
		{
			if(last<it)
			{
				tr.Update(last,it-1,1,n,root,-1);
			}
			last=it+1;
		}
		if(last<=n) tr.Update(last,n,1,n,root,-1);
		tr.Update(nd,1,n,root);
	}
	printf("%d\n",ans-1);
    return 0;
}