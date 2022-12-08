#include<stdio.h>
int m, d, inm[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
    scanf("%i%i",&m,&d);
    int x = inm[m-1];
    x-=8-d;
    int y = x/7;
    if(x>y*7)
	y++;
    printf("%i\n",1+y);
}