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
int head[111],nxt[1011],to[1011],cap[1011],tot=1,it[1011],q[1011],qsz,dis[1011];
void addedge(int x,int y,int c)
{
//	cout<<"addedge:"<<x<<" "<<y<<" "<<c<<endl;
	nxt[++tot]=head[x];
	head[x]=tot;
	to[tot]=y;
	cap[tot]=c;
	nxt[++tot]=head[y];
	head[y]=tot;
	to[tot]=x;
	cap[tot]=0;
}
void bfs(int S)
{
	qsz=0;
	memset(dis,-1,sizeof(dis));
	dis[S]=0;
	q[qsz++]=S;
	for(int i=0;i<qsz;i++)
	{
		int u=q[i];
		for(int j=head[u];j;j=nxt[j])
		{
			if(cap[j]&&dis[to[j]]==-1)
			{
				dis[to[j]]=dis[u]+1;
				q[qsz++]=to[j];
			}
		}
	}
}
int dfs(int x,int T,int f)
{
	if(x==T)return f;
	for(int &i=it[x];i;i=nxt[i])
	{
		if(dis[to[i]]==dis[x]+1&&cap[i])
		{
			int d=dfs(to[i],T,min(f,cap[i]));
			if(d)
			{
				cap[i]-=d;
				cap[i^1]+=d;
				return d;
			}
		}
	}
	return 0;
}
int maxflow(int S,int T)
{
	int ans=0;
	while(true)
	{
		bfs(S);
		if(dis[T]==-1)return ans;
		for(int i=0;i<111;i++)it[i]=head[i];
		int f=0;
		while(f=dfs(S,T,23333333))ans+=f;
	}
}
int n,m,cnt[10],a[10][10],b[10][10];
pair<int,int> cmd[200111];
int vis;
pair<int,int> ve[10];
int vsz;
vector<pair<int,int> > v[10][10];
const int bs[7]={1,10,100,1000,10000,100000,1000000};
int vid[7];
void solve()
{
	for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)b[i][j]=a[i][j];
	for(int i=0;i<vsz;i++)
	{
		int x=ve[i].FF,y=ve[i].SS;
		if(x>y)swap(x,y);
//		cout<<x<<"-"<<y<<endl;
		b[x][y]--;
	}
	for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)if(b[i][j]<0)return;
	tot=1;
	memset(head,0,sizeof(head));
	int S=59,T=60;
	for(int i=1;i<=m;i++)
	{
		addedge(S,i,cnt[i]-1);
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=i;j<=m;j++)
		{
			if(!b[i][j])continue;
			addedge(i,i*m+j,mod);
			addedge(j,i*m+j,mod);
			addedge(i*m+j,T,b[i][j]);
		}
	}
	int flow=maxflow(S,T);
//	cout<<"flow="<<flow<<endl;
	if(flow+m==n)
	{
		for(int i=0;i<vsz;i++)
		{
			int x=ve[i].FF,y=ve[i].SS;
			if(x>=y)swap(x,y);
			v[x][y].PB(MP(bs[x-1],bs[y-1]));
		}
		int id[7];
		for(int i=1;i<=m;i++)id[i]=bs[i-1];
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				int w=0;
				for(int k=head[i];k;k=nxt[k])
				{
					if(to[k]==min(i,j)*m+max(i,j))
					{
						w=cap[k^1];
						break;
					}
				}
//				cout<<i<<" "<<j<<" "<<w<<endl;
				while(w--)
				{
					if(i<j)v[i][j].PB(MP(++id[i],bs[j-1]));
					else v[j][i].PB(MP(bs[j-1],++id[i]));
				}
			}
		}
/*		for(int i=1;i<=m;i++)
		{
			for(int j=i;j<=m;j++)
			{
				cout<<v[i][j].size()<<" ";
			}cout<<endl;
		}*/
		for(int i=1;i<n;i++)
		{
			int x=cmd[i].FF,y=cmd[i].SS;
			if(x>y)
			{
				swap(x,y);
				int sz=v[x][y].size();
				assert(sz>0);
				pair<int,int> pp=v[x][y][sz-1];
				v[x][y].resize(sz-1);
				putsii(pp.SS,pp.FF);
			}
			else
			{
				int sz=v[x][y].size();
				assert(sz>0);
				pair<int,int> pp=v[x][y][sz-1];
				v[x][y].resize(sz-1);
				putsii(pp.FF,pp.SS);
			}
		}
		exit(0);
	}
}
void dfs(int x)
{
//	cout<<"dfs:"<<x<<" "<<vis<<endl;
	if(vis+1==(1<<m))
	{
		solve();
		return;
	}
	for(int i=0;i<(1<<m);i++)
	{
		if((i&vis)==0)
		{
			for(int j=0;j<m;j++)
			{
				if((i>>j)&1)
				{
					vis|=1<<j;
					ve[vsz++]=MP(x,j+1);
				}
			}
			for(int j=0;j<m;j++)
			{
				if((i>>j)&1)
				{
					dfs(j+1);
				}
			}
			for(int j=0;j<m;j++)
			{
				if((i>>j)&1)
				{
					vis&=~(1<<j);
					vsz--;
				}
			}
		}
	}
}
int main()
{
	geti(n);
	for(int i=1;i<n;i++)
	{
		char s[10];
		int x,y;
		scanf("%s",s);x=strlen(s);
		scanf("%s",s);y=strlen(s);
		cmd[i]=MP(x,y);
		if(x>=y)swap(x,y);
		a[x][y]++;
	}
	for(int i=1;i<=6;i++)
	{
		cnt[i]=max(0,min(n,bs[i]-1)-bs[i-1]+1);
		if(cnt[i])m++;
	}
	vis=1;
	dfs(1);
	puts("-1");
	return 0;
}