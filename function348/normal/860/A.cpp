#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int len,kd;
char s[30100];
int main()
{
	scanf("%s",s);
	int n=strlen(s);
	for (int i=0;i<n;i++)
	{
		if (s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u')
		{
			len++;
			if (len==1) kd=1;
			else if (s[i]!=s[i-1]) kd++;
			if (len>=3&&kd>=2) 
			{
				putchar(' ');
				len=kd=1;
			}
		} else len=kd=0;
		putchar(s[i]);
	}
}