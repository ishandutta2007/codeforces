#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <cstring>
#include <ctime>
#include <vector>
#define ll long long
#define N 1020
#define lson x*2
#define rson x*2+1
#define For(i,j,k) for(int i=j;i<=k;i++)
#define Dow(i,j,k) for(int i=k;i>=j;i--)
#define clr(x, c) memset(x, c, sizeof(x))
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){write(x);puts("");};
int dp[201][7001][2],n,k,t[201],f[201],ans,mx;
ll x;
int main()
{
	n=read();k=read();
	For(i,1,n)
	{
		x=read();
		while(x%2LL==0&&x)	t[i]++,x/=2LL;
		while(x%5LL==0&&x)	f[i]++,x/=5LL;
		mx+=f[i];
	}
	int now=1;
	For(i,0,200)	For(j,0,7000)	dp[i][j][now^1]=-1e9;
	dp[0][0][0]=0;
	For(i,1,n)
	{
		For(j,0,n)
		{
			For(k,0,mx)
			{
				dp[j][k][now]=dp[j][k][now^1];
				if(k>=f[i]&&j>0)	dp[j][k][now]=max(dp[j][k][now],dp[j-1][k-f[i]][now^1]+t[i]);
			}
		}
		now^=1;
	}
	For(i,0,mx)	ans=max(ans,min(dp[k][i][now^1],i));
	writeln(ans);
}