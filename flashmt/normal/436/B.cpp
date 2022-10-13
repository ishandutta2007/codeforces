#include <bits/stdc++.h>
using namespace std;

int m, n, k, ans[2222];
char a[2222][2222];

int main()
{
	cin >> m >> n >> k;
	for (int i = 0; i < m; i++) scanf("%s", a[i]);
	
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (i * 2 < m && a[i * 2][j] == 'U') ans[j]++;
			if (j + i < n && a[i][j + i] == 'L') ans[j]++;
			if (j - i >= 0 && a[i][j - i] == 'R') ans[j]++;
		}
		
	for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}