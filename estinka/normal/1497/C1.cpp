#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <bitset>
typedef long long ll;
using namespace std;

vector<int> solve3(int n)
{
	if (n & 1) return { n / 2, n / 2, 1 };
	if (n % 4 == 2) return { (n - 2) / 2, (n - 2) / 2, 2 };
	if (n % 4 == 0) return  { n / 2, n / 4, n / 4 };
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
		vector<int> ans = solve3(n);
		cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
	}
	return 0;
}