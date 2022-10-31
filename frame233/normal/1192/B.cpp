// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

Finline uint rnd()
{
	static uint seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());
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
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=200005;
struct edge{
	int v,nxt;
	ll w;
}c[N<<1];
int front[N],edge_cnt=-1;
Finline void addedge(int u,int v,ll w)
{
	c[++edge_cnt]=(edge){v,front[u],w};
	front[u]=edge_cnt;
}
ll dis[N];
int t[N],p,rev[N];
int nd[N];
int fir[N],end[N];
void dfs(int x,int fa)
{
	t[++p]=x;
	rev[p]=x;
	fir[x]=p;
	for(int i=front[x];~i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v!=fa)
		{
			nd[i>>1]=v;
			dis[v]=dis[x]+c[i].w;
			dfs(v,x);
			t[++p]=x;
			rev[p]=x;
		}
	}
	end[x]=p;
}
int n;
struct seg_tr{
	struct Node{
		int ls,rs;
		ll minn,maxx,LM,MR,LMR,tag;
	}f[N<<1];
	int node_cnt;
	Finline void PushUp(int x)
	{
		f[x].minn=min(f[f[x].ls].minn,f[f[x].rs].minn);
		f[x].maxx=max(f[f[x].ls].maxx,f[f[x].rs].maxx);
		f[x].LMR=max(max(f[f[x].ls].LMR,f[f[x].rs].LMR),max(f[f[x].ls].LM+f[f[x].rs].maxx,f[f[x].rs].MR+f[f[x].ls].maxx));
		f[x].LM=max(max(f[f[x].ls].LM,f[f[x].rs].LM),f[f[x].ls].maxx-(f[f[x].rs].minn<<1));
		f[x].MR=max(max(f[f[x].ls].MR,f[f[x].rs].MR),f[f[x].rs].maxx-(f[f[x].ls].minn<<1));
	}
	int build(int l,int r)
	{
		int cur=++node_cnt;
		if(l==r)
		{
			f[cur].maxx=f[cur].minn=dis[rev[l]];
			f[cur].LM=f[cur].MR=-dis[rev[l]];
			f[cur].LMR=0;
			return cur;
		}
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		PushUp(cur);
		return cur;
	}
	Finline void add(int cur,ll C)
	{
		f[cur].tag+=C;
		f[cur].minn+=C;
		f[cur].maxx+=C;
		f[cur].LM-=C;
		f[cur].MR-=C;
	}
	Finline void PushDown(int cur)
	{
		if(f[cur].tag)
		{
			add(f[cur].ls,f[cur].tag);
			add(f[cur].rs,f[cur].tag);
			f[cur].tag=0;
		}
	}
	void Update(int L,int R,ll C,int l=1,int r=p,int cur=1)
	{
		if(L<=l&&r<=R)
		{
			add(cur,C);
			return;
		}
		PushDown(cur);
		int mid=(l+r)>>1;
		if(L<=mid) Update(L,R,C,l,mid,f[cur].ls);
		if(R>mid) Update(L,R,C,mid+1,r,f[cur].rs);
		PushUp(cur);
	}
	Finline ll Query(){return f[1].LMR;}
}tr;
ll E[N];
int main()
{
	memset(front,255,sizeof(front));
	int q;
	ll w,z;
	read(n,q,w);
	int x,y;
	for(int i=1;i<n;++i)
	{
		read(x,y,z);
		addedge(x,y,z),addedge(y,x,z);
		E[i-1]=z;
	}
	dfs(1,0);
	tr.build(1,p);
	ll lastans=0;
	while(q--)
	{
		read(x,z);
		x=(x+lastans)%(n-1),z=(z+lastans)%w;
		tr.Update(fir[nd[x]],end[nd[x]],z-E[x]);
		E[x]=z;
		printf("%lld\n",lastans=tr.Query());
	}
	return 0;
}