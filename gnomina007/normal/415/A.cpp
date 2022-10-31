#include <iostream>
#include <vector>
#include<cmath>
#include<stdio.h>
using namespace std;
long long n, m, b[500], i, j, ans[500], pt;
int main()
{
	cin>>n>>m;
	for(i=1; i<=m; i++)
	{
		cin>>b[i];
	}
	for(i=1; i<=n; i++)
	{
		pt=0;
		for(j=1; j<=m; j++)
		{
			if(b[j]<=i)
			{
				if(pt==0)
				{
					pt++;
					cout<<b[j]<<' ';
				}
			}
		}
	}
}