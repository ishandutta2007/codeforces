#include<cstdio>
#include<iostream>
typedef long long LL;
using namespace std;
LL n,m,k;
LL ans;
int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	if (n+m-2<k) 
	{
		printf("-1\n");
		return 0;
	}
	LL nxt;
	for (int i=max(k+1-m,0LL);i+1<=n&&i<=k;i=nxt)
	{
		int j=k-i;
		LL x1=n/(i+1);
		LL x2=m/(j+1);
		LL y1=i+1-n%(i+1);
		LL y2=j+1-m%(j+1);
		LL now=min(x1,x2)+x1*x2;
		if (y1+y2>i+1||y1+y2>j+1) now=x1*x2;
		nxt=min(n/(n/(i+1))+1,k-(m/(m/(j+1)+1)-1));
		ans=max(ans,now);
	}
	printf("%I64d\n",ans);
}