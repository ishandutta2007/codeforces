#include <iostream>
#include <algorithm>
using namespace std;
const int BASE = int(1e9) + 7;

long long ans, f[2222][2222], s[2222][2222], g[2222][2222];

int main()
{
	int m, n;
	cin >> m >> n;

	// non-decreasing rows
	for (int height = 1; height <= m; height++)
	{
		long long accSum = (height == 1);
		for (int width = 2; width <= n; width++)
		{
			accSum = (accSum + s[height - 1][width]) % BASE;
			f[height][width] = accSum;
			s[height][width] = (s[height][width - 1] + f[height][width]) % BASE;
		}
	}
	
	// mid column
	for (int height = 1; height <= m; height++)
		for (int width = n; width >= 2; width--)
		{
			f[height][width] = f[height][width] * (n - width + 1) % BASE;
			s[height][width] = (s[height][width + 1] + f[height][width]) % BASE;
		}
		
	// first strictly decreasing row
	for (int height = 2; height <= m; height++)
	{
		long long accSum = 0;
		for (int width = n; width >= 2; width--)
		{
			accSum += s[height - 1][width];
			g[height][width] = (accSum + BASE - f[height - 1][width]) % BASE;
		}
	}
	
	// non-increasing rows
	for (int width = 2; width <= n; width++) s[1][width] = 0;
	for (int height = 2; height <= m; height++)
	{
		long long accSum = 0;
		for (int width = n; width >= 2; width--)
		{
			accSum += s[height - 1][width];
			g[height][width] += accSum;
			s[height][width] = (s[height][width + 1] + g[height][width]) % BASE;
		}
	}
	
	// result
	for (int height = 1; height <= m; height++)
		for (int width = 2; width <= n; width++)
		{
			long long both = f[height][width] + g[height][width];
			ans = (ans + both * (m - height + 1)) % BASE;
		}
		
	cout << ans << endl;
}