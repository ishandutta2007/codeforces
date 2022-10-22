#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,ans;
	scanf("%d%d",&n,&k);
	ans=k;
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		if(k%x==0)
			ans=min(ans,k/x);
	}
	printf("%d\n",ans);
	return 0;
}