#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<queue>
#define For(i,j,k)  for(int i=j;i<=k;++i)
#define Dow(i,j,k)  for(int i=k;i>=j;--i)
#define ll long long
#define inf 1e9
#define pb push_back
#define local freopen("in.in","r",stdin);
#define c(x,y)  ((x-1))*m+(y)
using namespace std;
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read()
{
	int t=0,f=1;char c=gc();
	while(!isdigit(c))  {if(c=='-') f=-1;c=gc();}
	while(isdigit(c))   t=t*10+c-'0',c=gc();
	return t*f;
}
inline void write(int x){if(x<0) {putchar('-');write(-x);return;}if(x>=10)    write(x/10);putchar(x%10+'0');}
inline void writeln(int x){write(x);puts("");}
inline void write_p(int x){write(x);putchar(' ');}
int g[2000001],sum[2000001][11],n,l,r,k;
inline int Solve(int x)
{
	if(x<10)	return g[x]=x;
	if(g[x])	return g[x];
	int tmp=x,de=1;
	while(tmp){if(tmp%10)	de*=(tmp%10);tmp/=10;}
	return g[x]=Solve(de);
}
int main()
{
	For(i,1,1000000)
		g[i]=Solve(i),sum[i][g[i]]++;
	For(i,1,1000000)	For(j,0,9)	sum[i][j]+=sum[i-1][j];
	n=read();
	For(i,1,n)
	{
		l=read();r=read();k=read();
		writeln(sum[r][k]-sum[l-1][k]);
	}
}