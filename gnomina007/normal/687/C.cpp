#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include <cstdio>
#include<cmath>
#include <string>
using namespace std;
int n, b[505], dyn[4][505][505], ans,i, j, k, h, a1, a2, a3;
int main()
{
	cin>>n>>k;
	for(i=0; i<n; i++)
	{
		cin>>b[i];
	}
	dyn[0][0][0]=1;
	for(i=1; i<=n; i++)
	{
		for(j=0; j<=k; j++)
		{
			for(h=0; h<=k; h++)
			{
				a1=0;
				a2=0;
				a3=0;
				a1=dyn[(i-1)%2][j][h];
				if(j>=b[i-1])
				{
				    a2=dyn[(i-1)%2][j-b[i-1]][h];
				}
				if(h>=b[i-1])
				{
			    	a3=dyn[(i-1)%2][j][h-b[i-1]];
				}
				a1=max(a1, a2);
				a1=max(a1, a3);
				dyn[i%2][j][h]=a1;
			}
		}
	}
	for(j=0; j<=k; j++)
	{
		if(dyn[n%2][j][k-j]==1)
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	for(j=0; j<=k; j++)
	{
		if(dyn[n%2][j][k-j]==1)
		{
			cout<<j<<' ';
		}
	}
}