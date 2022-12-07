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
#define N 105
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
int n,s,a[N];
int main()
{
	re(n),re(s);
	++s;
	for(int i=1,h,m;i<=n;++i)
	{
		re(h),re(m);
		a[i]=h*60+m;
	}
	for(int i=1;i<=n;++i)
	{
		if(i==1 && a[i]-s>=0)
		{
			puts("0 0");
			return 0;
		}
		else if((i<n&&a[i+1]-a[i]>=2*s) || i==n)
		{
			int t=a[i]+s;
			printf("%d %d\n",t/60,t%60);
			return 0;
		}
	}
}