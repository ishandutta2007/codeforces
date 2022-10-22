#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <iomanip>
#include <cmath>
typedef long long ll;
using namespace std;

int pay(int ai, int one, int two)
{
	int mini = 2e9 + 5;
	for (int i = 0; i <= one; i++)
	{
		for (int j = 0; j <= two; j++)
		{
			if (ai >= i + j * 2 && (ai - i - j * 2) % 3 == 0)
			{
				mini = min(mini, (ai - (i + j * 2)) / 3);
			}
		}
	}
	return mini > ai ? -1 : mini;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int mini = 2e9 + 5;
		for (int one = 0; one <= 4; one++)
		{
			for (int two = 0; two <= 4; two++)
			{
				int three = 0;
				for (int i = 0; i < n; i++)
				{
					int x = pay(a[i], one, two);
					if (x == -1)
					{
						three = -1;
						break;
					}
					three = max(three, x);
				}
				if (three != -1)
				{
					mini = min(mini, three + two + one);
				}
			}
		}
		cout << mini << "\n";
	}
	return 0;
}