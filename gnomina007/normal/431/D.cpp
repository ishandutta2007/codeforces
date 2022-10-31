#include <iostream>
#include <cmath>
#include<stdio.h>
#include <string>
#include <algorithm>
using namespace std;
long long c[100][100];
long long bin_pow (long long a, long long b)
{
	if(b==0)
	{
		return 1;
	}
	if(b%2!=0)
	{
		return (bin_pow(a, b-1)*a);
	}
	if(b%2==0)
	{
		return (bin_pow(a, b/2)*bin_pow(a,b/2));
	}
}
long long imbo (long long t, long long n, long long s)
{
	int i, j;
	c[0][0]=1;
	for(i=0; i<=90; i++)
	{
		for(j=0;j<=90; j++)
		{
			if(i<=j)
			{
				if(i==0)
				{
					c[i][j]=1;
				}
				if(j==i)
				{
					c[i][j]=1;
				}
				else
				{
					c[i][j]=c[i][j-1]+c[i-1][j-1];
				}
			}
		}
	}
	if(s==1)
	{
		return bin_pow(2, t)-1;
	}
	else
	{
		if(s<=c[t][n-1])
		{
			return imbo(t, n-1, s);
		}
		else
		{
			return imbo(t-1, n-1, s-c[t][n-1])+bin_pow(2, n-1);
		}
	}
}

long long  k, i, j, u[100], ans, maxi, sum, p, dyn1[500],dyn2[500], n, d, m;
int main()
{
	cin>>m>>k;
	if(m==0)
	{
		cout<<1;
	}
	else
	{
		if(k==1)
		{
			cout<<1;
		}
		else
		{
		   p=imbo(k-1, 64, m);
		   cout<<p+1;
		}
	}

}