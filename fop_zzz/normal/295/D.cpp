#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back


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
const int N=2005;
ll mo=1e9+7,n,m,dp[N][N],s[N][N],sum[N][N],ans;
int main()
{
	n=read();m=read();
	For(i,1,n)
		For(j,2,m)
		{
			dp[i][j]=(j+1)*sum[i-1][j]-s[i-1][j]+1;
			s[i][j]=s[i][j-1]+dp[i][j]*j%mo;sum[i][j]=sum[i][j-1]+dp[i][j];
			dp[i][j]=(dp[i][j]%mo+mo)%mo;s[i][j]%=mo;sum[i][j]%=mo;
		}
	For(i,1,n)	For(j,2,m)
	{
		ans=ans+(dp[i][j]*(dp[n-i+1][j]-dp[n-i][j]+mo)%mo*(m-j+1)%mo)%mo;
		ans%=mo;
	}
	writeln(ans);
}