#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if (a<b) printf("-1\n");else
	if (a==b) printf("%d\n",a);else
	{
		int p1=trunc(1.0*(a-b)/b);
		int p2=trunc(1.0*(a+b)/b);
		if (p1&1) p1--;if (p2&1) p2--;
		printf("%.9lf\n",min(1.0*(a-b)/p1,1.0*(a+b)/p2));
	}
	return 0;
}