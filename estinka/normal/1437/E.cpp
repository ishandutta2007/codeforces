#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
typedef long long ll;
typedef long double ld;
using namespace std;

const int inf = 1e9 + 79;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<ll>a(n + 2), b(k + 2);
	a[0] = -inf;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i + 1];
		a[i + 1] -= i;
	}
	a[n + 1] = inf;
	b[0] = 0;
	for (int i = 0; i < k; i++)
	{
		cin >> b[i + 1];
	}
	b[k + 1] = n + 1;
	int ans = 0;
	for (int i = 0; i <= k; i++)
	{
		int now = b[i + 1], prev = b[i];
		if (a[now] < a[prev])
		{
			cout << "-1\n";
			return 0;
		}
		vector<int> c;
		for (int j = prev + 1; j < now; j++)
		{
			if (a[prev] <= a[j] && a[j] <= a[now])
			{
				int in = upper_bound(c.begin(), c.end(), a[j]) - c.begin();
				if (in == c.size()) c.push_back(a[j]);
				else c[in] = a[j];
			}
		}
		ans += (now - prev - 1) - c.size();
	}
	cout << ans << "\n";
	return 0;
}