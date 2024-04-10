#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
const int N = 5010, inf = 1e9;
int f[N][1 << 13], a[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int testcase;
	for (cin >> testcase; testcase--;)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 0; i <= n + 1; i++)
		{
			for (int j = 0; j < 1 << 13; j++)
			{
				f[i][j] = inf;
			}
		}
		f[1][a[1]] = 0;
		for (int i = 1; i < n; i++)
		{
			f[i + 1][a[i + 1]] = min(f[i + 1][a[i + 1]], f[i][0]);
			for (int j = 0; j < 1 << 13; j++)
			{
				f[i + 1][a[i + 1] ^ j] = min(f[i + 1][a[i + 1] ^ j], f[i][j] + 1);
				f[i + 1][a[i + 1]] = min(f[i + 1][a[i + 1]], f[i][j] + 1);
			}
		}
		int ans = f[n][0];
		for (int j = 1; j < 1 << 13; j++)
		{
			ans = min(ans, f[n][j] + 1);
		}
		cout << ans << '\n';
	}
}