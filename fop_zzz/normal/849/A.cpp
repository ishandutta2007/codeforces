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
int n,a[2001],f[2001],g[2001];
int main()
{
	n=read();
	For(i,1,n)	a[i]=read();
	g[1]=1;
	for(int i=1;i<=n;i++)
		for(int len=1;len<=i;len+=2)
		{	
			if(a[i]&1)	if(a[i-len+1]&1)	f[i]|=g[i-len+1],g[i]|=f[i-len+1];
		}
	if(f[n])	puts("Yes");else puts("No");
}