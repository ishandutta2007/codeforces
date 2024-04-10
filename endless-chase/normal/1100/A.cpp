#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,k,a[111],cnt,cntt,ans; 
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=k;i++)
	{
		cnt=cntt=0;
		for (int j=1;j<=n;j++)
		{
			if ((j-i)%k==0) continue;
			if (a[j]==-1) cnt++;
			else cntt++;
		}
		ans=max(ans,abs(cnt-cntt));
	}
	cout<<ans<<endl;
	return Accepted;
}