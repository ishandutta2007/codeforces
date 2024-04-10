#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,k,mn[111111],mx[111111],x,ans;
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		mn[i]=1e9;
	}	
	for (int i=1;i<=k;i++)
	{
		scanf("%d",&x);
		mn[x]=min(mn[x],i);
		mx[x]=max(mx[x],i);
	}
	for (int i=1;i<=n;i++)
	{
		if (i-1)//i-1,i
		{
			if (mn[i]>mx[i-1]) ans++;
		}
		if (i+1<=n)
		{
			if (mn[i]>mx[i+1]) ans++;
		}
		if (mn[i]>1e8) ans++;
	}
	printf("%d\n",ans);
	return Accepted;
}