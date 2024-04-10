#include <bits/stdc++.h>
using namespace std;
const int BASE = int(1e9) + 7, MAX = (1 << 20) - 1;

int f[1 << 20];
long long power2[1000100];

int main()
{
	ios::sync_with_stdio(0);
	int n, x;
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		cin >> x; 
		f[x ^ MAX]++;
	}
	
	power2[0] = 1;
	for (int i = 1; i <= n; i++) power2[i] = power2[i - 1] * 2 % BASE;
	
	for (int bit = 0; bit < 20; bit++)
		for (int mask = 0; mask < 1 << 20; mask++)
			if (mask >> bit & 1)
				f[mask] += f[mask ^ 1 << bit];
				
	long long ans = 0;
	for (int mask = 0; mask < 1 << 20; mask++)
		if (__builtin_popcount(mask) % 2) ans = (ans + BASE - power2[f[mask]] + 1) % BASE;
		else ans = (ans + power2[f[mask]] - 1) % BASE;
	
	cout << ans << endl;
}