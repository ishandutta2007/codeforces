#include<cstdio>
#include<iostream>
using namespace std;
int n;
int a[10];
char s[100010];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++) 
	{
		if (s[i]=='A') a[1]++;
		if (s[i]=='C') a[2]++;
		if (s[i]=='G') a[3]++;
		if (s[i]=='T') a[4]++;
	}
	int x1=0,x2=0;
	for (int i=1;i<=4;i++)
	{
			if (a[i]>x1) x1=a[i],x2=1;
			else if (a[i]==x1) x2++;
	}
	int x3=1;
	for (int i=1;i<=n;i++) x3=1LL*x3*x2%1000000007;
	printf("%d\n",x3);
	return 0;
}