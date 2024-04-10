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

int n,a,b,dp[5001][5001],f[5001];
char s[5001];
int main()
{
	n=read();a=read();b=read();
	scanf("\n%s",s+1);
	For(i,1,n)	
		For(j,i+1,n)	
			if(s[i]==s[j])	dp[i][j]=dp[i-1][j-1]+1;else	dp[i][j]=0;
	For(i,1,n)
	{
		f[i]=f[i-1]+a;
		For(j,1,i)
		{
			int l=max(j,i-dp[j][i]);
//			if(i==3&&j==1)	cout<<l<<' '<<dp[1][3]<<endl;
			f[i]=min(f[i],f[l]+b);
		}
	}
	writeln(f[n]);
}