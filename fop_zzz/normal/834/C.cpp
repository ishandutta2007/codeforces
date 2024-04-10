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
#define eps 1e-8
#define For(i,j,k) for(int i=j;i<=k;i++)
#define Dow(i,j,k) for(int i=k;i>=j;i--)
#define clr(x, c) memset(x, c, sizeof(x))
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){write(x);puts("");};
ll T,a,b;
inline ll gcd(ll x,ll y){return y==0?x:gcd(y,x%y);}
int main()
{
	T=read();
	For(i,1,T)
	{
		a=read();b=read();
		ll g=gcd(a,b);
		ll ta=a/g,tb=b/g;
		ll tot=ta*tb;
		bool flag=0;
		if(g%tot==0)
		{
			ll s=g/tot;
			ll tr=pow((double)s,(double)1/3)+eps;
			if(tr*tr*tr==s)
				puts("Yes"),flag=1;
		}
		if(flag==0)	puts("No");
	}
}