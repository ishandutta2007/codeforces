#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include <cstdio>
#include<cmath>
#include <string>
using namespace std;
string a[1005];
int n, i,  j, cur, ans, k;
int main()
{
	cin>>n;
	for(i=0; i<n; i++)
	{
		cin>>a[i];
	}
	ans=6;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			if(i!=j)
			{
				cur=0;
				for(k=0; k<6; k++)
				{
					if(a[i][k]!=a[j][k])
					cur++;
				}
				ans=min(ans, (cur-1)/2);
			}
		}
	}
	cout<<ans;
}