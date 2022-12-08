#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	if(n<6)puts("-1");
	else
	{
		puts("4 2");
		puts("4 3");
		for(int i=4;i<=n;i++)
			printf("%d %d\n",1,i);
	}
	for(int i=2;i<=n;i++)
		printf("%d %d\n",i-1,i);
	return 0;
}