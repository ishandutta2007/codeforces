#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	set<pair<int, char> > remaining;
	vector<int> b(2 * n);
	vector<int> when(n + 1);
	int x = 0;
	for (int i = 0; i < 2 * n; i++)
	{
		char c;
		cin >> c;
		if (c == '+')
		{
			b[i] = x;
			x++;
		}
		else
		{
			cin >> b[i];
			when[b[i]] = i;
		}
		remaining.insert({ i, c });
	}
	vector<int> ans(n);
	for (int i = 1; i <= n; i++)
	{
		int kde = when[i];
		auto it = remaining.find({ kde, '-' });
		if (it == remaining.begin() || it == remaining.end())
		{
			cout << "NO\n";
			return 0;
		}
		auto prev = it;
		prev--;
		if (prev->second == '-')
		{
			cout << "NO\n";
			return 0;
		}
		ans[b[prev->first]] = i;
		remaining.erase(prev);
		remaining.erase({ kde, '-' });
	}
	cout << "YES\n";
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}