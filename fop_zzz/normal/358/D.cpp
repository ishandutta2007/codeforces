#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<queue>
#define For(i,j,k)  for(int i=j;i<=k;++i)
#define Dow(i,j,k)  for(int i=k;i>=j;--i)
#define ll long long
#define inf 1e9
#define pb push_back
#define c(x,y)  ((x-1))*m+(y)
using namespace std;
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read()
{
	int t=0,f=1;char c=gc();
	while(!isdigit(c))  {if(c=='-') f=-1;c=gc();}
	while(isdigit(c))   t=t*10+c-'0',c=gc();
	return t*f;
}
inline void write(int x){if(x<0) {putchar('-');write(-x);return;}if(x>=10)    write(x/10);putchar(x%10+'0');}
inline void writeln(int x){write(x);puts("");}
inline void write_p(int x){write(x);putchar(' ');}
int dp[5001][2][2],v[5001][4],n;
int main()
{
	n=read();
	For(i,1,n)	v[i][0]=read();
	For(i,1,n)	v[i][1]=read();
	For(i,1,n)	v[i][2]=read();
	For(i,1,n)	For(j,0,2)	For(k,0,1)	dp[i][j][k]=-inf;
	dp[0][0][0]=0;
	For(i,1,n)
	{
		if(i!=n)	dp[i][0][1]=max(dp[i-1][0][1],dp[i-1][1][1])+v[i][1];
		dp[i][0][0]=max(dp[i-1][0][1],dp[i-1][1][1])+v[i][0];
		if(i!=1)	dp[i][1][0]=max(dp[i-1][0][0],dp[i-1][1][0])+v[i][1];
		if(i!=1&&i!=n)	dp[i][1][1]=max(dp[i-1][0][0],dp[i-1][1][0])+v[i][2];
	}
	int ans=0;
	For(i,0,1)	For(j,0,1)	ans=max(ans,dp[n][i][j]);
	writeln(ans);
}