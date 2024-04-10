#include<cstdio>
int main()
{
	int a,b,c,d;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	if(a!=d)
	{
		printf("0\n");
		return 0;
	}
	if(c)
	{
		if(a) printf("1\n");
		else printf("0\n");
		return 0;
	}
	printf("1\n");
	return 0;
}
//Dpair AK IOI
//Dpair bless me