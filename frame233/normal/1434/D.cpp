// Author -- xyr2005

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>inline void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=1000005;
struct edge{
	int v,nxt,w;
}c[N<<1];
int front[N],edge_cnt;
inline void addedge(int u,int v,int w)
{
	c[++edge_cnt]=(edge){v,front[u],w};
	front[u]=edge_cnt;
}
int dep[N],st[N];
int nd[N],E[N][2];
int t[N],p,rev[N];
int fir[N],end[N];
void dfs(int x,int fa)
{
	t[++p]=x,rev[p]=x,fir[x]=p;
	dep[x]=dep[fa]+1;
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v==fa) continue;
		st[v]=st[x]^c[i].w;
		dfs(v,x);
		t[++p]=x,rev[p]=x;
	}
	end[x]=p;
}
int n;
struct seg_tr{
	struct Node{
		int ls,rs;
		int minn,maxx[2],LM[2],MR[2],LMR[2];
		bool tag;
	}f[N<<1];
	int node_cnt;
	inline void PushUp(int x)
	{
		f[x].minn=min(f[f[x].ls].minn,f[f[x].rs].minn);
		for(int i=0;i<2;++i)
		{
			f[x].maxx[i]=max(f[f[x].ls].maxx[i],f[f[x].rs].maxx[i]);
			f[x].LMR[i]=max(max(f[f[x].ls].LMR[i],f[f[x].rs].LMR[i]),max(f[f[x].ls].LM[i]+f[f[x].rs].maxx[i],f[f[x].rs].MR[i]+f[f[x].ls].maxx[i]));
			f[x].LM[i]=max(max(f[f[x].ls].LM[i],f[f[x].rs].LM[i]),f[f[x].ls].maxx[i]-(f[f[x].rs].minn<<1));
			f[x].MR[i]=max(max(f[f[x].ls].MR[i],f[f[x].rs].MR[i]),f[f[x].rs].maxx[i]-(f[f[x].ls].minn<<1));
		}
	}
	int build(int l,int r)
	{
		int cur=++node_cnt;
		if(l==r)
		{
			for(int i=0;i<2;++i) f[cur].maxx[i]=f[cur].LM[i]=f[cur].MR[i]=f[cur].LMR[i]=-inf;
			f[cur].maxx[st[rev[l]]]=f[cur].minn=dep[rev[l]];
			f[cur].LM[st[rev[l]]]=f[cur].MR[st[rev[l]]]=-dep[rev[l]];
			f[cur].LMR[st[rev[l]]]=0;
			return cur;
		}
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		PushUp(cur);
		return cur;
	}
	inline void flip(int cur)
	{
		std::swap(f[cur].maxx[0],f[cur].maxx[1]);
		std::swap(f[cur].LM[0],f[cur].LM[1]);
		std::swap(f[cur].MR[0],f[cur].MR[1]);
		std::swap(f[cur].LMR[0],f[cur].LMR[1]);
		f[cur].tag^=1;
	}
	inline void PushDown(int cur)
	{
		if(f[cur].tag)
		{
			flip(f[cur].ls);
			flip(f[cur].rs);
			f[cur].tag=0;
		}
	}
	void Update(int L,int R,int l=1,int r=p,int cur=1)
	{
		if(L<=l&&r<=R)
		{
			flip(cur);
			return;
		}
		PushDown(cur);
		int mid=(l+r)>>1;
		if(L<=mid) Update(L,R,l,mid,f[cur].ls);
		if(R>mid) Update(L,R,mid+1,r,f[cur].rs);
		PushUp(cur);
	}
	inline int Query(){return max(f[1].LMR[0],f[1].LMR[1]);}
}tr;
int main()
{
	int n;read(n);
	int x,y,z;
	for(int i=1;i<n;++i)
	{
		read(x,y,z);
		addedge(x,y,z),addedge(y,x,z);
		E[i][0]=x,E[i][1]=y;
	}
	dfs(1,0);
	tr.build(1,p);
	for(int i=1;i<n;++i) nd[i]=dep[E[i][0]]>dep[E[i][1]]?E[i][0]:E[i][1];
	int m;read(m);
	while(m--)
	{
		read(x),x=nd[x];
		tr.Update(fir[x],end[x]);
		printf("%d\n",tr.Query());
	}
	return 0;
}