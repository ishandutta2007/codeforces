#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,x,y;
pair<int,int> a[111111];
map<pair<long long,long long>,int> mp;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].first,&a[i].second);
	}
	sort(a+1,a+n+1);
	if (n&1) 
	{
		printf("NO\n");
		return 0;
	}
	x=a[1].first+a[n].first;
	for (int i=1;i<=n;i++)
	{
		swap(a[i].first,a[i].second);
		mp[a[i]]=i;
	}
	sort(a+1,a+n+1);
	if (n&1) 
	{
		printf("NO\n");
		return 0;
	}
	y=a[1].first+a[n].first;
	for (int i=1;i<=n;i++)
	{
		if (mp.find(make_pair(1ll*y-a[i].first,1ll*x-a[i].second))==mp.end()) 
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return Accepted;
}