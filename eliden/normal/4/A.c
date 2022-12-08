#include<stdio.h>
int x;
int main()
{
    scanf("%i",&x);
    if(x>=4 && x%2==0)
	printf("YES\n");
    else
	printf("NO\n");
}