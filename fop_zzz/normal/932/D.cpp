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
#define int ll
#define inf 1e17
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
int Fa[500001][21],n,tv[500001],cnt,opt,x,y;
ll sum[500001][21];
inline void Insert(int x,int y,int v)
{
	int tmp=x;//yx,v
	if(tv[tmp]<v)		
	{	
		Dow(i,0,20)	if(tv[Fa[tmp][i]]<v)	tmp=Fa[tmp][i];
		tmp=Fa[tmp][0]; 
	}
	Fa[y][0]=tmp;tv[y]=v;
	sum[y][0]=tv[Fa[y][0]];
	For(i,1,20)
	{
		Fa[y][i]=Fa[Fa[y][i-1]][i-1];
		sum[y][i]=sum[y][i-1]+sum[Fa[y][i-1]][i-1];
	}
}
ll ans;
inline void Solve(int x,int k)
{
	int tot=1;
	k-=tv[x];
	if(k<0)	tot=0;
	Dow(i,0,20)	if(sum[x][i]<=k)	tot+=1<<i,k-=sum[x][i],x=Fa[x][i];
	writeln(tot);
	ans=tot;
}
signed main()
{
	n=read();
	For(i,0,20)	Fa[1][i]=0,sum[0][i]=sum[1][i]=inf;tv[0]=inf;
	cnt=2;
	For(i,1,n)
	{
		opt=read();x=read()^ans;y=read()^ans;
//		cout<<x<<'-'<<y<<endl;
		if(opt==1)	Insert(x,cnt,y),cnt++;
		else	Solve(x,y);
	}
}