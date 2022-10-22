#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,c,ans=0;
		scanf("%d%d%d",&a,&b,&c);
		if(b<c)
			swap(b,c);
		if(a<b)
			swap(a,b);
		if(b<c)
			swap(b,c);
		if(a)
		{
			a--;
			ans++;
		}
		if(b)
		{
			b--;
			ans++;
		}
		if(c)
		{
			c--;
			ans++;
		}
		if(a&&b)
		{
			a--;
			b--;
			ans++;
		}
		if(a&&c)
		{
			a--;
			c--;
			ans++;
		}
		if(b&&c)
		{
			b--;
			c--;
			ans++;
		}
		if(a&&b&&c)
			ans++;
		printf("%d\n",ans);
	}
	return 0;
}