#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,x=0,c=0;
		scanf("%d",&n);
		for(int i=1;;i++)
		{
			x+=i;
			c++;
			if(x>=n)
				break;
		}
		if(x==n+1)
			c++;
		printf("%d\n",c);
	}
	return 0;
}