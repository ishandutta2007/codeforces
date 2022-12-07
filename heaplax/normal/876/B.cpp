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
int n,m,k,a[100001];
int have[100001];
int main()
{
	re(n),re(k),re(m);
	for(int i=1;i<=n;++i)
		re(a[i]),++have[a[i]%m];
	for(int i=0;i<=m;++i)
		if(have[i]>=k)
		{
			puts("Yes");
			for(int j=1;k;++j)
				if(a[j]%m == i)
					printf("%d ",a[j]),--k;
			return 0;
		}
	puts("No");
}