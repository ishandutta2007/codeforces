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
#define N 100005
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
int n,x[N],e[20],w[N],q[N],f[N][20],g[N][20];
int maxx(int l,int r)
{
	int k=w[r-l+1];
	return max(g[l][k],g[r-e[k]+1][k]);
}
int minn(int l,int r)
{
	int k=w[r-l+1];
	return min(f[l][k],f[r-e[k]+1][k]);
}
bool check(int p)
{
	for(int i=1;i<=n;++i)
	{
		int l=i,r=n;
		while(l<r)
		{
			int m=l+r+1>>1;
			if(maxx(i,m)<=x[i]+p && minn(i,m)>=x[i]-p)
				l=m;
			else 
				r=m-1;
		}
		q[i]=l;
	}
	int i=3;
	for(int k=max(q[1],q[2]);i<=k;++i)
		k=max(k,q[i]);
	return i>n;
}
int main()
{
	re(n);
	n+=2;
	for(int i=0;i<20;++i)e[i]=1<<i;
	for(int i=1;i<=n;++i)re(x[i]);
	for(int i=n;i;--i)
	{
		f[i][0]=g[i][0]=x[i];
		for(int j=1;i+e[j-1]<=n;++j)
			f[i][j]=min(f[i][j-1],f[i+e[j-1]][j-1]),
			g[i][j]=max(g[i][j-1],g[i+e[j-1]][j-1]);
	}
	for(int i=2;i<=n;++i)w[i]=w[i>>1]+1;
	int l=abs(x[1]-x[2]),r=1000000000;
	while(l < r)
	{
		int m=l+r>>1;
		if(check(m))r=m;
		else l=m+1;
	}
	printf("%d\n",l);
}