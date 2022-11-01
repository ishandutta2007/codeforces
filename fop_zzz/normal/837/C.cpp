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
int n,a,b,x[2001],y[2001],ans=0;
inline bool check(int i,int j)
{
	int l1=x[i]+y[j],L1=max(y[i],x[j]);
	if((l1<=a&&L1<=b)||(l1<=b&&L1<=a))	return 1;
	l1=x[i]+x[j],L1=max(y[i],y[j]);
	if((l1<=a&&L1<=b)||(l1<=b&&L1<=a))	return 1;
	l1=y[i]+y[j],L1=max(x[i],x[j]);
	if((l1<=a&&L1<=b)||(l1<=b&&L1<=a))	return 1;
	l1=y[i]+x[j],L1=max(x[i],y[j]);
	if((l1<=a&&L1<=b)||(l1<=b&&L1<=a))	return 1;
	return 0;
}
int main()
{
	n=read();a=read();b=read();
	For(i,1,n)
	{
		x[i]=read();y[i]=read();
	}
//	check(1,3);
	For(i,1,n)
		For(j,i+1,n)
			if(check(i,j))	ans=max(ans,x[i]*y[i]+x[j]*y[j]);
	writeln(ans);	
}