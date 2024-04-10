#include <bits/stdc++.h>
using namespace std;

int cnt[5050][5050], m, n;
string s;

int main()
{
	ios::sync_with_stdio(0);
	
	cin >> m >> n;
	for (int i = 0; i < m; i++) 
	{
		cin >> s;
		for (int j = 0; j < n; )
			if (s[j] == '1')
			{
				int jj = j + 1;
				while (jj < n && s[jj] == '1') jj++;
				cnt[j + 1][jj]++;
				j = jj;
			}
			else j++;
	}
	
	int ans = 0;
	for (int l = n - 1; l >= 0; l--)
		for (int i = 1; i + l <= n; i++)
		{
			int j = i + l;
			cnt[i][j] += cnt[i][j + 1] + cnt[i - 1][j] - cnt[i - 1][j + 1];
			if (j >= i) ans = max(ans, (j - i + 1) * cnt[i][j]);
		}
		
	cout << ans << endl;	
}