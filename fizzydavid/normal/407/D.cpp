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
int n,m;
int a[411][411],tor[411][411];
int pre[300011],nxt[300000],head[300011];
int main()
{
	getii(n,m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			geti(a[i][j]);
		}
	}
	int ans=0;
	for(int r=1;r<=n;r++)
	{
		memset(pre,0,sizeof(pre));
		memset(nxt,0,sizeof(nxt));
		memset(tor,63,sizeof(tor));
		memset(head,0,sizeof(head));
		for(int j=1;j<=m;j++)
		{
			for(int i=r;i<=n;i++)
			{
				if((head[a[i][j]]&511)==j)
				{
					tor[i][j]=j-1;
				}
				else
				{
					int x=i<<9|j;
					if(head[a[i][j]])
					{
						nxt[head[a[i][j]]]=x;
						pre[x]=head[a[i][j]];
					}
					head[a[i][j]]=x;
				}
			}
		}
		for(int i=n;i>=r;i--)
		{
			for(int j=1;j<=m;j++)
			{
				int x=i<<9|j;
				if(pre[x])
				{
					tor[i][(pre[x]&511)]=min(tor[i][(pre[x]&511)],j-1);
					nxt[pre[x]]=nxt[x];
				}
				if(nxt[x])
				{
					tor[i][j]=min(tor[i][j],(nxt[x]&511)-1);
					pre[nxt[x]]=pre[x];
				}
			}
		}
		for(int i=r;i<=n;i++)
		{
			for(int j=m;j>=1;j--)
			{
				tor[i][j]=min(tor[i][j],min(tor[i-1][j],tor[i][j+1]));
				ans=max(ans,(min(m,tor[i][j])-j+1)*(i-r+1));
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}