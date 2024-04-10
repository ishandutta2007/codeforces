#include<bits/stdc++.h>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
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
int dp[1101][16][16][16],v[5],zt[1101],n;
char s[1101];
inline int Dfs(int x,int t1,int t2,int t3)
{
	if(dp[x][t1][t2][t3]!=-1)	return dp[x][t1][t2][t3];
	if(x>=n+2&&t1==0&&t2==0&&t3==0)	return 0;
	if(t1==0)	return Dfs(x+1,t2,t3,zt[x+3]);
	int tmp=0;
	dp[x][t1][t2][t3]=2e9; 
	tmp = v[4]+Dfs(x+4,zt[x+4],zt[x+5],zt[x+6]);
    tmp=min(tmp,v[3]+Dfs(x,t1&8 ,t2&8 ,t3&8));
    tmp=min(tmp,v[3]+Dfs(x,t1&1 ,t2&1 ,t3&1));
    tmp=min(tmp,v[2]+Dfs(x,t1&12,t2&12,t3));
    tmp=min(tmp,v[2]+Dfs(x,t1&9 ,t2&9 ,t3));
    tmp=min(tmp,v[2]+Dfs(x,t1&3 ,t2&3 ,t3));
    tmp=min(tmp,v[1]+Dfs(x,t1&14,t2,t3));
    tmp=min(tmp,v[1]+Dfs(x,t1&13,t2,t3));
    tmp=min(tmp,v[1]+Dfs(x,t1&11,t2,t3));
    tmp=min(tmp,v[1]+Dfs(x,t1&7 ,t2,t3));
    return dp[x][t1][t2][t3]=tmp;
}
int main()
{
	n=read();	
	memset(dp,-1,sizeof dp);
	For(i,1,4)	v[i]=read();
	For(i,1,4)	
	{
		scanf("\n%s",s+1);
		For(j,1,n)	if(s[j]=='*')	zt[j]+=(1<<i-1);
	}
	cout<<Dfs(1,zt[1],zt[2],zt[3])<<endl;
}