#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<unistd.h>
#include<signal.h>
using namespace std;
char s[5],t[5];
int chk(char* a,char* b)
{
	return a[0]==b[0]||a[1]==b[1];
}
int main()
{
	scanf("%s",s);
	for (int i=1;i<=5;i++)
	{
		scanf("%s",t);
		if (chk(s,t)) 
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
}