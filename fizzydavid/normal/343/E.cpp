//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
typedef long long ll;
const int Imx=2147483647;
const int mod=1000000007;
const ll Lbig=2e18;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=getchar();
	if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
int head[211],nxt[2111],to[2111],cap[2111],tot=1;
void addedge(int x,int y,int c)
{
	nxt[++tot]=head[x];
	head[x]=tot;
	to[tot]=y;
	cap[tot]=c;
	nxt[++tot]=head[y];
	head[y]=tot;
	to[tot]=x;
	cap[tot]=c;
}
int dis[211],q[211],qn,it[211];
void bfs(int S)
{
	memset(dis,-1,sizeof(dis));
	dis[S]=0;
	qn=0;
	q[qn++]=S;
	for(int i=0;i<qn;i++)
	{
		int u=q[i];
		for(int j=head[u];j;j=nxt[j])
		{
			if(cap[j]&&dis[to[j]]==-1)
			{
				dis[to[j]]=dis[u]+1;
				q[qn++]=to[j];
			}
		}
	}
}
int dfs(int x,int T,int f)
{
	if(x==T)return f;
	int F=f;
	for(int &i=it[x];i;i=nxt[i])
	{
		if(dis[to[i]]==dis[x]+1&&cap[i])
		{
			int d=dfs(to[i],T,min(f,cap[i]));
			if(d)
			{
				cap[i]-=d;
				cap[i^1]+=d;
				f-=d;
				if(f==0)return F;
			}
		}
	}
	return F-f;
}
int maxflow(int S,int T)
{
	for(int i=2;i<=tot;i+=2)cap[i]=cap[i^1]=(cap[i]+cap[i^1])>>1;
	int ans=0;
	while(true)
	{
		bfs(S);
		if(dis[T]==-1)return ans;
		for(int i=0;i<205;i++)it[i]=head[i];
		int f;
		while(f=dfs(S,T,23333333))ans+=f;
	}
}
vector<pair<int,int> >con[211];
void solvegh(vector<int>&v)
{
//	cout<<"solvegh:"<<endl;
//	cout<<v.size()<<endl;
//	for(int i=0;i<v.size();i++)cout<<v[i]<<" ";cout<<endl;
	if(v.size()<2)return;
	int S=v[0],T=v[1];
	int w=maxflow(S,T);
	con[S].PB(MP(T,w));
	con[T].PB(MP(S,w));
//	cout<<"addedge:"<<S<<" "<<T<<" "<<w<<endl;
	vector<int>vs,vt;
	for(int i=0;i<v.size();i++)
	{
		if(dis[v[i]]==-1)vt.PB(v[i]);
		else vs.PB(v[i]);
	}
	solvegh(vs);
	solvegh(vt);
}
bool f[211];
pair<int,pair<int,int> > dfs(int x,int pre=-1)
{
	pair<int,pair<int,int> >ret=MP(mod,MP(0,0));
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i].FF;
		if(f[u]||u==pre)continue;
		ret=min(ret,MP(con[x][i].SS,MP(x,u)));
		ret=min(ret,dfs(u,x));
	}
	return ret;
}
int av[211],an,ans;
void solve(int x)
{
//	cout<<"solve:"<<x<<endl;
	pair<int,pair<int,int> > mx=dfs(x);
	int u=mx.SS.FF,v=mx.SS.SS;
//	cout<<u<<" "<<v<<" "<<mx.FF<<endl;
	if(u==0)
	{
		av[an++]=x;
		return;
	}
	f[v]=1;solve(u);f[v]=0;
	f[u]=1;solve(v);f[u]=0;
	ans+=mx.FF;
}
int n,m;
int main()
{
//	freopen("input","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		addedge(x,y,c);
	}
	vector<int>v;
	for(int i=1;i<=n;i++)v.PB(i);
	solvegh(v);
	solve(1);
	printf("%d\n",ans);
	for(int i=0;i<an;i++)printf("%d ",av[i]);
	return 0;
}