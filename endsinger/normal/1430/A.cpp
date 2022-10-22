#include<bits/stdc++.h>
using namespace std;
void sol()
{
	int n;
	scanf("%d",&n);
	if(n==1||n==2||n==4)
	{
		puts("-1");
		return;
	}
	if(n==7)
	{
		puts("0 0 1");
		return;
	}
	for(int i=0;;i++)
	{
		if((n-i*3)%5==0)
		{
			printf("%d %d 0\n",i,(n-i*3)/5);
			return;
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}