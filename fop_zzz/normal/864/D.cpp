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
int n,a[500001],q[500001],vis[500001],top,ans,tag[500001];
int main()
{
	n=read();
	For(i,1,n)
	{
		a[i]=read();
		vis[a[i]]++;
	}
	top=1;
	while(vis[top])	top++;
	For(i,1,n)
	{		
		if(vis[a[i]]>1)	
		{
			if(top<a[i]||tag[a[i]])
			{
				vis[a[i]]--;vis[top]++;
				a[i]=top;
				top++;while(vis[top])	top++;
				ans++;
			}	else tag[a[i]]=1;
		}
	}
	writeln(ans);
	For(i,1,n)	write_p(a[i]);
}