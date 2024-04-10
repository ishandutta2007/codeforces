#include<bits/stdc++.h>
using namespace std;
int a[1010];
bool u;
int ans;
int mx=0x3f3f3f3f;
int main()
{
	int n;
	scanf("%d",&n);
	n<<=1;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
		{
			ans=0;
			for(int k=1;k<=n;k++)
				if(k!=i&&k!=j)
				{
					ans+=u?a[k]:-a[k];
					u^=1;
				}
			mx=min(mx,ans);
		}
	printf("%d\n",mx);
	return 0;
}