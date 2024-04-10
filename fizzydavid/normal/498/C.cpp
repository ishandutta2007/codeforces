//while(true)rp++;
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<deque>
#include<iostream>
#include<iomanip>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
//My own input/output stream
#define input1(x) x=getnum()
#define input2(x,y) input1(x),y=getnum()
#define input3(x,y,z) input2(x,y),z=getnum()
#define input4(x,y,z,w) input3(x,y,z),w=getnum()
#define output1(x) putnum(x)
#define output2(x,y) output1(x),putnum(y)
#define output3(x,y,z) output2(x,y),putnum(z)
#define output4(x,y,z,w) output3(x,y,z),putnum(w)
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

const int maxn=100000;
int n,m,a[111];
vector<int>p;
int fac[111][1011];
struct edge
{
	int to,cap,rev;
};
vector<edge>g[maxn];
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
	input2(n,m);
	for(int i=1;i<=n;i++)
		input1(a[i]);
	for(int i=1;i<=n;i++)
	{
		int t=a[i];
		for(int j=2;j*j<=t;j++)
		{
			if(t%j==0)
				p.PB(j);
			while(t%j==0)
				t/=j;
		}
		if(t>1)
			p.PB(t);
	}
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	int k=p.size();
	for(int i=1;i<=n;i++)
	{
		int t=a[i];
		for(int j=0;j<k;j++)
		{
			int cnt=0;
			while(t%p[j]==0)
				cnt++,t/=p[j];
			fac[i][j]=cnt;
		}
	}
	int pt=n*k,vs=2*n*k,vt=vs+1;
	for(int i=1;i<=n;i+=2)
		for(int j=0;j<k;j++)
			add_edge(vs,(i-1)*k+j,INF);
	for(int i=2;i<=n;i+=2)
		for(int j=0;j<k;j++)
			add_edge(pt+(i-1)*k+j,vt,INF);
	for(int i=1;i<=n;i++)
		for(int j=0;j<k;j++)
			if(fac[i][j]>0)
				add_edge((i-1)*k+j,pt+(i-1)*k+j,fac[i][j]);
	int x,y;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		if(y&1)
			swap(x,y);
		for(int j=0;j<k;j++)
			if(min(fac[x][j],fac[y][j])>0)
				add_edge(pt+(x-1)*k+j,(y-1)*k+j,INF);
	}
	cout<<maxflow(vs,vt);
	return 0;
}