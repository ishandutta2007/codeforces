//while(true)rp++;
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
int f[200111];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
int n,m;
bool vis[200111];
bool gr[200111];
vector<int>v1,v2;
int main()
{
	getii(n,m);
	for(int i=1;i<=2*n;i++)f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		getii(x,y);
		f[gf(x+n)]=gf(y);
		f[gf(y+n)]=gf(x);
	}
	bool ok=1;
	for(int i=1;i<=n;i++)ok&=(gf(i)!=gf(i+n));
	if(!ok)puts("-1");
	else
	{
		for(int i=1;i<=n;i++)
		{
			int t=gf(i),rt=gf(i+n);
			if(!vis[t]&&!vis[rt])
			{
				vis[t]=vis[rt]=1;
				gr[t]=1;
			}
		}
		for(int i=1;i<=n;i++)if(gr[gf(i)])v1.PB(i);else v2.PB(i);
		putsi(v1.size());
		for(int i=0;i<v1.size();i++)puti(v1[i]);puts("");
		putsi(v2.size());
		for(int i=0;i<v2.size();i++)puti(v2[i]);
	}
	return 0;
}