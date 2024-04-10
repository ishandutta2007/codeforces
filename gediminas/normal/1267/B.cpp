/*input
WWWOOOOOOWWW
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int l = 0;
	int r = s.size() - 1;
	while (l <= r)
	{
		int sz = r - l + 1;
		if (s[l] != s[r])
		{
			cout << "0\n";
			return 0;
		}
		int k = 2;
		while (l < r && s[l + 1] == s[l])
		{
			l++;
			k++;
		}
		while (l < r && s[r - 1] == s[r])
		{
			r--;
			k++;
		}
		if (l == r)
		{
			if (sz >= 2)
				cout << sz + 1 << "\n";
			else
				cout << "0\n";
			return 0;
		}
		if (k >= 3)
		{
			l++;
			r--;
		}
		else
		{
			cout << "0\n";
			return 0;
		}
	}
	cout << "0\n";
	return 0;
}