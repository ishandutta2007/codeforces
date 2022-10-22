#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <iomanip>
#include <functional>
//#pragma optimize GCC("O3")
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<ll>a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		vector<ll>b(n);
		for (int i = 0; i < n; i++)
			cin >> b[i];
		ll ma = a[0], mb = b[0];
		for (int i = 0; i < n; i++)
			ma = min(a[i], ma);
		for (int i = 0; i < n; i++)
			mb = min(b[i], mb);
		ll ans = 0;
		for (int i = 0; i < n; i++)
		{
			ll da = a[i] - ma;
			ll db = b[i] - mb;
			ans += max(da, db);
		}
		cout << ans << endl;
	}
	return 0;
}