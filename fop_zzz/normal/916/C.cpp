// luogu-judger-enable-o2
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<map>
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
int n,m,ax[200001],ay[200001],av[200001],top;
int main()
{
	n=read();m=read();
	For(i,1,n-2)	ax[++top]=i,ay[top]=i+1,av[top]=1,m--;
	int tmp=n-2;
	av[++top]=200003-tmp;ax[top]=n-1;ay[top]=n;m--;
	For(i,1,n)
	{
		if(!m)	break;
		For(j,i+2,n)	
			if(!m)	break;	
			else
			{
				ax[++top]=i;ay[top]=j;av[top]=900007;m--;
			}
	}
	write_p(200003);writeln(200003);
	For(i,1,top)	write_p(ax[i]),write_p(ay[i]),writeln(av[i]);
	 //200003;
}