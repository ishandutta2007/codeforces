#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, k, a[111][111];
	cin >> m >> n >> k;
	
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
			
	if (m <= k)
	{
		int allOne = (1 << m) - 1, f[1024] = {0};
		for (int j = 1; j <= n; j++)
		{
			int mask = 0;
			for (int i = 1; i <= m; i++) mask = mask << 1 | a[i][j];
			for (int pattern = 0; pattern < allOne; pattern++)
				f[pattern] += min(__builtin_popcount(pattern ^ mask), __builtin_popcount(pattern ^ mask ^ allOne));
		}
		
		int ans = m * n;
		for (int pattern = 0; pattern < allOne; pattern++) ans = min(ans, f[pattern]);
		
		if (ans > k) ans = -1;
		cout << ans << endl;
	}
	else
	{
		int ans = m * n;
		for (int fixedCol = 1; fixedCol <= n; fixedCol++)
		{
			int flip = 0;
			for (int j = 1; j <= n; j++)
			{
				int dif = 0;
				for (int i = 1; i <= m; i++) dif += a[i][j] ^ a[i][fixedCol];
				flip += min(dif, m - dif);
			}

			ans = min(ans, flip);
		}
		
		if (ans > k) ans = -1;
		cout << ans << endl;
	}
}