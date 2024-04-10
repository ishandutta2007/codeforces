#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m=0;
		scanf("%d",&n);
		while(n)
		{
			m=max(m,n%10);
			n/=10;
		}
		printf("%d\n",m);
	}	
	return 0;
}