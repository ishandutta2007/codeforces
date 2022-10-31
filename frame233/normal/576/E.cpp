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

const int N=500005;
int E[N][2];
struct node{
	int e,c;
}O[N];
int nxt[N];
int ans[N];
struct Node{
	int *pos,val;
}t[N*24];
int pos;
struct Union_set{
	int fa[N<<1],rnk[N<<1];
	Finline Union_set()
	{
		for(int i=0;i<N<<1;++i)
		{
			fa[i]=i;
		}
	}
	int find(int x){return x==fa[x]?x:find(fa[x]);}
	int merge(int x,int y)
	{
		x=find(x),y=find(y);
		if(x==y) return 0;
		if(rnk[x]>=rnk[y])
		{
			t[++pos]={fa+y,y};
			fa[y]=x;
			if(rnk[x]==rnk[y])
			{
				t[++pos]={rnk+x,rnk[x]};
				++rnk[x];
				return 2;
			}
		}
		else
		{
			t[++pos]={fa+x,x};
			fa[x]=y;
		}
		return 1;
	}
}S[51];
Finline void reset()
{
	*t[pos].pos=t[pos].val;
	--pos;
}
int last[N];
int limit;
struct seg_tr{
	struct Node{
		int ls,rs;
		std::vector<node> v;
	}f[N<<1];
	int node_cnt;
	int build(int l,int r)
	{
		int cur=++node_cnt;
		if(l==r) return cur;
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		return cur;
	}
	void Update(int L,int R,int l,int r,int cur,const node &o)
	{
		if(L<=l&&r<=R)
		{
			f[cur].v.push_back(o);
			return;
		}
		int mid=(l+r)>>1;
		if(L<=mid) Update(L,R,l,mid,f[cur].ls,o);
		if(R>mid) Update(L,R,mid+1,r,f[cur].rs,o);
	}
	void Query(int l,int r,int cur)
	{
		int siz=0;
		for(auto it:f[cur].v)
		{
			siz+=S[it.c].merge(E[it.e][0]+N,E[it.e][1]);
			siz+=S[it.c].merge(E[it.e][0],E[it.e][1]+N);
		}
		if(l==r)
		{
			int x=O[l].e,c=O[l].c;
			int x1=S[c].find(E[x][0]),y1=S[c].find(E[x][1]);
			int x2=S[c].find(E[x][0]+N),y2=S[c].find(E[x][1]+N);
			if(x1==y1||x2==y2)
			{
				ans[l]=false;
				if(l+1<=nxt[l]-1&&last[x]) Update(l+1,nxt[l]-1,1,limit,1,{x,last[x]});
			}
			else
			{
				ans[l]=true;
				if(l+1<=nxt[l]-1) Update(l+1,nxt[l]-1,1,limit,1,{x,c});
				last[x]=c;
			}
			while(siz--) reset();
			return;
		}
		int mid=(l+r)>>1;
		Query(l,mid,f[cur].ls);
		Query(mid+1,r,f[cur].rs);
		while(siz--) reset();
	}
}tr;
int tmp[N];
int main()
{
	int n,m,k,q;
	read(n,m,k,q);
	limit=q;
	for(int i=1;i<=m;++i)
	{
		read(E[i][0],E[i][1]);
	}
	for(int i=1;i<=q;++i)
	{
		read(O[i].e,O[i].c);
	}
	for(int i=1;i<=m;++i) tmp[i]=q+1;
	for(int i=q;i>=1;--i)
	{
		nxt[i]=tmp[O[i].e];
		tmp[O[i].e]=i;
	}
	tr.build(1,q);
	tr.Query(1,q,1);
	for(int i=1;i<=q;++i)
	{
		printf(ans[i]?"YES\n":"NO\n");
	}
	return 0;
}