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
#define LL long long
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define int long long
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;	
}
using namespace std;
int n,L,ans,c[32],f[32];
main()
{
	re(n),re(L);
	for(int i=1;i<=n;++i)re(c[i]);
	for(int i=n+1;i<=31;++i)c[i]=1ll<<60;
	for(int i=2;i<=31;++i)
		c[i]=min(c[i],c[i-1]*2ll);
	for(int i=30;i;--i)
		c[i]=min(c[i],c[i+1]);
	for(int i=1;i<=30;++i)
		if(L&(1<<(i-1)))
		{
			f[i]=c[i+1];
			for(int j=i-1,now=c[i];j>=0;--j)
			{
				f[i]=min(f[i],f[j]+now);
				if(j==0)break;
				if(L&(1<<(j-1)))
					now+=c[j];
			}
		}
		else f[i]=f[i-1];
	printf ("%I64d", f[30]);
}