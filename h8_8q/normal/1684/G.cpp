#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<random>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>

#define int long long
#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define pb(x) push_back(x)
#define lowbit(x) ((x)&(-(x)))
#define fan(x) ((((x)-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define INF 0x3f3f3f3f

using namespace std;

inline int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<1)+(ans<<3)+c-'0';c=getchar();}
	return ans*f;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=2e3+5;
int n,m,a[N],tg[N];

vector<int> l,r;

vector<pair<int,int> > ans;

struct Dinic
{
	static const int _N=N,_M=N*N;
	
	int s,t,k,dep[_N],idl[N],idr[N];
	
	struct Edge
	{
		int v,w,ne;
	}e[_M*2];
	int head[_N],cur[_N],tot;
	
	inline void add(int u,int v,int w)
	{
		e[++tot]=(Edge){v,w,head[u]};head[u]=tot;
		e[++tot]=(Edge){u,0,head[v]};head[v]=tot;
	}
	
	inline bool bfs()
	{
		for(int i=1;i<=k;++i)
			dep[i]=0,cur[i]=head[i];
		queue<int> qu;
		dep[s]=1;qu.push(s);
		while(!qu.empty())
		{
			int u=qu.front();
			qu.pop();
			for(int i=head[u];i;i=e[i].ne)
			{
				int v=e[i].v;
				if(!e[i].w||dep[v])
					continue;
				dep[v]=dep[u]+1;
				qu.push(v);
			}
		}
		return dep[t];
	}
	
	inline int dinic()
	{
		int res=0;
		while(bfs())
		{
			while(1)
			{
				int tmp=dfs(s,INF);
				res+=tmp;
				if(!tmp) break;
			}
		}
		return res;
	}
	
	int dfs(int u,int flow)
	{
		if(u==t) return flow;
		for(int &i=cur[u];i;i=e[i].ne)
		{
			int v=e[i].v;
			if(!e[i].w||dep[v]!=dep[u]+1)
				continue;
			int tmp=dfs(v,min(flow,e[i].w));
			if(tmp)
			{
				e[i].w-=tmp;
				e[fan(i)].w+=tmp;
				return tmp;
			}
		}
		return 0;
	}
	int w[_N][_N];
	inline void build()
	{
		s=++k;t=++k;
		for(int i=0;i<l.size();++i)
			idl[i]=++k;
		for(int i=0;i<r.size();++i)
			idr[i]=++k;
		for(int i=0;i<l.size();++i)
			add(s,idl[i],1);
		for(int i=0;i<r.size();++i)
			add(idr[i],t,1);
		for(int i=0;i<l.size();++i)
			for(int j=0;j<r.size();++j)
				if(2*l[i]+r[j]<=m&&l[i]%r[j]==0)
					add(idl[i],idr[j],1),w[i][j]=tot-1;
	}
	inline void solve()
	{
		dinic();
		for(int i=0;i<l.size();++i)
		{
			int ne=-1;
			for(int j=0;j<r.size();++j)
				if(w[i][j]&&e[w[i][j]].w==0)
					ne=j;
			if(ne==-1)
			{
				puts("-1");
				exit(0);
			}
			ans.push_back(mp(2*l[i]+r[ne],l[i]+r[ne]));
			tg[ne]=1;
		}
		for(int i=0;i<r.size();++i)
			if(!tg[i])
				ans.push_back(mp(3*r[i],2*r[i]));
	}
}din;

signed main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		if(3*a[i]<=m)
			r.push_back(a[i]);
		else l.push_back(a[i]);
	}
	din.build();
	din.solve();
	write(ans.size());puts("");
	for(int i=0;i<ans.size();++i)
		write(ans[i].fi),putchar(' '),write(ans[i].se),puts("");
	return 0;
}