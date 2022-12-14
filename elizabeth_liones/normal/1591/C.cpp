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

ll solve(vector<int> x, int k)
{
	int n = x.size();
	ll ans = 0;
	for (int i = n - 1; i >= 0; i -= k)
	{
		ans += x[i];
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> x1(n), x2(n);
		int maxi = 0;
		for (int i = 0, x; i < n; i++)
		{
			cin >> x;
			maxi = max(maxi, abs(x));
			if (x > 0) x1.push_back(x);
			else x2.push_back(-x);
		}
		sort(x1.begin(), x1.end());
		sort(x2.begin(), x2.end());
		ll ans = solve(x1, k) * 2ll + solve(x2, k) * 2ll;
		ans -= (ll)maxi;
		cout << ans << "\n";
	}
	return 0;
}