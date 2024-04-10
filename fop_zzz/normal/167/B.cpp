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

int n,l,bag,v[205],tmp=300;
double may[205],dp[2][205][605];
int main()
{
	n=read();l=read();bag=read();
	For(i,1,n)		
		may[i]=1.0*read()/100;
	For(i,1,n)	v[i]=read();
	dp[0][0][min(n,bag)+tmp]=1;
	int now=0;
	For(i,1,n)
	{
		For(j,0,n)
			For(k,0,tmp+n)
			{
				dp[now^1][j][k]+=dp[now][j][k]*(1.0-may[i]);
				if(k!=0||v[i]!=-1)	dp[now^1][j+1][min(n+tmp,k+v[i])]+=dp[now][j][k]*may[i];
			}
		now^=1;
		For(j,0,n)	For(k,0,tmp+n)	dp[now^1][j][k]=0;
	}
	double ans=0;
	For(i,l,n)	For(k,tmp,tmp+n)ans+=dp[now][i][k];
	printf("%.20lf",ans);	
}