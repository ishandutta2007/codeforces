//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x)
#define putii(x,y) puti(x),putnum(y)
#define putiii(x,y,z) putii(x,y),putnum(z)
#define putsi(x) puti(x),putendl()
#define putsii(x,y) putii(x,y),putendl()
#define putsiii(x,y,z) putiii(x,y,z),putendl()
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c!=' '&&c!='\n')r=r*10+c-'0',c=getchar();
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
int n,m,a[111],b[111],suma,sumb,ans[111][111];
struct edge
{
	int to,cap,rev;
};
const int maxn=211;
vector<edge>con[maxn];
int dis[maxn],que[maxn],it[maxn];
edge make_edge(int to,int cap,int rev)
{
	edge tmp;
	tmp.to=to;
	tmp.cap=cap;
	tmp.rev=rev;
	return tmp;
}
void add_edge(int x,int y,int c)
{
	con[x].PB(make_edge(y,c,con[y].size()));
	con[y].PB(make_edge(x,0,con[x].size()-1));
}
void bfs(int s)
{
	memset(dis,-1,sizeof(dis));
	dis[s]=0;
	int head=0,tail=0;
	que[tail++]=s;
	while(head<tail)
	{
		int x=que[head++];
		for(int i=0;i<con[x].size();i++)
			if(con[x][i].cap>0&&dis[con[x][i].to]==-1)
				dis[con[x][i].to]=dis[x]+1,que[tail++]=con[x][i].to;
	}
}
int dfs(int x,int t,int f)
{
	if(x==t)
		return f;
	for(int &i=it[x];i<con[x].size();i++)
	{
		edge &e=con[x][i];
		if(dis[x]<dis[e.to]&&e.cap>0)
		{
			int d=dfs(e.to,t,min(e.cap,f));
			if(d>0)
			{
				e.cap-=d;
				con[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
int maxflow(int s,int t)
{
	int flow=0;
	while(true)
	{
		bfs(s);
		if(dis[t]<0)break;
		memset(it,0,sizeof(it));
		int f;
		while((f = dfs(s,t,INF)) > 0)
			flow+=f;
	}
	return flow;
}
int main()
{
	getii(n,m);
	for(int i=1;i<=n;i++)geti(a[i]),suma+=a[i];
	for(int i=1;i<=n;i++)geti(b[i]),sumb+=b[i];
	if(suma!=sumb)
	{
		puts("NO");
		return 0;
	}
	for(int i=1;i<=n;i++)add_edge(0,i,a[i]),add_edge(i,n+i,INF),add_edge(i+n,n*2+1,b[i]);
	int x,y;
	for(int i=1;i<=m;i++)
	{
		getii(x,y);
		add_edge(x,n+y,INF);
		add_edge(y,n+x,INF);
	}
	int sum=maxflow(0,n*2+1);
	if(sum!=sumb)
	{
		puts("NO");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<con[i].size();j++)
		{
			if(con[i][j].to>n)
			{
				ans[i][con[i][j].to-n]=INF-con[i][j].cap;
			}
		}
	}
	puts("YES");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			puti(ans[i][j]);putsp();
		}
		putendl();
	}
	return 0;
}