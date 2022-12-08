#include<stdio.h>
const int sz = 200000;
int a,b, n;
char s[sz];
int main()
{
    scanf("%i%i%i",&n,&a,&b);
    a--;
    b--;
    scanf("%s",s);
    if(s[a]==s[b])
	printf("0\n");
    else
	printf("1\n");
}