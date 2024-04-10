#ifdef __GNUG__
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
#endif
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int l, r;
		cin >> l >> r;
		if (2 * l <= r)
		{
			cout << l << " " << 2 * l << endl;
		}
		else
		{
			cout << "-1 -1" << endl;
		}
	}
	return 0;
}