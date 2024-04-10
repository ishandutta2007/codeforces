#include <iostream>
#include <vector>
#include<cmath>
#include<stdio.h>
using namespace std;
long long n,  i, j,  k, dyn[2005][17], c[2205][2205], l, s[17], mod, ans;
int main()
{
	mod=1000000007;
	cin>>n>>k;
	for(i=1; i<=n; i++)
	{
		dyn[i][1]=1;
		if(i!=1)
		{
			dyn[i][2]=1;
		}
		for(l=2; l<=15; l++)
		{
			for(j=2; j*j<=i; j++)
			{
				if((i%j)==0)
				{
					dyn[i][l]=(dyn[j][l-1]+dyn[(i/j)][l-1]+dyn[i][l])%mod;;
				}
				if((j*j)==i)
				{
					dyn[i][l]=(dyn[i][l]-dyn[j][l-1]+mod)%mod;
				}
			}
		}
	}
	for(i=1; i<=15; i++)
	{
		for(j=1; j<=n; j++)
		{
			s[i]=(s[i]+dyn[j][i])%mod;
		}
	}
	c[0][0]=1;
	c[0][1]=1;
	c[1][1]=1;
	for(j=2; j<=2200; j++)
	{
		c[j][1]=0;
	}
	for(j=1; j<=2200; j++)
	{
		c[0][j]=1;
	}
	for(i=2; i<=2200; i++)
	{
		for(j=1; j<=2200; j++)
		{
			if(j>i)
			{
				c[j][i]=0;
			}
			else
			{
				c[j][i]=(c[j][i-1]+c[j-1][i-1])%mod;
			}
		}
	}

	for(i=1; i<=15; i++)
	{
		ans=(ans+c[i-1][k-1]*s[i])%mod;
	}
	cout<<ans%mod;
}