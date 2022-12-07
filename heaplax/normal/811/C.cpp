#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define N 5555
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
int n,f[N],a[N],l[N],r[N];
int main()
{
	re(n);
	for(int i=1;i<=n;++i)
	{
		re(a[i]);
		if(!l[a[i]])l[a[i]]=i;
		r[a[i]]=i;
	}
	for(int i=1;i<=n;++i)
	{
		f[i]=f[i-1];
		int now=0,le=i,re=i;
		for(int j=i;j>=le;--j)
		{
			le=min(le,l[a[j]]);
			re=max(re,r[a[j]]);
			if(l[a[j]]==j)now^=a[j];
		}
		if(re==i)f[i]=max(f[i],f[le-1]+now);
	}
	printf("%d\n",f[n]);
}