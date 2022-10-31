#include <iostream>
#include <vector>
#include<cmath>
#include<stdio.h>
using namespace std;
long long n, m, x[130000], i, j,  pt, a, b, gcd, a1, b1, lb , pb, mid;
int main()
{
	cin>>n>>a>>b;
	for(i=1; i<=n; i++)
	{
		cin>>x[i];
	}
	for(i=1; i<=n; i++)
	{
		pt=(x[i]*a)/b;
		lb=0;
		pb=x[i];
		for(j=1; j<=35; j++)
		{
			mid=(lb+pb+j%2)/2;
			if(((mid*a)/b)==pt)
			{
				pb=mid;
			}
			else
			{
				lb=mid;
			}
		}
		cout<<x[i]-pb<<' ';
	}
}