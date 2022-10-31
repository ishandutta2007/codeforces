#include <iostream>;
#include <cmath>;
#include <vector>;
#include <stdio.h>;
#include <algorithm>;
using namespace std;
int __cdecl sravni(const void *a, const void *b)
{
	const long long *i1= (const long long*) a;
	const long long *i2= (const long long*) b;
	return *i1 - *i2;
}

long long a, b, c[100], i, n, x, sum, ans, m, k, v[4100], v1[4100], jy[4100], s1, s2;
int main()
{
	cin>>x>>k;
	for(i=0; i<k; i++)
	{
		cin>>n;
		if(n==1)
		{
			cin>>v[i];
			cin>>v1[i];
			jy[i]=v[i]*4100+v1[i];
		}
		else
		{
			cin>>v[i];
			v1[i]=v[i];
			jy[i]=v[i]*4100+v1[i];
		}
	}
	qsort(jy,k,sizeof(long long), sravni);
	v[0]=0;
	v1[0]=0;
	for(i=1; i<=k; i++)
	{
		v[i]=jy[i-1]/4100;
		v1[i]=jy[i-1]-v[i]*4100;
	}
	v[k+1]=x;
	v1[k+1]=x;
	s1=0;
	s2=0;
	for(i=0; i<=k; i++)
	{
		s1=s1+(v[i+1]-v1[i]-1);
		s2=s2+(v[i+1]-v1[i])/2;
	}
	cout<<s2<<' '<<s1;
}