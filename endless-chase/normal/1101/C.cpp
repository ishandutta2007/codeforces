#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int t,n,l[222222],r[222222],sum,ans[222222],n1,n2,c1,c2,f1,f2,mx,cnt;
bool f;
pair<pair<int,int>,int> a[222222];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		cnt=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%d%d",&l[i],&r[i]);
			a[i]=make_pair(make_pair(l[i],r[i]),i);
		}
		sort(a+1,a+n+1);
		mx=0;n1=-1;
		for (int i=1;i<=n;i++)
		{
			if (mx<a[i].first.first && i!=1)
			{
				n1=i;
				break;
			}
			mx=max(mx,a[i].first.second);
		}
		if (!~n1) printf("-1\n");
		else
		{
			for (int i=1;i<n1;i++) ans[a[i].second]=1;
			for (int i=n1;i<=n;i++) ans[a[i].second]=2;
			for (int i=1;i<=n;i++) printf("%d ",ans[i]);
			printf("\n");
		}
	}
	return Accepted;
}