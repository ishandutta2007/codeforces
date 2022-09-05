#include<bits/stdc++.h>
using namespace std;
int n,k,a[200010];
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int now=0;
	long long ans=0;
	for (int i=1;i<=n;i++)
	{
		now+=a[i];
		ans+=now/k;
		now%=k;
		if (now>a[i])
		{
			ans++;
			now=0;
		}
	}
	if (now>0)
	{
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}