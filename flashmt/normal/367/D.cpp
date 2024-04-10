#include <bits/stdc++.h>
using namespace std;

int n, m, d, a[100100], isBad[1 << 20], cnt[20];

int main()
{
	int x, s;
	cin >> n >> m >> d;
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		while (s--) cin >> x, a[x] = i;
	}
	
	for (int i = 1, mask = 0; i <= n; i++)
	{
		if (!cnt[a[i]]++) mask |= 1 << a[i];
		if (i > d && !--cnt[a[i - d]]) mask ^= 1 << a[i - d];
		if (i >= d) isBad[mask] = 1;
	}
	
	int maxExclude = 0;
	for (int mask = 1; mask < 1 << m; mask++)
	{
		for (int i = 0; i < m; i++)
			if (mask >> i & 1)
				isBad[mask] |= isBad[mask ^ 1 << i];
				
		if (!isBad[mask]) maxExclude = max(maxExclude, __builtin_popcount(mask));
	}
			
	cout << m - maxExclude << endl;	
}