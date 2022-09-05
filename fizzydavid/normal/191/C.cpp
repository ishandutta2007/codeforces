//by yjz
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
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
int n,q,head[200111],nxt[200111],to[200111],id[200111],tot,dis[200111];
int p[22][100111],sum[100111],ans[100111];
void dfs(int x)
{
	for(int i=head[x];i>0;i=nxt[i])
	{
		if(to[i]!=p[0][x])
		{
			p[0][to[i]]=x;
			dis[to[i]]=dis[x]+1;
			dfs(to[i]);
		}
	}
}
int getlca(int x,int y)
{
	if(dis[x]<dis[y])swap(x,y);
	for(int i=19;i>=0;i--)
		if(((dis[x]-dis[y])>>i)&1)
			x=p[i][x];
	if(x==y)return x;
	for(int i=19;i>=0;i--)
		if(p[i][x]!=p[i][y])
			x=p[i][x],y=p[i][y];
	return p[0][x];
}
void calc(int x)
{
	for(int i=head[x];i>0;i=nxt[i])
	{
		if(to[i]!=p[0][x])
		{
			calc(to[i]);
			sum[x]+=sum[to[i]];
			ans[id[i]]=sum[to[i]];
		}
	}
}
int main()
{
	geti(n);
	for(int i=1;i<n;i++)
	{
		int x,y;
		getii(x,y);
		nxt[++tot]=head[x];
		head[x]=tot;
		to[tot]=y;
		id[tot]=i;
		nxt[++tot]=head[y];
		head[y]=tot;
		to[tot]=x;
		id[tot]=i;
	}
	dis[1]=1;
	dfs(1);
	for(int i=1;i<20;i++)
		for(int j=1;j<=n;j++)
			p[i][j]=p[i-1][p[i-1][j]];
	geti(q);
	while(q--)
	{
		int x,y;
		getii(x,y);
		int pa=getlca(x,y);
		sum[x]++;
		sum[y]++;
		sum[pa]-=2;
	}
	calc(1);
	for(int i=1;i<n;i++)puti(ans[i]);
	return 0;
}