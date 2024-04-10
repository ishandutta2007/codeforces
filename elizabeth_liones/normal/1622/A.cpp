#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
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
		vector<int> l(3);
		for (int& i : l) cin >> i;
		bool ok = false;
		for (int i = 0; i < l.size(); i++)
		{
			if (l[i] % 2 == 0 && l[(i + 1) % 3] == l[(i + 2) % 3])
			{
				ok = true;
			}
			if (l[i] == l[(i + 1) % 3] + l[(i + 2) % 3])
			{
				ok = true;
			}
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
	return 0;
}