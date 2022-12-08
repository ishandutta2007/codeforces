#include<stdio.h>
const int sz = 1000000;
int n, t[sz], dp[sz];
int main()
{
    scanf("%i",&n);
    for(int i=0;i<n;i++)
	scanf("%i",&t[i]);

    for(int i=0;i<n;i++)
    {
	if(i==0)
	    dp[i] = 20;
	else
	{
	    dp[i] = 20+dp[i-1];
	    int l = -1, r=i-1;
	    while(l<r)
	    {
		int mid = r-(r-l)/2;
		if(t[mid]<t[i]-89)
		    l = mid;
		else
		    r = mid-1;
	    }
	    int can = 50;
	    if(l>=0)
		can+=dp[l];
	    if(can<dp[i])
		dp[i] = can;
	    l = -1, r=i-1;
	    while(l<r)
	    {
		int mid = r-(r-l)/2;
		if(t[mid]<t[i]-1439)
		    l = mid;
		else
		    r = mid-1;
	    }
	    can = 120;
	    if(l>=0)
		can+=dp[l];
	    if(can<dp[i])
		dp[i] = can;
	}
    }
    // printf("\n");
    // for(int i=0;i<n;i++)
    // 	printf("%i\n",dp[i]);
    int sum = 0;
    for(int i=0;i<n;i++)
    {
	if(i==0)
	{
	    sum+=dp[i];
	    printf("%i\n",dp[i]);
	}
	else
	{
	    printf("%i\n",dp[i]-sum);
	    sum+=dp[i]-sum;
	}
    }
}