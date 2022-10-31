#include<cstdio>
#include<iostream>
using namespace std;
const int N=100010;
int n,q,t;
int a[N],b[N],seq[N],L[N],R[N];
int abs(int n) { return n>0?n:-n;}
int main()
{
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	while (q--)
	{
		int l,r,m;
		scanf("%d%d",&l,&r);
		m=r-l;t=0;
		for (int i=1;i<=m;i++) b[i]=abs(a[i+l]-a[i+l-1]);
		for (int i=1;i<=m;i++)
		{
			while (t&&b[seq[t]]<=b[i]) t--;
			seq[++t]=i;
			if (t==1) L[i]=1;else L[i]=seq[t-1]+1;
		}
		t=0;
		for (int i=m;i>=1;i--)
		{
			while (t&&b[seq[t]]<b[i]) t--;
			seq[++t]=i;
			if (t==1) R[i]=m;else R[i]=seq[t-1]-1;
		}
		long long ans=0;
		for (int i=1;i<=m;i++)
			ans+=1LL*(i-L[i]+1)*(R[i]-i+1)*b[i];
		printf("%lld\n",ans);
	}
	return 0;
}