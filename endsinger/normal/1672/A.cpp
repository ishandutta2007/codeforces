#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,s=0,x;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			s+=x-1;
		}
		if(s&1)
			puts("errorgorn");
		else
			puts("maomao90");
	}
	return 0;
}