#include<stdio.h>
#include<stdbool.h>
long long n;
int main()
{
    scanf("%lld",&n);
    int ans;
    if(n==2)
	ans = 1;
    else if(n==3)
	ans = 1;
    else if(n%2==0)
	ans = 2;
    else
    {
	bool prime = true;
	for(int i=2;i*i<=n;i++)
	    if(n%i==0)
		prime = false;
	if(prime)
	    ans = 1;
	else
	{
	    prime = true;
	    for(int i=2;i*i<=n-2;i++)
		if((n-2)%i==0)
		    prime = false;
	    if(prime)
		ans = 2;
	    else
		ans = 3;
	}
    }
    printf("%i\n",ans);
}