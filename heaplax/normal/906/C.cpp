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
#define INF 0x3f3f3f3f
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
}
using namespace std;
int n,m,s[22];
int f[1<<22],pr[1<<22],fa[1<<22];
void gg(int x)
{
	if(!x)return;
	printf("%d ",pr[x]+1);
	gg(fa[x]);
}
int main()
{
	memset(f,INF,sizeof f);
	re(n),re(m);
	for(int i=0;i<n;++i)s[i]|=1<<i;
	for(int u,v;m--;)
	{
		re(u),re(v);
		--u;--v;
		s[u]|=1<<v;
		s[v]|=1<<u;
	}
	bool ok=1;
	for(int i=0;i<n;++i)
	{
		if(s[i]!=(1<<n)-1)ok=0;
		f[s[i]]=1;pr[s[i]]=i;
	}
	if(ok)
	{
		puts("0");
		return 0;
	}
	for(int i=0;i<1<<n;++i)if(f[i]<INF)
		for(int j=0;j<n;++j)
			if((i>>j&1) && f[i]+1<f[i|s[j]])
			{
				f[i|s[j]]=f[i]+1;
				fa[i|s[j]]=i;
				pr[i|s[j]]=j;
			}
	printf("%d\n",f[(1<<n)-1]);
	gg((1<<n)-1);
}