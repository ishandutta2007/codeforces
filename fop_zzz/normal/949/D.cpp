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
#define int ll
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
int n,tt,b,a[1000010],tdb,dp1[1000010],dp2[1000010],x1,x2,ddd,l,r;
signed main(){
	n=read();tt=read();b=read();tdb=n/2*b;
	For(i,1,n)	a[i]=read();
	For(i,1,n)	dp1[i]=min(a[i],tdb)+dp1[i-1],tdb-=min(a[i],tdb);
	tdb=n/2*b;
	Dow(i,1,n)	dp2[i]=min(a[i],tdb)+dp2[i+1],tdb-=min(a[i],tdb);
	tdb=n/2;
	ddd=0;
	For(i,1,tdb)	{r+=tt+1;r=min(r,n);if (ddd+b<=dp1[r])ddd+=b;else x1++; }
	tdb=(n+1)/2+1;
	ddd=0;
	l=n+1;
	Dow(i,tdb,n)
	{
		l-=tt+1;l=max(1ll,l);if (ddd+b<=dp2[l])ddd+=b;else x2++; 
	}
	cout<<max(x1,x2)<<endl;
}