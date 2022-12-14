#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <iomanip>
#include <cmath>
#include <bitset>
typedef long long ll;
using namespace std;

const int maxn = 2e5 + 5, logn = 20;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<vector<int> > pf(maxn, vector<int>(logn, 0));
	for (int i = 1; i < maxn; i++)
	{
		pf[i] = pf[i - 1];
		for (int j = 0; j < logn; j++) if (i & (1 << j))
		{
			pf[i][j]++;
		}
	}
	int t;
	cin >> t;
	while (t--)
	{
		int l, r;
		cin >> l >> r;
		int ans = 0;
		for (int i = 0; i < logn; i++)
		{
			ans = max(ans, pf[r][i] - pf[l - 1][i]);
		}
		cout << (r - l + 1 - ans) << "\n";
	}
	return 0;
}