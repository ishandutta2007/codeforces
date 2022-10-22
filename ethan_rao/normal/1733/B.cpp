#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int testcase;
	for (cin >> testcase; testcase--;)
	{
		int n, x, y;
		cin >> n >> x >> y;
		if (min(x, y) || (max(x, y) == 0))
		{
			cout << "-1\n";
		}
		else
		{
			if (y)
			{
				x = y;
			}
			basic_string<int> res;
			{
				int i;
				for (i = 2; i <= n; i += x)
				{
					res += basic_string(x, i);
				}
				if (i == n + 1)
				{
					for (int i = 0; i < n - 1; i++)
					{
						cout << res[i] << " \n"[i == n - 2];
					}
				}
				else
				{
					cout << "-1\n";
				}
			}
		}
	}
}