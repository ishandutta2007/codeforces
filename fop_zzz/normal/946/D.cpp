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
#define fir first
#define sec second
#define pb push_back
#define mk make_pair
#define pa pair<int,int>
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
int dp[601][601],n,m,k,tv[601][601],q[601],top;
inline void Upd(int &x,int y){x=x>y?y:x;}
char s[2001]; 
int main()
{
	n=read();m=read();k=read();
	For(i,1,n)	For(j,0,m)	tv[i][j]=inf;
	For(i,1,n)
	{
		scanf("\n%s",s+1);
		top=0;memset(q,0,sizeof q);
		For(j,1,m)	if(s[j]=='1')	q[++top]=j;
		For(j,1,top)	For(t,j,top)	Upd(tv[i][top-(t-j+1)],q[t]-q[j]+1);	
		tv[i][top]=0;
	}

//	For(i,1,n)	For(j,0,m)	cout<<tv[i][j]<<' '<<i<<' '<<j<<endl;
	For(i,1,n+1)	For(j,0,k)	dp[i][j]=inf;		
	dp[1][0]=0;
	For(i,1,n)
	{
		For(j,0,k)
			For(del,0,k)	if(j+del<=k&&tv[i][del]!=inf)
				Upd(dp[i+1][j+del],dp[i][j]+tv[i][del]);
	}
	int ans=1e9;
	For(i,0,k)	ans=min(dp[n+1][i],ans);
	writeln(ans);
}