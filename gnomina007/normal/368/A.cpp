#include <iostream>;
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

long long n, m,i, w[100005],sum, d, a[105];
int main()
{
	cin>>n>>d;
	for(i=0; i<n; i++)
	{
		cin>>a[i];
	}
	cin>>m;
	sum=0;
	qsort(a,n,sizeof(long long), sravni);
	if(n>=m)
	{
		for(i=0; i<m; i++)
		{
			sum=sum+a[i];
		}
	}
	else
	{
		for(i=0; i<n; i++)
		{
			sum=sum+a[i];
		}
		sum=sum-d*(m-n);
	}
	cout<<sum;


	return 0;
}