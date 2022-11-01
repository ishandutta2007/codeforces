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
inline void write_p(ll x){write(x);putchar(' ');}
int a,b,f,k,dis1,dis2,ans,have;
inline void go()
{	
	have-=dis1;
	if(have<0)	have=b-dis1*2,ans++;
	have-=dis2;
}
inline void back()
{
	have-=dis2;
	if(have<0)	ans++,have=b-dis2*2;
	have-=dis1;
}
int main()
{
	a=read();b=read();f=read();k=read();
	dis1=f,dis2=(a-f);
	if(dis1>b||dis2>b)	{puts("-1");return 0;}
	if(dis1*2>b&&k>=3)	{puts("-1");return 0;}
	if(dis2*2>b&&k>=2)	{puts("-1");return 0;}
	have=b;
	For(i,1,k)
		{if(i&1)	go();else back();}
	writeln(ans+(have<0));
}