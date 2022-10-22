#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int b[N],a[N],le[N],ri[N],sa[N],p=1,n;
long long ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		if(b[p]<b[i])
			p=i;
	}
	for(int i=1;i<=n;i++)
		a[i]=b[(i+p-2)%n+1];
	a[n+1]=b[p];
	for(int i=2;i<=n;i++)
	{
		le[i]=i-1;
		while(le[i]>1&&a[i]>=a[le[i]])
			le[i]=le[le[i]];
	}
	for(int i=n;i>=1;i--)
	{
		ri[i]=i+1;
		while(ri[i]<=n&&a[i]>a[ri[i]])
			ri[i]=ri[ri[i]];
		if(ri[i]<=n&&a[i]==a[ri[i]])
			sa[i]=sa[ri[i]]+1,ri[i]=ri[ri[i]];
	}
	for(int i=2;i<=n;i++)
	{
		ans+=sa[i]+2;
		if(le[i]==1&&ri[i]==n+1)
			ans--;
	}
	printf("%I64d\n",ans);
	return 0;
}