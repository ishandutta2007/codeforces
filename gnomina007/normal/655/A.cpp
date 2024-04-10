#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include <cstdio>
#include<cmath>
#include <string>
using namespace std;
char a[10], b[10];
long long i, j, x, ans, cur;
int main()
{
	for(i=0; i<4; i++)
	{
		cin>>a[i];
	}
	for(i=0; i<4; i++)
	{
		cin>>b[i];
	}
	for(i=0; i<100; i++)
	{
		cur=0;
		for(j=0; j<4; j++)
		{
			if(a[j]==b[j])
			{
				cur++;
			}
			if(cur==4)
			{
				ans++;
			}
		}
		if(a[0]=='X')
		{
			x=a[1];
			a[1]='X';
			a[0]=x;
		}
		else
		{
			if(a[1]=='X')
		    {
			    x=a[3];
			    a[3]='X';
			    a[1]=x;
		    }
			else
			{
				if(a[3]=='X')
		        {
			        x=a[2];
			        a[2]='X';
			        a[3]=x;
		        }
				else
				{
					x=a[0];
					a[0]='X';
					a[2]=x;
				}
			}
		}
	}
	if(ans>0)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}

}