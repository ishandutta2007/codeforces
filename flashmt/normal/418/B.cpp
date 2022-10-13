#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 60;

int n, m, monitorCost, money[111], monitor[111], solved[111];
long long f[1 << 20];

int main()
{
	cin >> n >> m >> monitorCost;
	
	for (int i = 0; i < n; i++)
	{
		int problems, x;
		cin >> money[i] >> monitor[i] >> problems;
		while (problems--)
		{
			cin >> x;
			solved[i] |= 1 << --x;
		}
	}
	
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (monitor[i] < monitor[j])
			{
				swap(monitor[i], monitor[j]);
				swap(solved[i], solved[j]);
				swap(money[i], money[j]);
			}
	
	for (int i = 1; i < 1 << m; i++) f[i] = oo;
	
	for (int i = 0; i < n; i++)
		for (int mask = (1 << m) - 1; mask >= 0; mask--)
		{
			int newMask = mask | solved[i];
			long long newCost = f[mask] + money[i];
			if (!mask) newCost += 1LL * monitor[i] * monitorCost;
			f[newMask] = min(f[newMask], newCost);
		}
		
	long long ans = f[(1 << m) - 1];
	if (ans == oo) ans = -1;
	cout << ans << endl;
}