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
#define For(i,j,k) for(int i=j;i<=k;i++)
#define Dow(i,j,k) for(int i=k;i>=j;i--)
using namespace std;
inline void read(int &tx){   int x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  tx=x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){write(x);puts("");}
int n,a[101][101];
int main()
{
	read(n);
	For(i,1,n)
		For(j,1,n)
			read(a[i][j]);
	For(i,1,n)
	{
		For(j,1,n)
		{
			bool flag=0;
			if(a[i][j]!=1)
			For(l,1,n)
			{
				For(c,1,n)	if(a[i][l]+a[c][j]==a[i][j])	flag=1;
			}
			if(flag==0&&a[i][j]!=1)	{puts("No");return 0;}
		}
	}
	puts("Yes");
}