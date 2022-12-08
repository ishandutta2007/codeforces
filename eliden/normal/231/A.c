#include<stdio.h>
int n, x, y, z, t;
int main()
{
    scanf("%i",&n);
    for(int i=0;i<n;i++)
    {
	scanf("%i%i%i",&x,&y,&z);
	if(x+y+z>=2)
	    t++;
    }
    printf("%i\n",t);
}