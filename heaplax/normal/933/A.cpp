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
#define N 2001
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
int n,ans,a[N];
int main()
{
	re(n);
	for(int i=1;i<=n;++i)re(a[i]);
	for(int i=1;i<=n;++i)
	{
		int now=0;
		for(int j=1;j<i;++j)now+=(a[j]==1);
		for(int j=i;j<=n;++j)now+=(a[j]==2);
		ans=max(ans,now);
		for(int j=i,mx=0,num=0;j<=n;++j)
		{
			if(a[j]==2)
			{
				++num;
				mx=max(mx,num);
				--now;
			}
			else ++mx;
			ans=max(ans,mx+now);
		}
	}
	printf("%d\n",ans);
}