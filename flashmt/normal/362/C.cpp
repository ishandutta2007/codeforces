#include <bits/stdc++.h>
using namespace std;

int n, a[5555], cnt[5555][5555];

int main()
{
	cin >> n;
	
	int initial = 0;
	for (int i = 1; i <= n; i++) 
	{
		cin >> a[i];
		for (int j = 0; j <= n; j++)
			cnt[i][j] = cnt[i - 1][j] + (a[i] <= j);
		initial += cnt[i][n] - cnt[i][a[i]];
	}
	
	int best = -1, pairs = 0;
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++)
			if (a[i] > a[j])
			{
				int decrease = 0;
				decrease += (cnt[j - 1][a[i]] - cnt[i][a[i]]) - (cnt[j - 1][a[j]] - cnt[i][a[j]]);
				decrease = decrease * 2 + 1;
				if (decrease == best) pairs++;
				else
					if (decrease > best) best = decrease, pairs = 1;
			}
			
	cout << initial - best << ' ' << pairs << endl;
}