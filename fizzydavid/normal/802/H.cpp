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
bool dp[21][1000111],f[1000111];
int pre[21][1000111];
char c[55];
int tn;
void dfs(int x,int y)
{
//	cout<<"dfs:"<<x<<" "<<y<<endl;
	if(x==0)
	{
		for(int i=0;i<tn;i++)cout<<c[i];
		return;
	}
	int times=(y-1)/pre[x][y];
	dfs(x-1,pre[x][y]);
	while(times--)cout<<c[x-1];
}
int main()
{
	for(int i=0;i<26;i++)c[i]='a'+i;
	for(int i=26;i<52;i++)c[i]='A'+i-26;
	dp[1][1]=1;pre[1][1]=1;
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=1000000;j++)
		{
			if(!dp[i][j])continue;
			for(int k=0,cnt=0;k<=1000000&&cnt<15;k+=j,cnt++)
			{
				dp[i+1][k+1]=1;
				pre[i+1][k+1]=j;
			}
		}
	}
	for(int j=1;j<=1000000;j++)
	{
		for(int i=1;i<=11;i++)f[j]|=dp[i][j];
		if(!f[j])cout<<j<<endl;
	}
	int n;
	geti(n);
	for(int i=1;i<=10;i++)
	{
		if(dp[i][n])
		{
			tn=i;
			dfs(i,n);
			cout<<" ";
			for(int j=0;j<i;j++)cout<<c[j];
			return 0;
		}
	}
	return 0;
}