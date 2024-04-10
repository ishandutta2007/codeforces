#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,a[111111],c[111111],mx;
long long ans;
pair<int,int> arr[111111];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&c[i]);
		arr[i]=make_pair(a[i],i);
	}
	sort(arr+1,arr+n+1);
	mx=a[arr[1].second]+c[arr[1].second];
	for (int i=2;i<=n;i++)
	{
		if (mx<a[arr[i].second]) ans+=(a[arr[i].second]-mx);
		mx=max(mx,a[arr[i].second]+c[arr[i].second]);
	}
	for (int i=1;i<=n;i++) ans+=c[i];
	printf("%lld\n",ans);
	return Accepted;
}