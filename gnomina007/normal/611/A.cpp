#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include <cstdio>
#include<cmath>
#include <string>
using namespace std;
char buffer[2048];
long long x, x1, s, i, sum;
int main()
{
	gets(buffer);
	for(i=0; i<100; i++)
	{
		if(x==0)
		{
			if(buffer[i]!=' ')
			{
				sum=sum*10+buffer[i]-'0';
			}
		}
		if(x==2)
		{
				   if(buffer[i]=='h')
				   {
					   x1=1;
				   }
				   if(buffer[i]=='k')
				   {
					   x1=2;
				   }
		}
		if(buffer[i]==' ')
		{
			x++;
		}
	}
	//cout<<x1<<endl;
	//cout<<sum;
	if(x1==2)
	{
		if(sum==5)
		{
			cout<<53;
		}
		if(sum==6)
		{
			cout<<53;
		}
		if(sum%7<5)
		{
			cout<<52;
		}
	}
	else
	{
		if(sum==30)
		{
			cout<<11;
		}
		if(sum==31)
		{
			cout<<7;
		}
		if(sum<30)
		{
			cout<<12;
		}
	}
}