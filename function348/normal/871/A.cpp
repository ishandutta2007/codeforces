#include<cstdio>
#include<iostream>
using namespace std;
int cas;
int main()
{
	scanf("%d",&cas);
	while (cas--)
	{
		int x;scanf("%d",&x);
		if (x%2==0)
		{
			if (x==2) printf("-1\n");
			else printf("%d\n",x/4);
		}
		if (x%4==1)
		{
			if (x>=9) printf("%d\n",(x-9)/4+1);
			else printf("-1\n");
		}
		if (x%4==3)
		{
			if (x>=15) printf("%d\n",(x-15)/4+2);
			else printf("-1\n");
		}
	}
	return 0;
}