#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include <cstdio>
#include<cmath>
#include <string>
using namespace std;
char buffer[2048];
long long x, x1, s, i, sum, dva[100], j, a, b, ans;
int main()
{
	cin>>a>>b;
	dva[0]=1;
	for(i=1; i<=61; i++)
	{
		dva[i]=dva[i-1]*2;
	}
	for(i=1; i<=61; i++)
	{
		for(j=0; j+1<i; j++)
		{
			if((dva[i]-dva[j]-1)>=a)
			{
				if((dva[i]-dva[j]-1)<=b)
				{
					ans++;
				}
			}
		}
	}
	cout<<ans;
}