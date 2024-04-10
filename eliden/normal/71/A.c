#include<stdio.h>
char s[101];
int n, len;
int main()
{
    scanf("%i",&n);
    for(int i=0;i<n;i++)
    {
	scanf("%s",s);
	len = 0;
	for(int j=0;s[j]!=0;j++)
	    len++;
	if(len>10)
	    printf("%c%i%c\n",s[0],len-2,s[len-1]);
	else
	    printf("%s\n",s);
    }
}