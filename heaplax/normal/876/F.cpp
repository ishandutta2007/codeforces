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
#define N 200001
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
LL ans;
int n,a[N],L[N],R[N],P[31];
map<int,int> mp;
int main()
{
	re(n);
	for(int i=0;i<31;++i)P[i]=0;
	for(int i=1;i<=n;++i)
	{
		re(a[i]);R[i]=n+1;
		for(int j=0;j<31;++j)
			if(a[i]&(1<<j))P[j]=i;
			else L[i]=max(L[i],P[j]);
	}
	for(int i=0;i<31;++i)P[i]=n+1;
	for(int i=n;i;--i)
		for(int j=0;j<31;++j)
			if(a[i]&(1<<j))P[j]=i;
			else R[i]=min(R[i],P[j]);
	ans=n*(n+1ll)/2;
	for(int i=1;i<=n;++i)
	{
		ans-=1ll*(i-max(mp[a[i]],L[i]))*(R[i]-i);
		mp[a[i]]=i;
	}
	printf("%I64d\n",ans);
}