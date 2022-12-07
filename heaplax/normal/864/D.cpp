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
int n,r=1,ans,a[200001],have[200001],dw[200001];
bool hw[200001],last[200001];
int main()
{
	re(n);
	for(int i=1;i<=n;++i)
		re(a[i]),++have[a[i]];
	for(int i=n;i;--i)
		if(!dw[a[i]])
			dw[a[i]]=i,last[i]=1;
	for(int i=1;i<=n;++i)	
	{
		while(have[r])++r;
		if(have[a[i]]>1&&(hw[a[i]]||(r<a[i]&&!last[i])))
			++ans,a[i]=r,have[r]=1;
		else 
			hw[a[i]]=1;	
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;++i)
		printf("%d ",a[i]);
}