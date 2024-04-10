#include <bits/stdc++.h>
using namespace std;

int m, n, a[1010][1010], f[1010][1010], ff[1010][1010], g[1010][1010], gg[1010][1010];

int main()
{
	ios::sync_with_stdio(0);
	
	cin >> m >> n;
	for (int i = 1; i <= m; i++)	
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
			
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			f[i][j] = max(f[i - 1][j], f[i][j - 1]) + a[i][j];
			
	for (int i = m; i; i--)
		for (int j = n; j; j--)
			ff[i][j] = max(ff[i + 1][j], ff[i][j + 1]) + a[i][j];
			
	for (int i = m; i; i--)
		for (int j = 1; j <= n; j++)
			g[i][j] = max(g[i + 1][j], g[i][j - 1]) + a[i][j];
			
	for (int i = 1; i <= m; i++)
		for (int j = n; j; j--)
			gg[i][j] = max(gg[i - 1][j], gg[i][j + 1]) + a[i][j];
			
	int ans = 0;
	for (int i = 2; i < m; i++)
		for (int j = 2; j < n; j++)
		{
			ans = max(ans, f[i - 1][j] + ff[i + 1][j] + g[i][j - 1] + gg[i][j + 1]);
			ans = max(ans, f[i][j - 1] + ff[i][j + 1] + g[i + 1][j] + gg[i - 1][j]);
		}
		
	cout << ans << endl;
}