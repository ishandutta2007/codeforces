#include <iostream>;
#include <stdio.h>;
#include <vector>;
#include <cmath>
#include <string>
#include <algorithm>;
using namespace std;
int __cdecl sravni(const void *a, const void *b)
{
	const long long *i1= (const long long*) a;
	const long long *i2= (const long long*) b;
	return *i1 - *i2;
}
long long n, x, a[120000], i, sum, b[120000], p, k, c[120000], h, u, m, lev, prav, mid, s1, s2, ans, j;
int main()
{
	cin>>n>>m;
	for(i=0; i<n; i++)
	{
		cin>>a[i];
	}
	for(i=0; i<m; i++)
	{
		cin>>b[i];
	}
	lev=0;
	prav=1000000009;
	ans=0;
	for(j=0; j<=70; j++)
	{
		mid=(lev+prav+j%2)/2;
		s1=0;
		s2=0;
		for(i=0; i<n; i++)
		{
			if(a[i]<=mid)
			{
				s1=s1+1;
			}
		}
		for(i=0; i<m; i++)
		{
			if(b[i]>mid)
			{
				s2=s2+1;
			}
		}
		if(s2>s1)
		{
			lev=mid+1;
		}
		else
		{
			prav=mid;
		}
	}
	for(i=0; i<n; i++)
	{
		if(a[i]<mid)
		{
			ans=ans+mid-a[i];
		}
	}
	for(i=0; i<m; i++)
	{
		if(b[i]>mid)
		{
			ans=ans+b[i]-mid;
		}
	}
	cout<<ans;
}