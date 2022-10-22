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
		int n;
		cin >> n;
		string s;
		cin >> s;
		if (!(count(s.begin(), s.end(), '<') * 1ll * count(s.begin(), s.end(), '>')))
		{
			cout << n << "\n";
		}
		else
		{
			int ans = 0;
			for (int i = 0; i < n; i++)
			{
				if (s[i] == '-' || s[(i + 1) % n] == '-')
				{
					ans++;
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}