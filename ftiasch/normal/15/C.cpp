// Codeforces Beta Round #15
// Problem C -- Industrial Nim
#include <iostream>

using namespace std;

int n;

long long xor_sum(long long n)
{
	long long a = 0;
	if((n & 3) == 2 || (n & 3) == 3)
		a = 1;
	for(int i = 1; i != 60; ++ i)
	{
		long long r = n & ((1LL << (i + 1)) - 1);
		if(!r)continue;
		if(r <= (1LL << i))continue;
		if((r - (1LL << i)) & 1)
			a ^= 1LL << i;
	}
	return a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	long long s = 0;
	for(int i = 0; i != n; ++ i)
	{
		long long x, m;
		cin >> x >> m;
		s ^= xor_sum(x) ^ xor_sum(x + m);
	}
	if(s)
		cout << "tolik\n";
	else
		cout << "bolik\n";
	return 0;
}