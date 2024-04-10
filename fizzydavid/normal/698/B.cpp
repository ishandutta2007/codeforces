//by yjz
#include<bits/stdc++.h>
using namespace std;
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
int n;
int head[200111],nxt[400111],to[400111],tot=1;
bool vis[200111];
int p[200111];
int X,Y;
void dfs(int x,int pre)
{
	vis[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		if(!vis[to[i]])
		{
			dfs(to[i],i/2);
		}
		else if(i/2!=pre)
		{
			X=x;
			Y=to[i];
		}
	}
}
int main()
{
	geti(n);
	int ans=0,fb=0;
	for(int i=1;i<=n;i++)
	{
		geti(p[i]);
		nxt[++tot]=head[i];
		head[i]=tot;
		to[tot]=p[i];
		nxt[++tot]=head[p[i]];
		head[p[i]]=tot;
		to[tot]=i;
		if(i==p[i])fb=i;
	}
	if(fb)dfs(fb,-1);
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			X=Y=-1;
			dfs(i,-1);
			if(p[Y]==X)swap(X,Y);
			if(!fb)
			{
				ans++;
				p[X]=X,fb=X;
			}
			else
			{
				ans++;
				p[X]=fb;
			}
		}
	}
	putsi(ans);
	for(int i=1;i<=n;i++)puti(p[i]);
	return 0;
}