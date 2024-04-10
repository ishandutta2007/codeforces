#pragma comment(linker, "/stack:200000000")
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

const int N=1005;
int dp[N][4],n;
char s[4][N];
int main()
{
	//dp i jij
	int T=read();
	while(T--)
	{
		bool flag=0;
		n=read();read();
		scanf("\n%s\n%s\n%s",s[1]+1,s[2]+1,s[3]+1);
		memset(dp,0,sizeof dp);
		if(s[1][1]=='s')	dp[1][1]=1;else	if(s[2][1]=='s')	dp[1][2]=1;else	dp[1][3]=1;
		For(i,1,n)
		{
			int sx=1+(i-1)*3;
			if(sx>=n)	
				if(dp[i][1]||dp[i][2]||dp[i][3])	{puts("YES");flag=1;break;}
				else	break;
			For(j,1,3)	if(dp[i][j])
			{
				For(k,1,3)	if(abs(k-j)<=1)
				{
					if(s[j][sx+1]!='.'||s[k][sx+1]!='.')	continue;
					if('A'<=s[k][sx+3]&&s[k][sx+3]<='Z')	continue;
					dp[i+1][k]=1;
				}
			}
		}
		if(!flag)	puts("NO");
	}
}