#include<stdio.h>
using namespace std;
int main()
{
	char a[105];
	int ans;
	scanf("%s",a);
	printf("%c",a[0]);
	int i,flag=0;
	for(int i=1;a[i+1];i++)
	{
		if(a[i+3]&&a[i]=='d'&&a[i+1]=='o'&&a[i+2]=='t')
		{
			printf(".");
			i+=2;
		}
		else if(a[i+2]&&a[i]=='a'&&a[i+1]=='t'&&flag==0)
	{
		flag=1;
		printf("@");
		i++;
	}
	else
	printf("%c",a[i]);
	ans=i;
	}
	printf("%c\n",a[ans+1]);
	return 0;
}