#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include <cstdio>
#include<cmath>
using namespace std;
long long n, i, j, d1[505][505], d2[505][505], b[505], k, ans;
int main()
{
	cin>>n;
	for(i=0; i<n; i++)
	{
		cin>>b[i];
	}
	for(i=0; i<n; i++)
	{
		d1[i][i+1]=1;
		d2[i][i+1]=1;
	}
	for(j=2; j<=n; j++)
	{
		for(i=0; i+j<=n; i++)
		{
		    ans=999999;
			for(k=1; k<j; k++)
			{
				ans=min(ans, d1[i][i+k]+d1[i+k][i+j]);
			}
			if(b[i]!=b[i+j-1])
			{
				d1[i][i+j]=ans;
				d2[i][i+j]=9999999;
			}
			else
			{
				d2[i][i+j]=d1[i+1][i+j-1];
				if(j==2)
				{
					d2[i][i+j]++;
				}
				//cout<<d2[i][i+j]<<' '<<999<<endl;
			}
			d1[i][i+j]=min(ans,d2[i][i+j]);
		}
	}
	//cout<<d1[4][6]<<endl;
	cout<<d1[0][n]<<endl;
}