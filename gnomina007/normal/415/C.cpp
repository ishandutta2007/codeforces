#include <iostream>
#include <vector>
#include<cmath>
#include<stdio.h>
using namespace std;
long long n, m, x[130000], i, j,  pt, a, b, gcd, a1, b1, lb , pb, mid, k;
int main()
{
	cin>>n>>k;
	if(k<(n/2))
	{
		cout<<-1;
	}
	else
	{
		if(n==1)
		{
			if(k==0)
			{
				cout<<1;
			}
			else
			{
				cout<<-1;
			}
		}
		else
		{
			pt=n/2;
			mid=k-pt+1;
			cout<<k-pt+1<<' '<<(k-pt+1)*2<<' ';
			for(i=1; i<=n-2; i++)
			{
				cout<<(k-pt+1)*2+i<<' ';
			}
		}
	}



	
}