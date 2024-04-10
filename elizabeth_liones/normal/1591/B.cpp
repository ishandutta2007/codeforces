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
		vector<pair<int, int> > a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i].first;
			a[i].second = i;
		}
		sort(a.begin(), a.end());
		vector<pair<int, int> > sf(n + 1, { -1, -1 });
		for (int i = n - 1; i >= 0; i--)
		{
			sf[i] = max(sf[i + 1], { a[i].second, i });
		}
		int x = sf[0].second;
		int ans = 0;
		while (x != n - 1)
		{
			x = sf[x + 1].second;
			ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}