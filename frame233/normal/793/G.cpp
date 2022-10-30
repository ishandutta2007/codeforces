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

const int N=100005;
namespace flow
{
	struct edge{
		int v,nxt;
		int w;
	}c[N*100];
	int front[N],edge_cnt;
	int cur[N],dep[N],S,T;
	int _q[N],_l,_r;
	int node_cnt;
	inline void addedge(int u,int v,int w)
	{
		c[++edge_cnt]=(edge){v,front[u],w},front[u]=edge_cnt;
		c[++edge_cnt]=(edge){u,front[v],0},front[v]=edge_cnt;
	}
	inline void init(){memset(front,255,sizeof(front)),edge_cnt=-1;}
	bool bfs()
	{
		memset(dep,255,(node_cnt+3)<<2);
		memcpy(cur,front,(node_cnt+3)<<2);
		dep[S]=0;
		_q[_l=_r=1]=S;
		while(_l!=_r+1)
		{
			int x=_q[_l++];
			for(int i=front[x];~i;i=c[i].nxt)
			{
				if(c[i].w&&!~dep[c[i].v])
				{
					dep[c[i].v]=dep[x]+1;
					_q[++_r]=c[i].v;
				}
			}
		}
		return ~dep[T];
	}
	int dfs(int x,int flow)
	{
		if(x==T||!flow) return flow;
		int f=0,rf;
		for(int &i=cur[x];~i;i=c[i].nxt)
		{
			if(dep[c[i].v]==dep[x]+1&&(rf=dfs(c[i].v,min(flow,c[i].w))))
			{
				flow-=rf,f+=rf;
				c[i].w-=rf,c[i^1].w+=rf;
				if(!flow) return f;
			}
		}
		return f;
	}
	int dinic()
	{
		int ans=0;
		while(bfs()) ans+=dfs(S,inf);
		return ans;
	}
}
using namespace flow;
int ls[N<<2],rs[N<<2],n;
int build1(int l,int r)
{
	if(l==r) return l+n;
	int cur=++node_cnt,mid=(l+r)>>1;
	addedge(cur,ls[cur]=build1(l,mid),inf);
	addedge(cur,rs[cur]=build1(mid+1,r),inf);
	return cur;
}
int build2(int l,int r)
{
	if(l==r) return l;
	int cur=++node_cnt,mid=(l+r)>>1;
	addedge(ls[cur]=build2(l,mid),cur,inf);
	addedge(rs[cur]=build2(mid+1,r),cur,inf);
	return cur;
}
void query1(int L,int R,int l,int r,int cur,int val)
{
	if(L<=l&&r<=R)
	{
		addedge(val,cur,inf);
		return;
	}
	int mid=(l+r)>>1;
	if(L<=mid) query1(L,R,l,mid,ls[cur],val);
	if(R>mid) query1(L,R,mid+1,r,rs[cur],val);
}
void query2(int L,int R,int l,int r,int cur,int val)
{
	if(L<=l&&r<=R)
	{
		addedge(cur,val,inf);
		return;
	}
	int mid=(l+r)>>1;
	if(L<=mid) query2(L,R,l,mid,ls[cur],val);
	if(R>mid) query2(L,R,mid+1,r,rs[cur],val);
}
struct node{
	int y1,y2;
};
std::vector<node> v1[N];
std::vector<node> v2[N];
int cnt[N];
int nxt[N],last[N],rt1,rt2;
void push(int i,int j)
{
	if(last[j])
	{
		int a=++node_cnt,b=++node_cnt;
		query2(last[j],i-1,1,n,rt2,a);
		query1(j,nxt[j],1,n,rt1,b);
		addedge(a,b,inf);
		last[j]=nxt[j]=0;
	}
}
int main()
{
	init();
	int q;read(n,q);
	node_cnt=n+n+2,S=n+n+1,T=n+n+2;
	int x1,y1,x2,y2;
	for(int i=1;i<=q;++i)
	{
		read(x1,y1,x2,y2);
		v1[x1].pb((node){y1,y2});
		v2[x2+1].pb((node){y1,y2});
	}
	rt1=build1(1,n);
	rt2=build2(1,n);
	for(int i=1;i<=n;++i) addedge(S,i,1),addedge(i+n,T,1);
	for(int i=1;i<=n;++i)
	{
		for(auto it:v1[i]) for(int k=it.y1;k<=it.y2;++k) ++cnt[k];
		for(auto it:v2[i]) for(int k=it.y1;k<=it.y2;++k) --cnt[k];
		for(int j=1;j<=n;++j)
		{
			if(cnt[j])
			{
				push(i,j);
				continue;
			}
			int k=j;
			while(k<n&&!cnt[k+1]) ++k;
			if(nxt[j]!=k)
			{
				push(i,j);
				last[j]=i,nxt[j]=k;
			}
			for(int t=j+1;t<=k;++t) push(i,t);
			j=k;
		}
	}
	for(int j=1;j<=n;++j) push(n+1,j);
	printf("%d\n",dinic());
	return 0;
}
;