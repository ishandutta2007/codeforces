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
char s[201][201];
bool ok=1;
int n,m;
inline bool check(int x,int y)
{
	For(i,1,m)	if(s[x][i]!=s[y][i])	return 0;
	return 1;
}
int main()
{
	n=read();m=read();
	For(i,1,n)	scanf("\n%s",s[i]+1);
	For(p1,1,n)	
		For(p2,1,n)
			For(j,1,m)	if(s[p1][j]=='#'&&s[p2][j]=='#')	ok&=check(p1,p2);
	if(ok)	puts("Yes");	else puts("No"); 
}