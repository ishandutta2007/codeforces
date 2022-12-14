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
		int n, a, b;
		cin >> n >> a >> b;
		if (abs(a - b) > 1 || a + b > n - 2)
		{
			cout << "-1\n";
			continue;
		}
		vector<int> p(n);
		for (int i = 0; i < n; i++)
		{
			p[i] = i + 1;
		}
		if (a < b)
		{
			for (int i = 0; i < b; i++)
			{
				swap(p[i * 2], p[i * 2 + 1]);
			}
		}
		if (a == b)
		{
			for (int i = 0; i < a; i++)
			{
				swap(p[i * 2 + 1], p[i * 2 + 2]);
			}
		}
		if (a > b)
		{
			for (int i = 0; i < a; i++)
			{
				swap(p[i * 2], p[i * 2 + 1]);
			}
			for (int i = 0; i < n; i++)
			{
				p[i] = n - p[i] + 1;
			}
		}
		for (int i = 0; i < n; i++)
		{
			cout << p[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}