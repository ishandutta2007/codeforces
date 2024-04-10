#include<cstdio>

using namespace std;

int n,i,j;

int main()
{
	scanf("%d",&n);
	printf("%d\n",(n/2)*(n-n/2));
	for(i=1;i<=n/2;++i)
		for(j=n/2+1;j<=n;++j)
			printf("%d %d\n",i,j);
}