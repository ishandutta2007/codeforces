#include<stdio.h>
#include<algorithm>
using namespace std;
main()
{
	int a,b,m,n;
	while(scanf("%d %d %d %d",&n,&m,&a,&b)!=EOF)
	{
		printf("%d\n",min(n*a,min((n/m+1)*b,n/m*b+n%m*a)));
	} 
	return 0;
}