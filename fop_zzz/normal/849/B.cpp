#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <cstring>
#include <ctime>
#include <vector>
#define ll long long
#define N 1020
#define lson x*2
#define rson x*2+1
#define For(i,j,k) for(int i=j;i<=k;i++)
#define Dow(i,j,k) for(int i=k;i>=j;i--)
#define clr(x, c) memset(x, c, sizeof(x))
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){write(x);puts("");};
int n,y[2001],poi1,poi2,vis[2001];
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}
inline void solve(int x)
{
	For(i,1,n)	vis[i]=0;poi1=poi2=0;
	int delta=y[x]-y[1],dis=x-1;
	int tmp=0;	
	if(delta!=0)	tmp=gcd(abs(dis),abs(delta)),dis/=tmp,delta/=tmp;else dis=1;
	vis[1]=1;
	for(int i=1;i*dis+1<=n;i++)
		if(i*delta+y[1]==y[i*dis+1])	vis[i*dis+1]=1;
	For(i,1,n)
		if(!vis[i])
			if(!poi1)	poi1=i;else if(!poi2)	poi2=i;else break;
	if(poi1==0)	return;
	if(poi2==0)	{puts("YES");exit(0);}
	vis[poi1]=1;
	int delta1=y[poi2]-y[poi1],dis1=poi2-poi1;
	int tmp1=gcd(dis1,delta1);
	if(delta1!=0)	tmp1=gcd(abs(dis1),abs(delta1)),dis1/=tmp1,delta1/=tmp1;	else	dis1=1;
	if(dis!=dis1||delta1!=delta)	return;
	for(int i=1;i*dis1+poi1<=n;i++)
		if(i*delta+y[poi1]==y[i*dis+poi1])	vis[i*dis+poi1]=1;	
	For(i,1,n)	if(!vis[i])	return;
	puts("Yes");exit(0);
}
inline void tp()
{
	vis[1]=1;
		For(i,1,n)
		if(!vis[i])
			if(!poi1)	poi1=i;else if(!poi2)	poi2=i;else break;
	if(poi1==0)	return;
	if(poi2==0)	{puts("YES");exit(0);}
	vis[poi1]=1;
	int delta1=y[poi2]-y[poi1],dis1=poi2-poi1;
	if(y[2]-delta1==y[1])	return;
	int tmp1=gcd(dis1,delta1);
	if(delta1!=0)	tmp1=gcd(abs(dis1),abs(delta1)),dis1/=tmp1,delta1/=tmp1;	else	dis1=1;
	for(int i=1;i*dis1+poi1<=n;i++)
		if(i*delta1+y[poi1]==y[i*dis1+poi1])	vis[i*dis1+poi1]=1;	
	For(i,1,n)	if(!vis[i])	return;
	puts("Yes");exit(0);
}
int main()
{
	n=read();
	For(i,1,n)	y[i]=read();
//	solve(3);
	tp();
	For(i,1,n)
		solve(i);
	puts("No");
}