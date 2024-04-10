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
const int N=14,M=(1<<14)-1;
ll dp[N][M],a[201],b[201],c[201],in[N][M],lin[N][N],n,q,m,mx;

inline ll Dfs(int x,int zt)
{
	if(dp[x][zt]!=-1)	return dp[x][zt];
	int tp=0,tmp=0;
	dp[x][zt]=0;
	int tzt=zt;
	zt^=(1<<x-1);
	For(i,1,n)	if(in[i][zt])	tp=i;
	for(int nzt=zt;nzt;nzt=(nzt-1)&zt)	if(in[tp][nzt])
	{
		bool flag=0;
		For(i,1,n)	For(j,i+1,n)	if(i!=x&&j!=x&&lin[i][j])	if(in[i][nzt]^in[j][nzt])	flag=1;
		if(flag)	continue;
		int nrt=0;
		For(i,1,n)	if(in[i][nzt])if(lin[x][i])
		{
			if(nrt)	flag=1;else	nrt=i;
		}
		if(flag)	continue;
//		For(i,1,q)	
//		{
//			if(in[a[i]][zt]&&in[b[i]][zt])
//				if(in[a[i]][nzt]^in[b[i]][nzt])	if(x!=c[i])	flag=1;
//		}
 		For(i,1,q)
		{
            if(c[i]==x&&in[a[i]][nzt] && in[b[i]][nzt]) {
                flag = 1; break;
            }
            if(in[c[i]][nzt] && ((!in[a[i]][nzt])||(!in[b[i]][nzt]))) {
                flag = 1; break;
            }
        }
		if(flag)	continue;
		if(nrt)	dp[x][tzt]+=Dfs(nrt,nzt)*Dfs(x,tzt^nzt);
		else	
		For(nrt,1,n)	if(in[nrt][nzt])	
		{
			dp[x][tzt]+=Dfs(nrt,nzt)*Dfs(x,tzt^nzt);
		}
	}
	return dp[x][tzt];
}
int main()
{
	n=read();m=read();q=read();
	mx=(1<<n)-1;
	For(i,1,n)	For(zt,0,mx)	dp[i][zt]=-1;
	For(i,1,n)	For(zt,0,mx)	in[i][zt]=(zt>>(i-1))&1;
	For(i,1,n)	dp[i][1<<i-1]=1;
	For(i,1,m)	
	{
		int x=read(),y=read();
		lin[x][y]=lin[y][x]=1;
	}
	For(i,1,q)
	{
		a[i]=read();b[i]=read();c[i]=read();
	}
	writeln(Dfs(1,mx));
}