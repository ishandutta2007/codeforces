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
#define int long long
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
bool have;
int n,ans,p[N],c[N];
main()
{
	re(n);
	for(int i=1;i<=n;++i)
		re(p[i]),re(c[i]),c[i]+=48,have|=c[i]=='G';
	if(!have)
	{
		int lr,lb;
		for(int i=1;i<=n;++i)
			if(c[i]=='R')
			{
				lr=i;
				break;
			}
		for(int i=1;i<=n;++i)
			if(c[i]=='B')
			{
				lb=i;
				break;
			}
		for(int i=n;i;--i)
			if(c[i]=='R')
			{
				ans+=p[i]-p[lr];
				break;
			}
		for(int i=n;i;--i)
			if(c[i]=='B')
			{
				ans+=p[i]-p[lb];
				break;
			}
		printf("%lld\n",ans);
		return 0;
	}
	int last=0;
	for(int i=1;i<=n;++i)
		if(c[i]=='G')
		{
			if(!last)
			{
				for(int j=1;j<i;++j)
					if(c[j]=='R')
					{
						ans+=p[i]-p[j];
						break;
					}
				for(int j=1;j<i;++j)
					if(c[j]=='B')
					{
						ans+=p[i]-p[j];
						break;
					}
			}
			else
			{
				int mxr=0,mxb=0,lr=last,lb=last;
				for(int j=last+1;j<=i;++j)
				{
					if(c[j]!='B')
						mxr=max(mxr,p[j]-p[lr]),
						lr=j;
					if(c[j]!='R')
						mxb=max(mxb,p[j]-p[lb]),
						lb=j;
				}
				ans+=min(2*(p[i]-p[last]),3*(p[i]-p[last])-mxr-mxb);
			}
			last=i;
		}
	for(int i=n;i>last;--i)
		if(c[i]=='R')
		{
			ans+=p[i]-p[last];
			break;
		}
	for(int i=n;i>last;--i)
		if(c[i]=='B')
		{
			ans+=p[i]-p[last];
			break;
		}
	printf("%lld\n",ans);
}