#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int notPrime[1000100];

int main()
{
	notPrime[1]=1;
	for (int i=2;i<1000;i++)
		if (!notPrime[i])
			for (int j=i*i;j<=1000000;j+=i)
				notPrime[j]=1;
				
	int n;
	long long x;
	cin >> n;
	while (n--)
	{
		cin >> x;
		long long y=sqrt(x);
		cout << (!notPrime[y] && y*y==x?"YES":"NO") << endl;
	}
}