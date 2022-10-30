#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include <cstdio>
#include<cmath>
#include <string>
using namespace std;
long long n, t[100], i, j, k, ans, cur;
int main()
{
	cin>>n;
	for(i=0;i<n; i++)
	{
		cin>>t[i];
	}
	for(i=0; i<n; i++)
	{
		for(j=i+1; j<n; j++)
		{
			for(k=j+1; k<n;k++)
			{
				cur=(t[i]-t[j])*(t[i]-t[k])*(t[j]-t[k]);
				cur=cur*cur;
				if(cur==4)
				{
					ans++;
				}
			}
		}
	}
	if(ans==0)
	{
		cout<<"NO";
	}
	else
	{
		cout<<"YES";
	}
}