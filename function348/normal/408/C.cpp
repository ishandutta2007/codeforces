#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
int main()
{
	int n,m,flag=0;
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++)
	{
		int j=(int)sqrt(n*n-i*i);
		if (j*j+i*i-n*n) continue;
		if (i*m%n) continue;
		if (j*m%n) continue;
		int k=i*m/n,l=j*m/n;
		if (j==k) continue;
		printf("YES\n");
		printf("%d %d\n",0,0);
		printf("%d %d\n",-i,j);
		printf("%d %d\n",l,k);
		flag=1;
		break;
	}
	if (!flag) printf("NO");
	return 0;
}