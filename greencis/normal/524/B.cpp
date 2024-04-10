#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <queue>
#include <algorithm>
#include <stdlib.h> 
#include <iomanip>
//#pragma comment(linker, "/STACK:99999999999")
using namespace std;






int main()
{
	/*ifstream cin("input.txt");
    ofstream cout("output.txt");*/
	long long n;
	cin>>n;
	vector <pair <long long,long long > > a(n);
	for (long long i=0;i<n;i++)
	{
		long long x1,x2;
		cin>>x1>>x2;
		if (x1>x2)
			swap(x1,x2);
		a[i].first=x1;
		a[i].second=x2;
	}
	long long ans=2e15;
	for (long long i=0;i<n;i++)
	{
		long long mh=a[i].first;
		long long f=0;
		long long ff=a[i].second;
		for (long long j=0;j<n;j++)
		{
			if (i!=j)
			{
				if (a[j].first<a[j].second)
				{
					if (a[j].second<=mh)
					{
						ff+=a[j].first;
					}
					else
					{
						if (a[j].first<=mh)
						{
							ff+=a[j].second;
						}
						else
						{
							f=1;
						}
					}
				}
				else
				{
					if (a[j].first<=mh)
					{
						ff+=a[j].second;
					}
					else
					{
						if (a[j].second<=mh)
						{
							ff+=a[j].first;
						}
						else
						{
							f=1;
						}
					}
				}
			}
		}
		if (f==0)
		{
			ans=min(ans,mh*ff);
		}
	}
	for (long long i=0;i<n;i++)
	{
		long long mh=a[i].second;
		long long f=0;
		long long ff=a[i].first;
		for (long long j=0;j<n;j++)
		{
			if (i!=j)
			{
				if (a[j].first<a[j].second)
				{
					if (a[j].second<=mh)
					{
						ff+=a[j].first;
					}
					else
					{
						if (a[j].first<=mh)
						{
							ff+=a[j].second;
						}
						else
						{
							f=1;
						}
					}
				}
				else
				{
					if (a[j].first<=mh)
					{
						ff+=a[j].second;
					}
					else
					{
						if (a[j].second<=mh)
						{
							ff+=a[j].first;
						}
						else
						{
							f=1;
						}
					}
				}
			}
		}
		if (f==0)
		{
			ans=min(ans,mh*ff);
		}
	}
	/*sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	
	for (long long i=0;i<n;i++)
	{
		long long f=0;
		long long ff=0;
		for (long long j=0;j<i;j++)
		{
			if (a[j].second>a[i].first)
			{
				f=1;
			}
			ff+=a[j].second;
		}
		if (f==0)
		{
			ff+=a[i].second;
			for (long long j=i+1;j<n;j++)
			{
				if (a[j].second<=a[i].first)
				{
					ff+=a[j].first;
				}
				else
				{
					ff+=a[j].second;
				}
				
			}
			ans=min(ans,ff*a[i].first);
		}
	}*/
	cout<<ans<<endl;

	
	return 0;
}