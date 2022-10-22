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
		int n;
		ll k, x;
		string s;
		cin >> n >> k >> x >> s;
		x--;
		string ans;
		for (int i = n - 1; i >= 0; i--)
		{
			if (s[i] == '*' && (i == n - 1 || s[i + 1] == 'a'))
			{
				int j = i;
				while (j > 0 && s[j - 1] == '*') j--;
				ll len = (i - j + 1) * k + 1;
				ll cnt = x % len;
				x /= len;
				for (int j = 0; j < cnt; j++)
				{
					ans.push_back('b');
				}
			}
			else if (s[i] == 'a')
			{
				ans.push_back('a');
			}
		}
		reverse(ans.begin(), ans.end());
		cout << ans << "\n";
	}
	return 0;
}