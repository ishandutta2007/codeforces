#include<stdio.h>
const int sz = 1001, w=8;
int n, a[sz], dp[sz][1<<w], next[w][sz], block[w][sz][sz];
bool dy[w];
int main()
{
    scanf("%i",&n);
    for(int i=0;i<n;i++)
    {
	scanf("%i",&a[i]);
	a[i]--;
    }
    for(int i=0;i<w;i++)
	next[i][n] = -1;
    for(int i=n-1;i>=0;i--)
    {
	for(int j=0;j<w;j++)
	    next[j][i] = next[j][i+1];
	next[a[i]][i] = i+1;
    }
    for(int j=0;j<w;j++)
	for(int i=0;i<n;i++)
	{
	    int p = i;
	    for(int k=0;k<=n;k++)
	    {
		block[j][i][k] = p;
		if(p>=0 && p<n)
		    p = next[j][p];
		else
		    p = -1;
	    }
	}
    // for(int j=0;j<w;j++)
    // {
    // 	for(int i=0;i<n;i++)
    // 	    printf("%i ",block[j][0][i]);
    // 	printf("\n");
    // }
    //printf("%i\n",0&8);
    int best = 0;
    for(int l=0;l<=n/8;l++)
    {
	for(int i=0;i<=n;i++)
	{
	    dp[i][0] = 0;
	    for(int s=1;s<(1<<w);s++)
		dp[i][s] = -1;
	}
	for(int i=0;i<=n;i++)
	    for(int s=0;s<(1<<w);s++)
		if(dp[i][s]>=0)
		{
		    // if(s>0)
		    //  	printf("%i, %i: %i\n",i,s,dp[i][s]);
		    if(s==((1<<w)-1) && dp[i][s]>best)
			best = dp[i][s];
		    if(i<n)
			for(int k=0;k<w;k++)
			    if((s&(1<<k))==0)
			    {
				//printf("!%i",k);
				if(block[k][i][l]>=0)
				{
				    int x = dp[i][s] + l;
				    int s2 = s+(1<<k);
				    int i2 = block[k][i][l];
				    if(dp[i2][s2]<0 || x>dp[i2][s2])
					dp[i2][s2] = x;
				}
				if(block[k][i][l+1]>=0)
				{
				    int x = dp[i][s] + l+1;
				    int s2 = s+(1<<k);
				    int i2 = block[k][i][l+1];
				    if(dp[i2][s2]<0 || x>dp[i2][s2])
					dp[i2][s2] = x;
				}
			    }
		}
    }
    printf("%i\n",best);
}