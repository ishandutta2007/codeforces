#include<stdio.h>
int n, m, a[100], b[101],l,r;
int main()
{
    scanf("%i%i",&n,&m);
    b[0] = 0;
    for(int i=0;i<n;i++)
    {
	scanf("%i",a+i);
	b[i+1] = a[i]+b[i];
    }
    int sum = 0;
    for(int i=0;i<m;i++)
    {
	scanf("%i%i",&l,&r);
        if(b[r]-b[l-1]>0)
	    sum+=b[r]-b[l-1];
    }
    printf("%i\n",sum);
}