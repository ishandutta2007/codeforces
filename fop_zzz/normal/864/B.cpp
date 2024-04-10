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
int ans,n,tj[201];
char s[2001];
inline void doit(int l,int r)
{
	For(i,'a','z')	tj[i]=0;
	For(i,l,r)
	{
		if(isupper(s[i]))	return;
		tj[s[i]]=1;
	}
	int tmp=0;
	For(i,'a','z')	if(tj[i])	tmp++;
	ans=max(ans,tmp);
}
int main()
{
	n=read();
	scanf("%s",s+1);
	For(i,1,n)
		For(j,i,n)
			doit(i,j);	
	writeln(ans);
}