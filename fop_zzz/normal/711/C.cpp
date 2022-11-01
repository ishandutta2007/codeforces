#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back
#define int ll

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
/*------------------------------------------------------------------------------------------------------*/
const int N=105;
int n,m,k,v[N][N],dp[N][N][N],c[N];
inline void Upd(int &x,int y){x=min(x,y);}
signed main()
{
	n=read();
	m=read();k=read();
	For(i,1,n)	c[i]=read();
	For(i,1,n)	For(j,1,m)	v[i][j]=read();
	memset(dp,0x3f,sizeof dp);
	dp[0][0][0]=0;//i  j t
	For(i,0,n-1)
		For(j,0,k)
			For(t,0,m)
			{
				if(c[i+1])
					Upd(dp[i+1][j+(c[i+1]!=t)][c[i+1]],dp[i][j][t]);
				else
				{
					For(p,1,m)
						Upd(dp[i+1][j+(p!=t)][p],dp[i][j][t]+v[i+1][p]);
				}
			}
			
	ll ans=1e17;
	For(t,1,m)	ans=min(ans,dp[n][k][t]);
	if(ans==1e17)	puts("-1");else	writeln(ans);
}