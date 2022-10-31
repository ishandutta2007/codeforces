#include<cstdio>
#include<iostream>
using namespace std;
int x;
char s[10];
int main()
{
	scanf("%d",&x);
	scanf("%s",s);
	scanf("%s",s);
	if (s[0]=='w')
	{
		int now=5,cnt=0;
		for (int i=1;i<=366;i++)
		{
			if (now==x) cnt++;
			now++;
			if (now==8) now=1;
		}
		printf("%d\n",cnt);
	}
	else
	{
		if (x<=29) printf("12\n");else
		if (x<=30) printf("11\n");else
		printf("7\n");
	}
	return 0;
}