#include <iostream>;
#include <stdio.h>;
#include <vector>;
#include <string>;
#include <algorithm>;
using namespace std;

/*int __cdecl sravni(const void *a, const void *b)
{
	const long long *i1= (const long long*) a;
	const long long *i2= (const long long*) b;
	return *i1 - *i2;
}*/



	//qsort(a,n,sizeof(long long), sravni);
//sort(a, a+n);
long long n , k, a[3002], b[3002], c[102], i, j, kp, oi, otv, m, bl1, bl2;
int main()
{
	cin>>n>>m>>k;
	for(i=0; i<n; i++)
	{
		cin>>a[i];
		if(a[i]==1)
		{
			bl1++;
		}
		else
		{
			bl2++;
		}
	}
	if(m>=n)
	{
		cout<<0;
	}
	else
	{
		kp=n-m;
		kp=min(kp, bl2);
		oi=min(k, kp);
		otv=n-m-oi;
		cout<<otv;
	}


	return 0;
}