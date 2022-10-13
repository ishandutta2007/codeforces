#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int BASE = int(1e9) + 7, N = 100010, X = 4, Y = 7;

long long s[N], p[N], power10[N * 2], power2[N * 2], num11[N * 2];

void init()
{
	power2[0] = power10[0] = num11[0] = 1;
	for (int i = 1; i < N * 2; i++)
	{
		power2[i] = power2[i - 1] * 2 % BASE;
		power10[i] = power10[i - 1] * 10 % BASE;
		num11[i] = (num11[i - 1] * 10 + 1) % BASE;
	}
	
	s[0] = X + Y; p[0] = X * Y;
	for (int i = 1; i < N; i++)
	{
		p[i] += power10[i * 2] * (X * X + Y * Y) % BASE * (power2[i] - 1) % BASE;
		p[i] += power10[i] * (X + Y) % BASE * s[i - 1]; p[i] %= BASE;
		p[i] += p[i - 1] * 2; p[i] %= BASE;
		// 4777... x 7444...
		p[i] += power10[i * 2] * X * Y; p[i] %= BASE;
		p[i] += num11[i - 1] * power10[i] % BASE * (X * X + Y * Y); p[i] %= BASE;
		p[i] += num11[i - 1] * num11[i - 1] % BASE * X * Y; p[i] %= BASE;
		
		s[i] = power2[i] * (X + Y) * 2 % BASE * num11[i] % BASE;
		s[i] = (s[i] - num11[i] * (X + Y) % BASE + BASE) % BASE;
	}
}

int calc2(int i, int a[], long long prefix)
{
	long long res = 0;
	prefix = (prefix * 10 + X) % BASE;
	if (!i) return a[i] ? prefix * (prefix + 3) % BASE : 0;
	
	if (a[i]) 
	{
		res += power10[i * 2] * prefix % BASE * prefix % BASE * (power2[i] - 1) % BASE;
		res += power10[i] * prefix % BASE * s[i - 1]; res %= BASE;
		res += p[i - 1]; res %= BASE;
		// ...4777... x ...7444...
		res += power10[i * 2] * prefix % BASE * (prefix + Y - X); res %= BASE;
		res += (prefix * X + (prefix + Y - X) * Y) % BASE * power10[i] % BASE * num11[i - 1]; res %= BASE;
		res += num11[i - 1] * num11[i - 1] % BASE * X * Y; res %= BASE;
		prefix = (prefix + Y - X) % BASE;
	}
	
	res = (res + calc2(i - 1, a, prefix)) % BASE;
	return res;
}

int calc(string A)
{
	long long res = 0;
	int n = A.size(), a[N];
	
	for (int i = 0; i < n; i++)
	{
		if (i < n - 1) res = (res + p[i]) % BASE;
		// 77... x 444...
		if (i) res = (res + num11[i] * num11[i - 1] % BASE * X * Y) % BASE;
	}
		
	for (int i = 0; i < n; i++) a[i] = A[n - 1 - i] == char(Y + '0');
	res = (res + calc2(n - 1, a, 0)) % BASE;
	
	return res;
}

int main()
{
	init();
	string A, B;
	cin >> A >> B;
	cout << (calc(B) - calc(A) + BASE) % BASE << endl;
}