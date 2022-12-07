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
int n;
bitset<233> a,b,c;
int main()
{
	re(n);
	a[1]=1;b[0]=1;
	for(int i=2;i<=n;++i)
	{
		c=a;
		a=(a<<1)^b;
		b=c;
	}
	printf("%d\n",n);
	for(int i=0;i<=n;++i)
		printf("%d ",a[i]?1:0);
	printf("\n%d\n",n-1);
	for(int i=0;i<n;++i)
		printf("%d ",b[i]?1:0);
}