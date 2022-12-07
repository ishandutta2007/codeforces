#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;	
}
using namespace std;
int n,ans=1;
bool coin[300005]; 
int main()
{
	scanf("%d",&n);
	coin[0]=coin[n+1]=1;
	putchar('1');
	for(int i=1,x,r=n+1;i<=n;++i)
	{
		re(x);
		if(coin[x])continue;
		coin[x]=1;
		++ans;
		while(coin[r-1])--r,--ans;
		printf(" %d",ans+(i==n));
	}
}