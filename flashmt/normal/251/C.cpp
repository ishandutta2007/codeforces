#include <iostream>
#include <algorithm>
using namespace std;
const int oo = 1 << 29;

int f[400000], n = 1, k;

int gcd(int x,int y)
{
	return x && y?gcd(y,x%y):x+y;
}

int lcm(int x,int y)
{
	return x/gcd(x,y)*y;
}

int calc(int s, int t, int n)
{
	for (int i = 0; i <= n; i++) f[i] = oo;
	f[s] = 0; 
	for (int i = s; i > t; i--)	
	{
		f[i - 1] = min(f[i - 1], f[i] + 1);
		for (int j = 2; j <= k; j++)
			f[i - i % j] = min(f[i - i % j], f[i] + 1);
	}
	return f[t];
}

int main()
{
	long long a, b;
	
	cin >> a >> b >> k;
	for (int i = 2; i <= k; i++) n = lcm(n, i);
	
	if (a/n == b/n) cout << calc(a%n, b%n, n) << endl;
	else cout << calc(a%n, 0, n) + (a/n - b/n - 1) * calc(n, 0, n) + calc(n, b%n, n) << endl;
}