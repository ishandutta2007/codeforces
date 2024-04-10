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
#define inf 1e9
#define ll long long
#define For(i,j,k) for(ll i=j;i<=k;i++)
#define Dow(i,j,k) for(ll i=k;i>=j;i--)
using namespace std;
inline void read(ll &tx){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  tx=x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){write(x);puts("");}
ll n,m,ans,now,x,y;
int main()
{
	read(n);read(m);
	ll y=m;x=0;
	while(1)
	{
	
		now=y*(y+1)/2*(x+1)+x*(x+1)/2*(y+1);
		ans=max(ans,now);	
		x+=n;y--;
		if(y<0)	break;
	}
	writeln(ans);
}