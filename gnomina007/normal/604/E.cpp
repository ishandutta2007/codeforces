#include<iostream>
#include<vector>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
long long  stmod(long long a, long long b, long long p)
{
	int x;
	if(b==0)
	{
		return 1;
	}
	else
	{
		if(b%2==0)
		{
			x=stmod(a, b/2, p);
			x=(x*x)%p;
			return x;
		}
		else
		{
			x=stmod(a, b-1, p);
			x=(x*a)%p;
			return x;
		}
	}
}
long long n, m, k,a[100005], i, sum, sum1, sum2, baze, t, x;
int main()
{ 
	cin>>n>>k;
	for(i=0; i<n; i++)
	{
		cin>>a[i];
	}
	if(k%2==0)
	{
		sum1=0;
		sum2=0;
		for(i=0; i<n; i++)
		{
			if(a[i]==1)
			{
				sum1++;
			}
			if(a[i]==2)
			{
				sum2++;
			}
			if(a[i]>2)
			{
				if((a[i]%2)==0)
				{
					sum1++;
				}
			}
		}
		sum=sum1%2+sum2%2;
		if(sum==0)
		{
			cout<<"Nicky";
		}
		else
		{
			cout<<"Kevin";
		}
	}
	else
	{
		for(i=0; i<n; i++)
		{
			if(a[i]==1)
			{
				sum1++;
			}
			if(a[i]==3)
			{
				sum1++;
			}
			if(a[i]>3)
			{
				x=a[i];
				t=0;
				while(x%2==0)
				{
					x=x/2;
					t++;
				}
				baze=x;
				if(baze==3)
				{
					if(t%2==0)
					{
						sum1++;
					}
					else
					{
						sum2++;
					}
				}
				else
				{
					if(t%2==1)
					{
						sum1++;
					}
					else
					{
						if(t>0)
						{
							sum2++;
						}
					}
				}
			}
		}
		sum=sum1%2+sum2%2;
		if(sum==0)
		{
			cout<<"Nicky";
		}
		else
		{
			cout<<"Kevin";
		}

	}

}