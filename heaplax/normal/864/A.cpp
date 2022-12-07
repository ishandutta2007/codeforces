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
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v;
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout); 
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;	
}
using namespace std;
int n,a,b,ca,cb;
int main()
{
	re(n);
	for(int i=1,x;i<=n;++i)
	{
		re(x);
		if(!a)a=x,++ca;
		else if(x==a)++ca;
		else if(!b)b=x,++cb;
		else if(x==b)++cb;
	}
	if(a && b && ca+cb==n && ca==cb)
		printf("YES\n%d %d\n",a,b);
	else puts("NO");
}