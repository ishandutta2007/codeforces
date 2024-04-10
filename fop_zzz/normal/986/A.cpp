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

const int N=200055;
int q[N],top,a[N],head[N],nxt[N],poi[N],cnt,dis[N],D[N][101],n,m,k,s,x,y;
inline void Add(int x,int y){poi[++cnt]=y;nxt[cnt]=head[x];head[x]=cnt;}
inline void Solve(int x)
{
	queue<int> Q;
	For(i,1,n)
		if(a[i]==x)	dis[i]=0,Q.push(i);else	dis[i]=1e9;
	while(!Q.empty())
	{
		int tx=Q.front();Q.pop();
		for(int i=head[tx];i;i=nxt[i])
			if(dis[poi[i]]==1e9)	Q.push(poi[i]),dis[poi[i]]=dis[tx]+1;
	}
	For(i,1,n)	D[i][x]=dis[i];
}
int main()
{
	n=read();m=read();k=read();s=read();
	For(i,1,n)	a[i]=read();
	For(i,1,m)	x=read(),y=read(),Add(x,y),Add(y,x);
	For(i,1,k)	Solve(i);
	For(i,1,n)
	{
		top=0;
		For(j,1,k)
			q[++top]=D[i][j];
		sort(q+1,q+top+1);
		int sum=0;
		For(j,1,s)	sum+=q[j];
		write_p(sum);
	}
}