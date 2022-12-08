#include<stdio.h>
#include<stdbool.h>
char a[300],b[300];
int main()
{
    scanf("%s",a);
    int i=0, j=0;
    char vowels[12] =
	{'a','A','e','E','i','I','o','O','u','U','y','Y'};
    while(a[i]!=0)
    {
	bool vowel = false;
	for(int k=0;k<12 && !vowel;k++)
	    if(a[i]==vowels[k])
		vowel = true;
	if(!vowel)
	{
	    b[j]='.';
	    j++;
	    if('A'<=a[i] && a[i]<='Z')
	    {
		b[j]=a[i]+'a'-'A';
	    }
	    else
		b[j]=a[i];
	    j++;
	}
	i++;
    }
    b[j] = 0;
    printf("%s\n",b);
}