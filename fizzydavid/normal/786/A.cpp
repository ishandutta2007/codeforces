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
int n,m;
vector<int>v[2];
int dp[2][7011],cnt[2][7011];
void dfs(int x,int id,int f)
{
	if(dp[id][x]!=0||x==0)return;
	dp[id][x]=f;
	if(f==-1)
	{
		for(int i:v[id^1])
		{
			dfs((x-i+n)%n,id^1,1);
		}
	}
	else
	{
		for(int i:v[id^1])
		{
			int u=(x-i+n)%n;
			if((++cnt[id^1][u])==v[id^1].size())dfs(u,id^1,-1);
		}
	}
}
int main()
{
	geti(n);
	geti(m);
	for(int i=1;i<=m;i++)
	{
		int x;
		geti(x);
		v[0].PB(x);
	}
	geti(m);
	for(int i=1;i<=m;i++)
	{
		int x;
		geti(x);
		v[1].PB(x);
	}
	for(int i:v[0])
	{
		dfs((n-i)%n,0,1);
	}
	for(int i:v[1])
	{
		dfs((n-i)%n,1,1);
	}
	for(int i=1;i<n;i++)
	{
		if(dp[0][i]==1)printf("Win ");
		if(dp[0][i]==-1)printf("Lose ");
		if(dp[0][i]==0)printf("Loop ");
	}puts("");
	for(int i=1;i<n;i++)
	{
		if(dp[1][i]==1)printf("Win ");
		if(dp[1][i]==-1)printf("Lose ");
		if(dp[1][i]==0)printf("Loop ");
	}puts("");
	
	return 0;
}