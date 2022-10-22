#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		mp[x]++;
	}
	int ans=0;
	for(auto i:mp)
		ans=max(ans,i.second);
	printf("%d\n",ans);
	return 0;
}