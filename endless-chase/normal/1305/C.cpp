#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,test,m,a[222222],ans;
int main()
{
	scanf("%d%d",&n,&m);
	if (n>=m+10)
	{
		printf("0\n");
		return Accepted;
	}
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);ans=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			ans=1ll*ans*(a[j]-a[i])%m;
		}
	}
	printf("%d\n",ans);
	return Accepted;
}