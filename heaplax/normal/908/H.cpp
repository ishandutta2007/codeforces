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
#define N 50
#define LL long long
#define LOG(x) cerr<<#x<<" = "<<x<<endl
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
int n,m,id[N];
char s[N][N];
int fa[N],siz[N],f[1<<23],ok[1<<23];
bool gg[1<<23];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void fwt(int *x,int n,int f)
{
	for(int i=1;i<n;i<<=1)
		for(int j=0;j<n;j+=i<<1)
			for(int k=0;k<i;++k)
				x[i+j+k]+=x[j+k]*f;
}
int main()
{
	re(n);
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s[i]+1);
		for(int j=i+1;j<=n;++j)
			if(s[i][j]=='A')
				fa[find(i)]=find(j);
	}
	for(int i=1;i<=n;++i)
	{
		++siz[find(i)];
		for(int j=i+1;j<=n;++j)
			if(s[i][j]=='X' && find(i)==find(j))
			{
				puts("-1");
				return 0;
			}
	}
	for(int i=1;i<=n;++i)
		if(i==find(i) && siz[i]>=2)
			id[i]=m++;
	if(!m)
	{
		printf("%d\n",n-1);
		return 0;
	}
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			if(s[i][j]=='X' && siz[find(i)]>1 && siz[find(j)]>1)
				gg[(1<<id[find(i)])|(1<<id[find(j)])]=1;
	for(int i=0;i<(1<<m);++i)
		for(int j=0;j<m;++j)
			if(i>>j&1)
				gg[i]|=gg[i^(1<<j)];
	for(int i=0;i<(1<<m);++i)f[i]=!gg[i];
	memcpy(ok,f,sizeof f);
	fwt(f,1<<m,1);
	for(int i=0;i<m;++i)
	{
		if(ok[(1<<m)-1])
		{
			printf("%d\n",n+i);
			return 0;
		}
		fwt(ok,1<<m,1);
		for(int j=0;j<(1<<m);++j)ok[j]*=f[j];
		fwt(ok,1<<m,-1);
	}
}