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
int n;
char s[2005][6];
inline void OK(int x1,int y1,int x2,int y2)
{
	s[x1][y1]=s[x2][y2]='+';
	puts("YES");
	For(i,1,n)	{For(j,1,5)	putchar(s[i][j]);puts("");}
	exit(0);
}
int main()
{
	n=read();
	For(i,1,n)
		scanf("\n%s",s[i]+1);
	For(i,1,n)
	{
		if(s[i][1]=='O'&&s[i][2]=='O')	OK(i,1,i,2);
		if(s[i][4]=='O'&&s[i][5]=='O')	OK(i,4,i,5);
	}
//	For(i,1,n-1)
//	{
//		For(j,1,5)
//			if(j!=3)
//			if(s[i][j]=='O'&&s[i+1][j]==0)	OK(i,j,i+1,j);
//	}
	puts("NO");
}