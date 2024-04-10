#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>
#include <vector>
#include <string>
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
		ll r, b, d;
		cin >> r >> b >> d;
		if (min(b, r) * (d + 1) < max(b, r))
			cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}