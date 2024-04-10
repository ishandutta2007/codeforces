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
int n;
vector<int>con[200111];
int tx[100111],ty[100111];
int c[200111];
void dfs(int x,int t=2)
{
	c[x]=t;
	for(int i=0;i<con[x].size();i++)
	{
		if(c[con[x][i]]==0)
		{
			dfs(con[x][i],t^1);
		}
	}
}
int main()
{
	scanf("%d",&n);
	n*=2;
	for(int i=1;i<=n/2;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		tx[i]=x;ty[i]=y;
		con[x].PB(y);
		con[y].PB(x);
	}
	for(int i=1;i<=n;i+=2)con[i].PB(i+1),con[i+1].PB(i);
	for(int i=1;i<=n;i++)if(c[i]==0)dfs(i);
	for(int i=1;i<=n/2;i++)printf("%d %d\n",c[tx[i]]-1,c[ty[i]]-1);
	return 0;
}