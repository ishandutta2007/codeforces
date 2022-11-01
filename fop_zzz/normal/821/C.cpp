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
inline void read(int &tx){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  tx=x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){write(x);puts("");}
int n,now,q[1000001],top,tmp,ans,last=0;
char s[201];
inline bool cmp(int x,int y){return x>y;}
int main()
{
	scanf("%d",&n);
	int now=0;
	For(i,1,2*n)
	{
		scanf("\n%s",s+1);
		if(s[1]=='a')	{scanf("%d",&tmp);q[++top]=tmp;}
		else 
		if(s[1]=='r')
		{
			if(q[top]!=++now&&last<top)	ans++;
			if(q[top]==now)	top--;else last=--top;
			last=min(last,top);
		}
	}
	writeln(ans);
}