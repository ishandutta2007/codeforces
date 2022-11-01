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
#define pb push_back
using namespace std;
inline int read()
{
	int t=0,f=1;char c=getchar();
	while(!isdigit(c))	{if(c=='-')	f=-1;c=getchar();}
	while(isdigit(c))	t=t*10+c-'0',c=getchar();
	return t*f;
}
inline void write(int x){if(x<0)	{putchar('-');write(-x);return;}if(x>=10)	write(x/10);putchar(x%10+'0');}
inline void writeln(int x){write(x);puts("");}
inline void write_p(int x){write(x);putchar(' ');}

int n,l,r,v[20001],tep=1e9,now,ans,pt[20001],ipt[20001],n1,n2,sum,dp[20001][2];
inline bool cmp(int x,int y){return v[x]>v[y];}
bool ok[20001];
inline void Upd(int &x,int y){x=x>y?x:y;}
inline bool in(int x,int l,int r){return l<=x&&x<=r;}
int main()
{
	n=read();l=read();r=read();
	For(i,1,n)	v[i]=read();
	For(i,1,n)	
	{
		if(read()==0)	pt[++n1]=i;
		else	ipt[++n2]=i;
	}
	ok[0]=1;
	For(i,1,n1)
		Dow(j,v[pt[i]],r)	ok[j]|=ok[j-v[pt[i]]];
	sort(ipt+1,ipt+n2+1,cmp);
	For(i,1,n2)	sum+=v[ipt[i]];
	int now=0;
	For(i,0,r)	if(ok[i]&&i+sum<=r)	dp[i][0]=0; else	dp[i][0]=-inf;
	For(i,1,n2)	
	{
		For(j,0,r)	dp[j][now^1]=dp[j][now];
		For(j,v[ipt[i]],r)	Upd(dp[j][now^1],dp[j-v[ipt[i]]][now]+in(j-v[ipt[i]],l,r));
		now^=1;
	}
	For(i,l,r)	ans=max(ans,dp[i][now]);

	now=0;
	For(i,0,r)	if(ok[i]&&i+sum>r) dp[i][0]=0;else	dp[i][0]=-inf;
	For(i,1,n2)	
	{
		For(j,0,r)	dp[j][now^1]=dp[j][now];
		For(j,v[ipt[i]],r)	Upd(dp[j][now^1],dp[j-v[ipt[i]]][now]+in(j-v[ipt[i]],l,r));
		now^=1;
	}
	For(i,l,r)	ans=max(ans,dp[i][now]+1);

	writeln(ans);
}