#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include <cstdio>
#include<cmath>
#include <string>
using namespace std;
long long gcd(long long v, long long ew)
{
	long long ki;
	if(v>ew)
	{
		ki=v;
		v=ew;
		ew=ki;
	}
	if(v==0)
	{
		return ew;
	}
	else
	{
		ki=ew%v;
		return gcd(ki, v);
	}
}
long long n, a[30], i, tc, sc, j, lok, k, lok1;
char xxx;
int main()
{
	cin>>n;
	for(i=0; i<n; i++)
	{
		cin>>a[i];
		if(a[i]%2==1)
		{
			sc++;
			lok=i;
		}
	}
	if(sc>1)
	{
		cout<<0<<endl;
		for(j=0; j<n; j++)
		{
			for(i=0; i<a[j]; i++)
			{
				xxx='a'+j;
				cout<<xxx;
			}
		}
	}
	if(sc==1)
	{
		lok1=0;
		for(i=0; i<n; i++)
		{
			lok1=gcd(lok1, a[i]);
		}
		cout<<lok1<<endl;
		for(i=0; i<lok1; i++)
		{
			xxx=lok+'a';
			cout<<xxx;
			for(j=0; j<n; j++)
			{
				if(j!=lok)
				{
				for(k=0; k<(a[j]/(2*lok1)); k++)
				{
					xxx='a'+j;
					cout<<xxx;
				}
				}
				else
				{
				    for(k=0; k<(a[j]/(2*lok1)); k++)
				   {
					   xxx='a'+j;
					   cout<<xxx;
				    }
				}
			}
			for(j=n-1; j>=0; j--)
			{
				if(j!=lok)
				{
				for(k=0; k<(a[j]/(2*lok1)); k++)
				{
					xxx='a'+j;
					cout<<xxx;
				}
				}
				else
				{
					for(k=0; k<(a[j]/(2*lok1)); k++)
					{
						xxx='a'+j;
						cout<<xxx;
					}
				}
			}
		}
	}
	if(sc==0)
	{
		lok=0;
		for(i=0; i<n; i++)
		{
			lok=gcd(lok, a[i]);
		}
		cout<<lok<<endl;
		for(i=0; i<lok/2; i++)
		{
			for(j=0; j<n; j++)
			{
				for(k=0; k<(a[j]/lok); k++)
				{
					xxx='a'+j;
					cout<<xxx;
				}
			}
			for(j=n-1; j>=0; j--)
			{
				for(k=0; k<(a[j]/lok); k++)
				{
					xxx='a'+j;
					cout<<xxx;
				}
			}
		}
	}

}