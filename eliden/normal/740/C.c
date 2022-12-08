#include<stdio.h>
int n, m, mex, l, r;
int main()
{
    scanf("%i%i",&n,&m);
    mex = n;
    for(int i=0;i<m;i++)
    {
	scanf("%i%i",&l,&r);
	if(r-l+1<mex)
	    mex=r-l+1;
    }
    printf("%i\n",mex);
    for(int i=0;i<n;i++)
	printf("%i ",i%mex);
    printf("\n");
}