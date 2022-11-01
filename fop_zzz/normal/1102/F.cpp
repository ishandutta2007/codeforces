#include<bits/stdc++.h>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back
#define y1 jjbesssws

using namespace std;

inline ll read()
{
    ll t=0,dp=1;char c=getchar();
    while(!isdigit(c))	{if(c=='-')	dp=-1;c=getchar();}
    while(isdigit(c))	t=t*10+c-48,c=getchar();
    return t*dp;
}
inline void write(ll x){if(x<0)	{putchar('-');x=-x;}	if(x>=10)	write(x/10);putchar(x%10+48);}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}

int n,m,a[17][10001];
int nxt[17][17],tr[17][17];
int dp[17][17][(1<<17)];
int main()
{
	n=read();m=read();
	For(i,1,n)	For(j,1,m)	a[i][j]=read();
	if(n==1)
	{
		int mx=1e9;
		For(j,1,m-1)	mx=min(mx,abs(a[1][j]-a[1][j+1]));
		writeln(mx);
		return 0;
	}
	For(i,1,n)	For(j,1,n)
	{
		if(i==j)	continue;
		int mx=1e9;
		For(k,1,m)	mx=min(mx,abs(a[i][k]-a[j][k]));
		tr[i][j]=mx;//i hou jie j
		mx=1e9;
		For(k,1,m-1)	mx=min(mx,abs(a[i][k]-a[j][k+1]));
		nxt[i][j]=mx;//i jie wei   j kai tou		
	}
	int mx=(1<<n)-1;
	memset(dp,-1,sizeof dp);
	For(i,1,n)	dp[i][i][1<<(i-1)]=1e9;
	For(i,1,n)
	{
		For(j,1,mx)
		{
			For(las,1,n)	if(dp[i][las][j]==-1)	continue;
			else
			For(k,1,n)	if((j>>(k-1)&1)==0)
			{
				int nzt=(j|(1<<(k-1)));
				dp[i][k][nzt]=max(dp[i][k][nzt],min(dp[i][las][j],tr[las][k]));
				if(nzt==mx)	dp[i][k][nzt]=min(dp[i][k][nzt],nxt[k][i]);
			}
		}
	}
	int ans=0;
	For(i,1,n)	For(j,1,n)	ans=max(ans,dp[i][j][mx]);
	writeln(ans); 
}