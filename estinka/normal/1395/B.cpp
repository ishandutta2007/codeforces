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
#include <random>
#include <chrono>
#endif
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	x--; y--;
	vector<pair<int, int> > path;
	path.push_back({ x, y });
	for (int i = x + 1; i < n; i++)
	{
		path.push_back({ i, y });
	}
	for (int i = x - 1; i >= 0; i--)
	{
		path.push_back({ i, y });
	}
	for (int j = y - 1; j >= 0; j--)
	{
		if (path.back().first == 0)
		{
			for (int i = 0; i < n; i++)
			{
				path.push_back({ i, j });
			}
		}
		else
		{
			for (int i = n - 1; i >= 0; i--)
			{
				path.push_back({ i, j });
			}
		}
	}
	for (int j = y + 1; j < m; j++)
	{
		if (path.back().first == 0)
		{
			for (int i = 0; i < n; i++)
			{
				path.push_back({ i, j });
			}
		}
		else
		{
			for (int i = n - 1; i >= 0; i--)
			{
				path.push_back({ i, j });
			}
		}
	}
	//vector<vector<int> > f(n, vector<int>(m, -1));
	for (int i = 0; i < path.size(); i++)
	{
		cout << path[i].first + 1 << " " << path[i].second + 1 << "\n";
		//f[path[i].first][path[i].second] = i;
	}
	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(3) << f[i][j] << " ";
		}
		cout << endl;
	}*/
	return 0;
}