#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
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
int n,ans,out[10001];
int main()
{
	re(n);
	for(int i=max(n-1000,0);i<=n;++i)
	{
		int sum=0;
		for(int c=i;c;c/=10)
			sum+=c%10;
		if(sum+i==n)out[++ans]=i;
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;++i)
		printf("%d ",out[i]);
}