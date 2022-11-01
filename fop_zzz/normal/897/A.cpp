#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<queue>
#define For(i,j,k)	for(register int i=j;i<=k;++i)
#define Dow(i,j,k)	for(register int i=k;i>=j;--i)
#define ll long long
using namespace std;
inline ll read()
{
    ll t=0,f=1;char c=getchar();
    while(c<'0'||c>'9')	{if(c=='-')	f=-1;	c=getchar();}
    while(c>='0'&&c<='9')	t=t*10+c-'0',c=getchar();
    return t*f;
}
inline void write(ll x){if(x>=10)	write(x/10);putchar(x%10+'0');}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}
int n,m;
char s[200001],c,c1,c2,l,r;
int main()
{
	n=read();m=read();
	scanf("\n%s",s+1);
	For(i,1,m)
	{
		l=read();r=read();
		scanf("%c",&c1);scanf(" %c",&c2);
		For(j,l,r)	
			if(s[j]==c1)	s[j]=c2;
	}
	int len=strlen(s+1);
	For(i,1,len)	putchar(s[i]);
 }