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
long long a[3002], b[3002], c[102], i, j, kp, oi, otv, m, bl1, bl2, n, l, k, r, sk, sall, a1, a2, a3, a4;
int main()
{
	cin>>n>>k>>l>>r>>sall>>sk;
	a1=sk/k;
	a2=sk%k;
	for(i=1; i<=k; i++)
	{
		if(i<=a2)
		{
			cout<<a1+1;
		}
		else
		{
			cout<<a1;
		}
		if(i!=k)
		{
			cout<<' ';
		}
	}
	if(n!=k)
	{
		cout<<' ';
		a3=(sall-sk)/(n-k);
		a4=(sall-sk)%(n-k);
		for(i=1; i<=(n-k); i++)
		{
		if(i<=a4)
		{
			cout<<a3+1;
		}
		else
		{
			cout<<a3;
		}
		if(i!=(n-k))
		{
			cout<<' ';
		}
		}
	}



	return 0;
}