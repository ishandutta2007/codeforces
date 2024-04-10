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
		string a, b;
		cin >> a >> b;
		int ans = 1e9 + 5;
		for (int it = 0; it < 2; it++)
		{
			int cnt10 = 0, cnt01 = 0;
			for (int i = 0; i < n; i++)
			{
				if (a[i] == '1' && b[i] == '0') cnt10++;
				if (a[i] == '0' && b[i] == '1') cnt01++;
			}
			if (it == 0 && cnt10 == cnt01)
			{
				ans = min(ans, cnt01 + cnt10);
			}
			if (it == 1 && cnt01 == cnt10 + 1)
			{
				ans = min(ans, cnt01 + cnt10);
			}
			for (int i = 0; i < n; i++)
			{
				a[i] = (a[i] == '0' ? '1' : '0');
			}
		}
		//cout << "			";
		cout << (ans > n ? -1 : ans) << "\n";
	}
	return 0;
}