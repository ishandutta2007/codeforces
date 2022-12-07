#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
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
int n,a[23],b[23];
int main()
{
	re(n);
	for(int i=1;i<=n;++i)re(a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	for(int i=1;i<=n;++i)
	{
		int x=lower_bound(b+1,b+n+1,a[i])-b;
		if(x==1)printf("%d ",b[n]);
		else printf("%d ",b[x-1]);
	}
}