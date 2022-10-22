#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>
typedef long long ll;
typedef long double ld;
using namespace std;

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
		if (k * 2 + 1 > n)
		{
			cout << "-1\n";
			continue;
		}
		vector<int> v(n, 0);
		int cnt = 1;
		for (int i = 0; i < k; i++) v[i * 2 + 1] = n - i;
		for (int i = 0; i < n; i++) if (!v[i]) v[i] = cnt++;
		for (int i = 0; i < n; i++) cout << v[i] << " ";
		cout << "\n";
	}
	return 0;
}