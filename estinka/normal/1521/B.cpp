#include <algorithm>
#include <set>
#include <vector>
#include <iostream>
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
		vector<ll>a(n);
		for (int i = 0; i < n; i++)cin >> a[i];
		int i = min_element(a.begin(), a.end()) - a.begin();
		cout << n - 1 << "\n";
		for (int j = 0; j < n; j++)
		{
			if (i == j) continue;
			int x = a[i], y = a[i] + (abs(i - j) & 1);
			cout << i + 1 << " " << j + 1 << " " << x << " " << y << "\n";
		}
	}
	return 0;
}