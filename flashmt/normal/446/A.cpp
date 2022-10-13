#include <bits/stdc++.h>
using namespace std;

int n, a[100100], f[100100][2];

int main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	int ans = 1;
	
	for (int i = 1; i <= n; i++)
	{
		f[i][0] = 1;
		f[i][1] = 1 + (i > 1);
		
		if (i > 1 && a[i] > a[i - 1]) 
		{
			f[i][0] = max(f[i][0], f[i - 1][0] + 1);
			f[i][1] = max(f[i][1], f[i - 1][1] + 1);
		}
		if (i > 2 && a[i] - 1 > a[i - 2])
			f[i][1] = max(f[i][1], f[i - 2][0] + 2);
		
		ans = max(ans, f[i][0] + (i < n));
		ans = max(ans, f[i][1]);
	}
	
	cout << ans << endl;
}