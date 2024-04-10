#include<stdio.h>
int n, a, b, c;
long long aa, bb, cc;
int min(long long x, long long y)
{
    if(x<y)
	return (int) x;
    else
	return (int) y;
}
int main()
{
    scanf("%i%i%i%i",&n,&a,&b,&c);
    aa = a;
    bb = b;
    cc = c;
    if(n%4==0)
	printf("0\n");
    else if(n%4==1)
	printf("%i\n",min(min(cc,3*aa),aa+bb));
    else if(n%4==2)
	printf("%i\n",min(min(bb,2*aa),2*cc));
    else if(n%4==3)
	printf("%i\n",min(min(aa,bb+cc),3*cc));
	
}