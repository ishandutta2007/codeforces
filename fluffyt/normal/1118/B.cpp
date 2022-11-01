#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,ans,a[200005];
ll sum[200005][2];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) 
	{
		sum[i][0]=sum[i-1][0],sum[i][1]=sum[i-1][1];
		if(i&1) sum[i][1]+=a[i];
		else sum[i][0]+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(sum[i-1][0]+sum[n][1]-sum[i][1]==sum[i-1][1]+sum[n][0]-sum[i][0]) ans++;
	}
	printf("%d\n",ans);
	return 0; 
}