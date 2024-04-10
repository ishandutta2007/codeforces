#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<map>
#include<cstring>
#include<ctime>
#include<algorithm>
#define For(i,j,k)  for(register int i=j;i<=k;++i)
#define Dow(i,j,k)  for(register int i=k;i>=j;--i)
#define ll long long
#define mk make_pair
#define pb push_back
#define eps 1e-8
#define pa pair<int,int>
#define fir first
#define sec second
using namespace std;
inline ll read()
{
    ll t=0,f=1;char c=getchar();
    while(c<'0'||c>'9')   {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') t=t*10+c-48,c=getchar();
    return t*f;
}
ll n,m,del,hf,tot,num[2001],dp[1201][12002],cost[2001];
int main()
{
	n=read();m=read();del=read();hf=read();
	For(i,1,n)	num[i]=read(),tot+=num[i];
	For(i,1,n)	cost[i]=read();
	For(i,0,n+1)	For(j,0,tot)	dp[i][j]=-1e17;
	dp[1][0]=m;
	For(i,1,n)
	{
		For(j,0,tot)
				For(t,0,min(num[i],cost[i]==0?(10000000):dp[i][j]/cost[i]))
					dp[i+1][j+t]=max(dp[i+1][j+t],min(m+(j+t)*del,dp[i][j]-t*cost[i]+hf));
	}
	Dow(j,0,tot)	if(dp[n+1][j]>=0)	{cout<<j<<endl;return 0;}
}