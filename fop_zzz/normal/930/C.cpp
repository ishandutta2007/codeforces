#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<queue>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define inf 1e9
using namespace std;
inline int read()
{
	int t=0,f=1;char c=getchar();
	while(!isdigit(c))	{if(c=='-')	f=-1;c=getchar();}
	while(isdigit(c))	t=t*10+c-'0',c=getchar();
	return t*f;
}
inline void write(int x){if(x>=10)	write(x/10);putchar(x%10+'0');}
inline void writeln(int x){write(x);puts("");}
inline void write_p(int x){write(x);putchar(' ');}
int n,m,x[200001],y[200001],cnt[200001],ans,L=1e9,R,t[200001],mx,tr[200001];
int dp[200001],dp1[200001];
inline void Add(int x,int v){for(;x<=n;x+=x&-x)	tr[x]=max(tr[x],v);}
inline int Ask(int x){int tmp=0;for(;x;x-=x&-x)	tmp=max(tmp,tr[x]);return tmp;}
int main()
{
	n=read();m=read();
	For(i,1,n)	x[i]=read(),y[i]=read();
	For(i,1,n)	t[x[i]]++,t[y[i]+1]--;
	int tmp=0;
	For(i,1,m)	tmp+=t[i],cnt[i]=tmp,mx=max(mx,cnt[i]);
	For(i,1,m)	if(mx==cnt[i])	L=min(L,i),R=max(R,i);
	For(i,1,m)
	{
		dp[i]=Ask(cnt[i]+1)+1;
		Add(cnt[i]+1,dp[i]);
	}		
	For(i,1,n)	tr[i]=0;
	Dow(i,1,m)
	{
		dp1[i]=Ask(cnt[i]+1)+1;
		Add(cnt[i]+1,dp1[i]);
	}	
	For(i,1,m-1)	ans=max(ans,dp[i]+dp1[i+1]);
	writeln(ans);
}