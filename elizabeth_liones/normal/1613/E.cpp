#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <queue>
typedef long long ll;
using namespace std;

const int di[4] = { 0, 0, -1, 1 };
const int dj[4] = { -1, 1, 0, 0 };
int n, m;
bool good(int i, int j, const vector<string>& s)
{
	if (i < 0 || j < 0 || i >= n || j >= m || s[i][j] != '.') return false;
	bool one = false;
	for (int x = 0; x < 4; x++)
	{
		int i2 = i + di[x], j2 = j + dj[x];
		if (i2 < 0 || j2 < 0 || i2 >= n || j2 >= m || s[i2][j2] != '.') continue;
		if (one) return false;
		one = true;
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		vector<string> s(n);
		queue<pair<int, int> > q;
		for (int i = 0; i < n; i++)
		{
			cin >> s[i];
			for (int j = 0; j < m; j++)
			{
				if (s[i][j] == 'L')
				{
					q.push({ i, j });
				}
			}
		}
		while (!q.empty())
		{
			int i = q.front().first, j = q.front().second;
			q.pop();
			for (int x = 0; x < 4; x++)
			{
				int i2 = i + di[x], j2 = j + dj[x];
				if (good(i2, j2, s))
				{
					s[i2][j2] = '+';
					q.push({ i2, j2 });
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			cout << s[i] << "\n";
		}
	}
	return 0;
}