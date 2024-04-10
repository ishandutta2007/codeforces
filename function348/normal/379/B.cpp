#include<cstdio>
#include<iostream>
using namespace std;
int n,x;
int main()
{
	scanf("%d",&n);
	scanf("%d",&x);
	if (x!=0) printf("P");
	for (int i=2;i<=x;i++) printf("RLP");
	for (int i=2;i<=n;i++)
	{
		scanf("%d",&x);
		printf("R");
		if (x!=0) printf("P");
		for (int j=2;j<=x;j++) printf("LRP");
	}
	return 0;
}