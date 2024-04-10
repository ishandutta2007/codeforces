#include<stdio.h>
const int sz = 100003;
int n, x, a;
long long sum, b[100003];;
int main()
{
    for(int i=0;i<sz;i++)
	b[i]=0;
    scanf("%i%i",&n,&x);
    for(int i=0;i<n;i++)
    {
	scanf("%i",&a);
	b[a]++;
    }
    sum = 0;
    for(int i=0;i<sz;i++)
	if(b[i]>0)
	{
	    int j = x^i;
	    if(j<sz && b[j]>0)
	    {
		if(i!=j)
		    sum+=b[i]*b[j];
		else
		    sum+=b[i]*(b[i]-1)/2;
		b[j]=0;
	    }
	    b[i]=0;
	}
    printf("%lli\n",sum);
}