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
#define N 300001
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
int n,m,x,y,ans,a[N];
int sol(int x,int y)
{
	int i=0,j=0;
	for(int k=1;k<=n;++k)
	{
		if(a[k]==1000)--x;
		else --y;
		if((a[k]==1000&&x>=0) || (a[k]==2000&&y>=0))
			i+=a[k],j+=a[k]/10;
		else 
			i+=a[k]-min(a[k],j),j=j-min(a[k],j);
	}
	return i;
}
int main()
{
	re(n);
	for(int i=1;i<=n;++i)
		re(a[i]),m+=a[i];
	for(int i=1;i<=n;++i)
	{
		m-=a[i]/10*11;
		if(m<0)break;
		if(a[i]==1000)++x;
		else ++y;
	}
	printf("%d\n",min(sol(x,y),min(sol(x+1,y),sol(x-1,y+1))));
}