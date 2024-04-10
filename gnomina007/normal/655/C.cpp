#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include <cstdio>
#include<cmath>
#include <string>
using namespace std;
long long i, j, x, ans, cur, n, k, lb, rb, mid, ls[100005], rs[100005];
char a[100005];
int main()
{
	cin>>n>>k;
	for(i=0; i<n; i++)
	{
		cin>>a[i];
	}
	lb=1;
	rb=n-1;
	for(j=0; j<50; j++)
	{
		mid=(rb+lb+j%2)/2;
		ls[0]=0;
		for(i=1; i<=mid; i++)
		{
			ls[i]=ls[i-1]+1-(a[i-1]-'0');
		}
		for(i=mid+1; i<n; i++)
		{
			ls[i]=ls[i-1]+(1-(a[i-1]-'0'))-((1-(a[i-mid-1]-'0')));
		}
		rs[n-1]=0;
		for(i=1; i<=mid; i++)
		{
			rs[n-1-i]=rs[n-i]+1-(a[n-i]-'0');
		}
		for(i=mid+1; i<n; i++)
		{
			rs[n-1-i]=rs[n-i]+(1-(a[n-i]-'0'))-((1-(a[n-i+mid]-'0')));
		}
		cur=0;
		for(i=0; i<n; i++)
		{
			if(a[i]=='0')
			{
				if(ls[i]+rs[i]>=k)
				{
					cur++;
				}
			}
		}
		if(cur>0)
		{
			rb=mid;
		}
		else
		{
			lb=mid;
		}
	}
	cout<<mid;
}