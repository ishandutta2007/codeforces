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
		vector<int>a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a.begin(), a.end());
		bool yes = true;
		for (int i = 0; i < n - 1; i++)
		{
			if (a[i + 1] - a[i] > 1)
				yes = false;
		}
		if (yes) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}