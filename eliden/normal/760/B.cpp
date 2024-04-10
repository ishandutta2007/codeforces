#include<stdio.h>
long long n, m, k;
long long sum(long long a, long long b)
{
    b*=b+1;
    b/=2;
    a*=a-1;
    a/=2;
    return b-a;
}
int main()
{
    scanf("%lli%lli%lli",&n,&m,&k);
    long long l=1, r=m;
    while(l<r)
    {
	long long mid = r-(r-l)/2;

	long long sup = m-n;
	long long fro = mid-1;

	long long lr = k-1;
	long long rr = n-k;
	if(lr>=fro)
	    lr = fro-1;
	if(rr>=fro)
	    rr = fro-1;
	
	{    
	    if(lr>0)
		sup-=sum(fro-lr,fro-1);
	    if(rr>0)
		sup-=sum(fro-rr,fro-1);
	    sup-=fro;

	    //printf("%i: %i %i %lli\n",mid,lr,rr,sup);
	}
	
	if(sup>=0)
	    l = mid;
	else
	    r = mid-1;
    }
    printf("%lli\n",l);
}