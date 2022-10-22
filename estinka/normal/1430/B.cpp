#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <random>
#include <chrono>
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
		int n, k;
		cin >> n >> k;
		vector<ll> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		if (n == 1)
		{
			cout << 0 << "\n";
			continue;
		}
		sort(a.begin(), a.end());
		int in = max(n - 2, 0);
		while (k-- && in >= 0)
		{
			a[n - 1] += a[in];
			a[in] = 0;
			in--;
		}
		sort(a.begin(), a.end());
		cout << a[n-1] - a[0] << "\n";
	}
	return 0;
}