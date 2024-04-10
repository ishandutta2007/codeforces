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
int n,m,len;
ll dp[201][201][201],po[201],mo=1e9+7;
char s[2001];
inline void Upd(ll &x,ll y){x=(x+y)%mo;}
int main()
{
	len=read();n=read();
	scanf("\n%s",s+1);
	For(i,1,len)	dp[s[i]-'0'][i][i]=1;
	po[1]=po[0]=2;
	For(i,2,n)	po[i]=po[i-1]*po[i-2]%mo;
	For(i,2,n)
		For(l,1,len)
			For(r,l,len)
			{
				Upd(dp[i][l][r],dp[i-2][l][r]*(l==1?po[i-1]:1)%mo);
				Upd(dp[i][l][r],dp[i-1][l][r]*(r==len?po[i-2]:1)%mo);
				For(k,l,r-1)	Upd(dp[i][l][r],dp[i-1][l][k]*dp[i-2][k+1][r]);
			}
	writeln(dp[n][1][len]);
}