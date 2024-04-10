#include <iostream>
#include <stdio.h>;
#include <vector>;
#include <algorithm>;
using namespace std;
int __cdecl sravni(const void *a, const void *b)
{
	const long long *i1= (const long long*) a;
	const long long *i2= (const long long*) b;
	return *i1 - *i2;
}
long long n, x, t[120000], i, sum, f[120000];
int main()
{
	cin>>n>>x;
	sum=0;
	for(i=0; i<n; i++)
	{
		cin>>t[i];
	}
	qsort(t,n,sizeof(long long), sravni);
	for(i=0; i<n; i++)
	{
		if(x-i>1)
		{
		    sum=sum+t[i]*(x-i);
		}
		else
		{
			sum=sum+t[i];
		}
	}
	cout<<sum;

}