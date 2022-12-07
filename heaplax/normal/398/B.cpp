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
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;	
}
using namespace std;
bool a[2002],b[2002];
int n,m,ca,cb;
double f[2002][2002];
int main()
{
	re(n),re(m);
	for(int i=1,x,y;i<=m;++i)
	{
		re(x),re(y);
		ca+=!a[x];
		cb+=!b[y];
		a[x]=b[y]=1;
	}
	for(int i=n;i>=ca;--i)
		for(int j=n;j>=cb;--j)if(i<n || j<n)
			f[i][j]=(1+(f[i+1][j]*(n-i)*j+f[i][j+1]*i*(n-j)+f[i+1][j+1]*(n-i)*(n-j))/n/n)/(1-1.0*i/n*j/n);
	printf("%.10f\n",f[ca][cb]);
}