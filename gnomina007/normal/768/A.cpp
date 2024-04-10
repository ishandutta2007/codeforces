#include <iostream>;
#include <cmath>;
#include <vector>;
#include <stdio.h>;
#include <algorithm>;
#include <string>;
#include <set>;
using namespace std;
int n, i, j, a[100005], c1, c2, ans;
int main()
{
	cin>>n;
	for(i=0; i<n; i++)
	{
		cin>>a[i];
	}
	sort(a, a+n);
	c1=a[0];
	c2=a[n-1];
	for(i=0; i<n; i++)
	{
		if(a[i]!=c1)
		{
			if(a[i]!=c2)
			{
				ans++;
			}
		}
	}
	cout<<ans;
}