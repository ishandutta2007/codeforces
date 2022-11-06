#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1000010
using namespace std;
int gcd(int x,int y){return y==0?x:gcd(y,x%y);}
int num[27];
int main()
{
	int n;
	scanf("%d",&n);
	int g=0;
	int cnt=-1;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
		g=gcd(g,num[i]);
		if(num[i]&1) cnt=(cnt==-1?i:-2);
	}
	if(cnt==-2)
	{
		puts("0");
		for(int i=0;i<n;i++)
			for(int j=1;j<=num[i];j++) putchar('a'+i);
		return 0;
	}
	printf("%d\n",g);
	for(int i=0;i<n;i++) num[i]/=g;
	if(cnt==-1)
	{
		for(int i=1;i<=g/2;i++)
		{
			for(int j=0;j<n;j++)
				for(int k=1;k<=num[j];k++)
					putchar('a'+j);
			for(int j=n-1;j>=0;j--)
				for(int k=1;k<=num[j];k++)
					putchar('a'+j);
		}
		return 0;
	}
	else
	{
		for(int i=1;i<=g;i++)
		{
			for(int j=0;j<n;j++)
			if(j!=cnt)
				for(int k=1;k<=num[j]/2;k++)
				putchar('a'+j);
			for(int k=1;k<=num[cnt];k++) putchar('a'+cnt);
			for(int j=n-1;j>=0;j--)
			if(j!=cnt)
				for(int k=1;k<=num[j]/2;k++)
				putchar('a'+j);
		}
	}
	return 0;
}