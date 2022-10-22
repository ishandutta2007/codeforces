#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iomanip>
#include <algorithm>
#include <cmath>
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
		vector<ll> x, y;
		for (int i = 0, xi, yi; i < 2 * n; i++)
		{
			cin >> xi >> yi;
			if (xi) x.push_back(xi * 1ll * xi);
			else y.push_back(yi * 1ll * yi);
		}
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		long double ans = 0.;
		for (int i = 0; i < n; i++) ans += sqrt((long double)(x[i] + y[i]));
		cout << setprecision(20) << fixed << ans << "\n";
	}
	return 0;
}