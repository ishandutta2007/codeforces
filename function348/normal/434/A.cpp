#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=100010;
int n,m;
int a[N],first[N],next[N],b[N];
LL ans;
inline int abs(int a){return a>0?a:-a;}
int main()
{
	scanf("%d%d",&m,&n);
	LL now=0;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),now+=abs(a[i]-a[i-1]);
	now-=a[1];
	ans=now;
	for (int i=n;i>=1;i--)
	{
		next[i]=first[a[i]];
		first[a[i]]=i;
	}
	for (int ii=1;ii<=m;ii++)
	{
		LL tmp=now;
		int p=0;
		for (int i=first[ii];i>=1;i=next[i])
		{
			if (i>1&&a[i]!=a[i-1]) tmp-=abs(a[i]-a[i-1]),b[++p]=a[i-1];
			if (i<n&&a[i]!=a[i+1]) tmp-=abs(a[i]-a[i+1]),b[++p]=a[i+1];
		}
		sort(b+1,b+1+p);
		int r=b[(p+1)>>1];
		for (int i=first[ii];i>=1;i=next[i])
		{
			if (i>1&&a[i]!=a[i-1]) tmp+=abs(r-a[i-1]);
			if (i<n&&a[i]!=a[i+1]) tmp+=abs(r-a[i+1]);
		}
		ans=min(ans,tmp);
	}
	printf("%I64d\n",ans);
}