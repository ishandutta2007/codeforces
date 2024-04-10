#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,b,ans=1;
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=a;i++)
	{
		int j=n-i;
		ans=max(ans,min(i?a/i:0,j?b/j:0));
	}
	printf("%d\n",ans);
	return 0;
}