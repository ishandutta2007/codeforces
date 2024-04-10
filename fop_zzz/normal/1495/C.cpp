#include<bits/stdc++.h>
#define For(i,j,k)  for(int i=j;i<=k;++i)
#define Dow(i,j,k)  for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back
#define fir first
#define sec second
#define pb push_back
#define pa pair<int,int>
#define mk make_pair
 
using namespace std;
 
inline ll read()
{
    ll t=0,dp=1;char c=getchar();
    while(!isdigit(c))  {if(c=='-') dp=-1;c=getchar();}
    while(isdigit(c))   t=t*10+c-48,c=getchar();
    return t*dp;
}
inline void write(ll x){if(x<0)  {putchar('-');x=-x;}    if(x>=10)    write(x/10);putchar(x%10+48);}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}

int n,m;
char s[505][505];
int main()
{
	int T=read();
	while(T--)
	{
		n=read();m=read();
		For(i,1,n)
			scanf("%s",s[i]+1);
		int now=1;
		while(now<=n)
		{
			int lnow=now+3;
			For(i,1,m)	s[now][i]=s[lnow][i]='X';
			int pos=0;
			For(i,1,m)
			{
				if(s[now+1][i-1]!='X'&&s[now+1][i+1]!='X'&&s[now+2][i-1]!='X'&&s[now+2][i+1]!='X')
					pos=i;
			}
			s[now+1][pos]=s[now+2][pos]='X';
			now+=3;
		}
		if(now>n)	now-=3;
		if(n-now==2)
		{
			For(i,1,m)
			{
				if(s[n][i]=='X')	s[n-1][i]='X';
			}
		}
		For(i,1,n)	{For(j,1,m)	putchar(s[i][j]);puts("");}
	}

}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
	-- Benq
*/