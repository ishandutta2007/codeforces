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

const ll mod=1e9+7;
int n,m,f[100111];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
vector<pair<int,int> >edges;
vector<int>con[100111];
int c[100111];
int dfs(int x,int col)
{
	if(c[x]>0&&c[x]!=col)return true;
	if(c[x]==col)return false;
	c[x]=col;
	for(int i=0;i<con[x].size();i++)
	{
		if(dfs(con[x][i],col^1))return true;
	}
	return false;
}
int main()
{
	getii(n,m);
	for(int i=1;i<=n;i++)f[i]=i;
	int x,y,e;
	for(int i=1;i<=m;i++)
	{
		getiii(x,y,e);
		if(e==1)
		{
			f[gf(x)]=f[gf(y)];
		}
		else
		{
			edges.PB(MP(x,y));
		}
	}
	for(int i=0;i<edges.size();i++)
	{
		x=edges[i].FF;y=edges[i].SS;
		con[gf(x)].PB(gf(y));
		con[gf(y)].PB(gf(x));
	}
	ll ans=1;bool f=0;
	for(int i=1;i<=n;i++)
	{
		if(c[gf(i)]==0)
		{
			if(dfs(gf(i),2))ans=0;
			else
			{
				if(f)ans=ans*2%mod;else f=1;
			}
		}
	}
	putsi(ans);
	return 0;
}