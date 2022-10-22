#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <set>
#include <queue>
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
		int x, y;
		cin >> x >> y;
		if ((x + y) % 2 == 1)
		{
			cout << "-1 -1\n";
		}
		else if ((x + y) / 2 <= x)
		{
			cout << (x + y) / 2 << " " << 0 << "\n";
		}
		else
		{
			cout << 0 << " " << (x + y) / 2 << "\n";
		}
	}
	return 0;
}