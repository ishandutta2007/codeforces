#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,l[111111],x,sum[1111111];
vector<int> a[111111];
bool can[111111];
long long ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&l[i]);
		for (int j=1;j<=l[i];j++)
		{
			scanf("%d",&x);
			a[i].push_back(x);
		}
	}
	for (int i=1;i<=n;i++)
	{
		can[i]=1;
		for (int j=0;j<l[i]-1;j++)
		{
			if (a[i][j]<a[i][j+1]) can[i]=0;
		}
		if (can[i]) sum[a[i][0]]++;
	}
	for (int i=1;i<=1000000;i++) sum[i]+=sum[i-1];
	for (int i=1;i<=n;i++)
	{
		if (can[i])
		{
			ans+=sum[a[i][l[i]-1]];
		}
	}
	printf("%lld\n",1ll*n*n-ans);
	return Accepted;
}