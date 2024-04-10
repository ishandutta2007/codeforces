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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int w, h;
		cin >> w >> h;
		vector<vector<int> > x(2);
		ll ans = 0;
		for (int i = 0; i < 2; i++)
		{
			int k;
			cin >> k;
			x[i].resize(k);
			for (int j = 0; j < k; j++)
			{
				cin >> x[i][j];
			}
			int dist = x[i].back() - x[i][0];
			ans = max(ans, h * 1ll * dist);
		}
		vector<vector<int> > y(2);
		for (int i = 0; i < 2; i++)
		{
			int k;
			cin >> k;
			y[i].resize(k);
			for (int j = 0; j < k; j++)
			{
				cin >> y[i][j];
			}
			int dist = y[i].back() - y[i][0];
			ans = max(ans, w * 1ll * dist);
		}
		//cout << "			";
		cout << ans << "\n";
	}
	return 0;
}