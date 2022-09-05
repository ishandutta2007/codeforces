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
int n,a[55][55],ans[55];
bool vis[55][55];
bool used[55];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		vis[i][i]=1;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(used[i])continue;
			bool ok=1;
			for(int j=1;j<=n;j++)
			{
				if(!vis[i][j]&&a[i][j]!=k)ok=0;
			}
			for(int j=1;j<=n;j++)
			{
				if(!vis[j][i]&&a[j][i]!=k)ok=0;
			}
			if(ok)
			{
				for(int j=1;j<=n;j++)vis[i][j]=vis[j][i]=1;
				used[i]=1;
				ans[i]=k;break;
			}
		}
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	return 0;
}