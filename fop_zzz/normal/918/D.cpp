#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<map>
#include<algorithm>
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define Dow(i,j,k)  for(ll i=k;i>=j;--i)
#define ll long long
#define mk make_pair
#define eps 1e-8
using namespace std;
inline ll read()
{
    ll t=0,f=1;char c=getchar();
    while(c<'0'||c>'9')   {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') t=t*10+c-48,c=getchar();
    return t*f;
}
int dp[201][201][151],n,m,x,y;
char z[5];
char v[50001];
int head[2001],nxt[50001],poi[50001],cnt;
inline void add(int x,int y,char c){poi[++cnt]=y;nxt[cnt]=head[x];head[x]=cnt;v[cnt]=c;}
inline int Dfs(int x,int y,int las)//xylas 
{
	if(dp[x][y][las]!=0)	return dp[x][y][las];
	int win=-1;
	for(int i=head[x];i;i=nxt[i])
	{
		if(v[i]<las)	continue;
		int tmp=Dfs(y,poi[i],v[i]);
		if(tmp==-1)	win=1;	
	}
	return dp[x][y][las]=win;
}
int main()
{
	n=read();m=read();
	For(i,1,m)	x=read(),y=read(),scanf("%s",z),add(x,y,z[0]);
	For(i,1,n)
		For(j,1,n)	dp[i][j][0]=Dfs(i,j,0);
	For(i,1,n)
	{
		For(j,1,n)	if(dp[i][j][0]==-1)	putchar('B');else putchar('A');puts("");
	}
}