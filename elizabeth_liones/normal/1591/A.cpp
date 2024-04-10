#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <iomanip>
typedef long long ll;
using namespace std;

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
		int x = 1;
		for (int i = 0; i < n; i++)
		{
			if (!a[i])
			{
				if (i && !a[i - 1])
				{
					x = -1;
					break;
				}
			}
			else
			{
				if (i && a[i - 1])
				{
					x += 5;
				}
				else
				{
					x += 1;
				}
			}
		}
		cout << x << "\n";
	}
	return 0;
}