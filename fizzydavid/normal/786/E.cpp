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
const ll Lbg=2e18;
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
int head[400111],nxt[3000111],to[3000111],cap[3000111],tot=1;
int dis[400111],q[400111],qsz;
void bfs(int S)
{
	memset(dis,-1,sizeof(dis));
	dis[S]=0;
	qsz=0;
	q[qsz++]=S;
	for(int i=0;i<qsz;i++)
	{
		int u=q[i];
		for(int j=head[u];j;j=nxt[j])
		{
			if(dis[to[j]]==-1&&cap[j])
			{
				q[qsz++]=to[j];
				dis[to[j]]=dis[u]+1;
			}
		}
	}
}
int it[400111];
int dfs(int x,int T,int f)
{
	if(x==T)return f;
	for(int &i=it[x];i;i=nxt[i])
	{
		if(dis[to[i]]==dis[x]+1&&cap[i])
		{
			int d=dfs(to[i],T,min(cap[i],f));
			if(d)
			{
				cap[i]-=d;
				cap[i^1]+=d;
//				cout<<"route:"<<d<<" "<<x<<endl;
				return d;
			}
		}
	}
	return 0;
}
int maxflow(int S,int T,int tn)
{
	int ans=0;
	while(true)
	{
//		cout<<"maxflow:"<<S<<" "<<T<<" "<<tn<<" "<<ans<<endl;
		bfs(S);
		if(dis[T]==-1)return ans;
		for(int i=0;i<=tn;i++)it[i]=head[i];
		int f;
		while(f=dfs(S,T,23333333))ans+=f;
	}
}
int n,m;
void addedge(int x,int y,int c)
{
//	cout<<"add:"<<x<<"-"<<y<<" "<<c<<endl;
	nxt[++tot]=head[x];
	head[x]=tot;
	to[tot]=y;
	cap[tot]=c;
	nxt[++tot]=head[y];
	head[y]=tot;
	to[tot]=x;
	cap[tot]=0;
}
int p[16][20011],pid[20011],a[16][20011],an,lv[20011];
vector<pair<int,int> >con[20011];
void dfs(int x)
{
	for(auto i:con[x])
	{
		int u=i.FF;
		if(u==p[0][x])continue;
		pid[u]=i.SS;
		p[0][u]=x;
		lv[u]=lv[x]+1;
		dfs(u);
	}
}
int getlca(int x,int y)
{
	if(lv[x]>lv[y])swap(x,y);
	for(int i=15;i>=0;i--)
		if(lv[y]-(1<<i)>=lv[x])
			y=p[i][y];
	if(x==y)return x;
	for(int i=15;i>=0;i--)
		if(p[i][x]!=p[i][y])
			x=p[i][x],y=p[i][y];
	return p[0][x];
}
int main()
{
	getii(n,m);
	for(int i=1;i<n;i++)
	{
		int x,y;
		getii(x,y);
		con[x].PB(MP(y,i));
		con[y].PB(MP(x,i));
	}
	lv[1]=1;
	dfs(1);
	for(int i=1;i<16;i++)for(int j=1;j<=n;j++)p[i][j]=p[i-1][p[i-1][j]];
	int S=0,T=1;
	for(int i=2;i<=n;i++)
	{
		a[0][i]=i;
		addedge(S,i,1);
		addedge(i,T,0);
	}
	an=n;
	for(int i=1;i<16;i++)for(int j=1;j<=n;j++)
	{
		if(p[i][j])
		{
			a[i][j]=++an;
			addedge(a[i-1][j],an,n+1);
			addedge(a[i-1][p[i-1][j]],an,n+1);
		}
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		getii(x,y);
		int t=getlca(x,y);
		for(int j=15;j>=0;j--)
		{
			if(lv[x]-(1<<j)>=lv[t])
			{
				addedge(a[j][x],an+i,n+1);
				x=p[j][x];
			}
		}
		for(int j=15;j>=0;j--)
		{
			if(lv[y]-(1<<j)>=lv[t])
			{
				addedge(a[j][y],an+i,n+1);
				y=p[j][y];
			}
		}
		addedge(an+i,T,1);
	}
	int ans=maxflow(S,T,an+m);
	putsi(ans);
	vector<int>v1,v2;
	for(int i=1;i<=m;i++)if(dis[an+i]!=-1)v1.PB(i);
	for(int i=2;i<=n;i++)if(dis[i]==-1)v2.PB(pid[i]);
	puti(v1.size());for(int i:v1)puti(i);puts("");
	puti(v2.size());for(int i:v2)puti(i);
	return 0;
}