#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <bitset>
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
		int n, m;
		cin >> n >> m;
		vector<int> a(n), f(m);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			f[a[i] % m]++;
		}
		int bad = 0;
		for (int i = 0; i < m; i++)
		{
			int i2 = (m - i) % m, now = 0;
			if (f[i] && i == i2)
			{
				bad++;
			} 
			else if (f[i] || f[i2])
			{
				bad++;
				int maxi = min(f[i], f[i2]) + 1;
				bad += max(0, f[i] - maxi) + max(0, f[i2] - maxi);
			}
			f[i] = f[i2] = 0;
		}
		cout << bad << "\n";
	}
	return 0;
}