#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include <cstdio>
#include<cmath>
using namespace std;
long long n, i, j, d1[505][505], d2[505][505], b[100005], k, ans, a[100005], dyn[100005], lb, rb, mid, rage[100005];
int main()
{
	cin>>n;
	for(i=0; i<n; i++)
	{
		cin>>a[i]>>b[i];
		rage[i]=a[i]*99999999+b[i];
	}
	sort(rage, rage+i);
	for(i=0; i<n; i++)
	{
		a[i]=rage[i]/99999999;
		b[i]=rage[i]%99999999;
	}
	dyn[0]=0;
	dyn[1]=1;
	for(i=2; i<=n; i++)
	{
		lb=0;
		rb=i-1;
		if(a[0]+b[i-1]<a[i-1])
		{
			if(a[i-2]+b[i-1]>=a[i-1])
			{
		for(j=0; j<40; j++)
		{
			mid=(lb+rb+j%2)/2;
			if(a[mid]+b[i-1]<a[i-1])
			{
				lb=mid;
			}
			else
			{
				rb=mid-1;
			}
		}
			}
			else
			{
				mid=i-2;
			}
		}
		else
		{
			mid=-1;
		}
		dyn[i]=dyn[mid+1]+1;
	}
	ans=99999999;
	for(i=0; i<=n; i++)
	{
		ans=min(ans, n-dyn[i]);
	}
	//cout<<dyn[7]<<endl;
	cout<<ans;

}