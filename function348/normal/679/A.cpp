#include<cstdio>
#include<iostream>
using namespace std;
int chk(int x)
{
	printf("%d\n",x);
	fflush(stdout);
	char s[10];
	scanf("%s",s);
	return s[0]=='y';
}
int main()
{
	int p1=chk(2),p2=chk(3),p3=chk(5),p4=chk(7);
	if (p1+p2+p3+p4==0) { printf("prime\n");return 0;}
	if (p1+p2+p3+p4>=2) { printf("composite\n");return 0;}
	if (chk(4)+chk(9)+chk(25)+chk(49)>=1) { printf("composite\n");return 0;}
	for (int i=11;i<=50;i++)
	{
		int f=1;
		for (int j=2;j*j<=i;j++)
		if (i%j==0) f=0;
		if (f) 
		if (chk(i)) 
		{
			printf("composite\n");
			return 0;
		}
	}
	printf("prime\n");
	return 0;
}