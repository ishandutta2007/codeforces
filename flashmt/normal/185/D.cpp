#include <iostream>
#include <algorithm>
using namespace std;

long long p;

long long pow2(long long y)
{
	if (!y) return 1LL;
	long long res=pow2(y/2);
	res*=res; res%=(p-1);
	if (y%2) res*=2, res%=(p-1);
	return res;
}

long long power(long long x,long long y)
{
	if (!y) return x?1LL:0LL;
	long long res=power(x,y/2);
	res*=res; res%=p;
	if (y%2) res*=x, res%=p;
	return res;
}

int main()
{
	int test;
	cin >> test;
	while (test--)
	{
		long long k,l,r;
		cin >> k >> l >> r >> p;
		int odd=k%2;
		
		if (k==1) cout << 2%p << endl;
		else
		{
			k%=p;
			long long A=power(k,pow2(l)),ans; 
			
			if (A==1) ans=power(2,r-l+1);
			else
			{
				long long numerator=(power(A,pow2(r-l+1))+p-1)%p;
				long long denominator=power((A+p-1)%p,p-2); 
				ans=numerator*denominator%p;
			}
			
			if (odd) ans*=power(power(2,p-2),r-l), ans%=p;
			cout << ans << endl;
		}
	}
}