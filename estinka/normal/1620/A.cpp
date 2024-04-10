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
		string s;
		cin >> s;
		if (count(s.begin(), s.end(), 'N') == 1)
		{
			cout << "NO\n";
		}
		else
		{
			cout << "YES\n";
		}
	}
	return 0;
}