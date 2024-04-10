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
int head[111],nxt[10011],to[10011],cap[10011],tot=1;
void addedge(int x,int y,int c)
{
//	cout<<"addedge:"<<x<<"-"<<y<<" "<<c<<endl;
	nxt[++tot]=head[x];
	head[x]=tot;
	to[tot]=y;
	cap[tot]=c;
	nxt[++tot]=head[y];
	head[y]=tot;
	to[tot]=x;
	cap[tot]=0;
}
int dis[10011];
int q[10011],qn;
void bfs(int S)
{
	memset(dis,-1,sizeof(dis));
	qn=0;
	q[qn++]=S;
	dis[S]=0;
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
int it[10011];
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
		int f;
		while(f=dfs(S,T,mod))ans+=f;
	}
}
int n,P;
pair<int,pair<int,int> > a[111];
bool np[200111];
int main()
{
	np[1]=1;
	for(int i=2;i<=200005;i++)
	{
		if(!np[i])
		{
			for(int j=i+i;j<=200005;j+=i)np[j]=1;
		}
	}
	getii(n,P);
	for(int i=1;i<=n;i++)getiii(a[i].SS.SS,a[i].SS.FF,a[i].FF);
	sort(a+1,a+n+1);
	int mx1=0,sum=0,cut=0;
	int t1=n+1,S=n+2,T=n+3;
	for(int i=1;i<=n;i++)
	{
		int c=a[i].SS.FF,p=a[i].SS.SS;
		if(c==1)
		{
			if(p>mx1)
			{
				addedge(S,t1,p-mx1);
				sum+=p-mx1;
				mx1=p;
			}
		}
		else
		{
			sum+=p;
			if(c&1)addedge(S,i,p);else addedge(i,T,p);
		}
		if(c!=1&&!np[c+1])addedge(t1,i,mod);
		for(int j=1;j<i;j++)
		{
			if(a[j].SS.FF>1&&!np[c+a[j].SS.FF])
			{
				if(c&1)addedge(i,j,mod);
				else addedge(j,i,mod);
			}
		}
		cut+=maxflow(S,T);
//		cout<<"sum="<<sum<<" cut="<<cut<<endl;
		if(sum-cut>=P)
		{
			putsi(a[i].FF);
			return 0;
		}
	}
	puts("-1");
	return 0;
}