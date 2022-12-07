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
int n,k,mx=-0x3f3f3f3f,mn=0x3f3f3f3f,a[100001];
int main()
{
	re(n),re(k);
	for(int i=1;i<=n;++i)	
		scanf("%d",&a[i]),mx=max(mx,a[i]),mn=min(mn,a[i]);
	if(k==1)printf("%d\n",mn);
	else if(k==2)printf("%d\n",max(a[1],a[n]));
	else printf("%d\n",mx);
}