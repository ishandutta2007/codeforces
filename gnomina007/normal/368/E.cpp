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

long long n, m,i, q[100005], w[100005], s[100005], sum;
int main()
{
	cin>>n>>m;
	for(i=0; i<m; i++)
	{
		cin>>q[i]>>w[i];
	}
	qsort(w,m,sizeof(long long), sravni);
	sum=0;
	for(i=0; i<m; i++)
	{
		if((i+1)%2==0)
		{
			if((((i+1)*(i+1))/2)<=n)
			{
				sum=sum+w[m-1-i];
			}
		}
		else
		{
			if((((i*(i+1))/2)+1)<=n)
			{
				sum=sum+w[m-1-i];
			}
		}
	}
	cout<<sum;
	return 0;
}