#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>
#include <vector>
#include <string>
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
		int n, m, k;
		cin >> n >> m >> k;
		int sum = (n - 1) + (m - 1) * n;
		if (sum == k) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}