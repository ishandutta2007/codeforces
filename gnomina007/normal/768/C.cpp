#include <iostream>;
#include <cmath>;
#include <vector>;
#include <stdio.h>;
#include <algorithm>;
#include <string>;
#include <set>;
using namespace std;
int n, k, x, a[100005], i, j, k1;
int main()
{
	cin>>n>>k>>x;
	k1=k%120;
	if(k>=120)
	{
		k1=k1+120;
	}
	for(i=0; i<n; i++)
	{
		cin>>a[i];
	}
	for(i=0; i<k1; i++)
	{
		sort(a, a+n);
		for(j=0; j<n; j++)
		{
			if(j%2==0)
			{
				a[j]=a[j]^x;
			}
		}
	}
	sort(a, a+n);
	cout<<a[n-1]<<' '<<a[0]<<endl;

}