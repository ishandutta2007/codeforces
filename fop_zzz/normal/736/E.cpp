#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>
#include<map>
#include<cstring>
#include<set>
#define eps 1e-5
#define inf 1e9
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define maxn 1000000
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c<='9'&&c>='0')	t=t*10LL+c-48LL,c=getchar();
	return t*f;
}
int win[3001][3001],n,m;
struct node{int x,y;}a[3001];
inline bool cmp(node x,node y){return x.x>y.x;}
inline void gg(){puts("no");exit(0);}
inline void solve(int x)
{
	sort(a+x,a+n+1,cmp);
	int ned=a[x].x;
	Dow(i,x+1,n)
	{
		if(ned>1)	ned-=2,win[a[x].y][a[i].y]=1,win[a[i].y][a[x].y]=0;
		else	if(ned)	a[i].x--,ned--,win[a[x].y][a[i].y]=2,win[a[i].y][a[x].y]=2;
			else a[i].x-=2,win[a[x].y][a[i].y]=0,win[a[i].y][a[x].y]=1;
	}
	a[x].x=ned;
}
int main()
{
	n=read();m=read();
	For(i,1,m)	a[i].x=read(),a[i].y=i;
	int tmp=0,mx=0;
	For(i,1,m)	
	{
		tmp+=a[i].x;mx+=2*(n-i);
		if(tmp>mx)	gg();
	}	
	For(i,m+1,n)
	{
		mx+=2*(n-i);
		a[i].x=min(a[i-1].x,mx-tmp);
		tmp+=a[i].x;a[i].y=i;
	}	
	if(tmp!=mx)	gg();
	For(i,1,n)	solve(i);
	puts("YES");

	For(i,1,n)
	{
		For(j,1,n)
		if(i==j)	putchar('X');
		else 
		if(win[i][j]==1)	putchar('W');
			else	if(win[i][j]==2)	putchar('D');
				else	putchar('L');
		puts("");
	}
}