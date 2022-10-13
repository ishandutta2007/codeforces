#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int n, f[5555], power2[5555];
long long a[5555];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		cin >> a[i];
		while (a[i] % 2 == 0) a[i] >>= 1, power2[i]++;
	}
	
	int best = 0;
	for (int i = 1; i <= n; i++)
	{
		f[i] = 1;
		for (int j = 1; j < i; j++)
			if (a[j] % a[i] == 0)
				if (power2[i] - power2[j] == i - j || power2[i] < i - j)
					f[i] = max(f[i], f[j] + 1);
		best = max(best, f[i]);
	}
	
	cout << n - best << endl;
}