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
int n,a[4011];
int dp1[100][2222][200];
bool vis1[100][2222][200];
int dp2[100][2222][200];
bool vis2[100][2222][200];
int dfs2(int x,int y,int k);
int dfs1(int x,int y,int k)
{
	if(vis1[k][x][y-x+100])return dp1[k][x][y-x+100];
	vis1[k][x][y-x+100]=1;
	int &v=dp1[k][x][y-x+100];
	if(x+y+k+1<=n)
	{
		v=max(dfs2(x+k,y,k),dfs2(x+k+1,y,k+1));
	}
	else if(x+y+k<=n)
	{
		v=dfs2(x+k,y,k);
	}
	else v=a[x]+a[n-y];
	return v;
}
int dfs2(int x,int y,int k)
{
	if(vis2[k][x][y-x+100])return dp2[k][x][y-x+100];
	vis2[k][x][y-x+100]=1;
	int &v=dp2[k][x][y-x+100];
	if(x+y+k+1<=n)
	{
		v=min(dfs1(x,y+k,k),dfs1(x,y+k+1,k+1));
	}
	else if(x+y+k<=n)
	{
		v=dfs1(x,y+k,k);
	}
	else v=a[x]+a[n-y];
	return v;
}
int main()
{
	geti(n);
//	n=4000;
	for(int i=1;i<=n;i++)
	{
		geti(a[i]);
//		a[i]=1;
		a[i]+=a[i-1];
	}
	cout<<dfs1(0,0,1)-a[n]<<endl;
	return 0;
}