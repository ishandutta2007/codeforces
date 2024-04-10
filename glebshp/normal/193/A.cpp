#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 60;
const int px[] = {1, 0, -1, 0};
const int py[] = {0, 1, 0, -1};

int n, m;
string field[size];
bool used[size][size];

bool onfield(int x, int y)
{
	return (x >= 0 && x < n && y >= 0 && y < m);
}

void dfs(int x, int y)
{
	used[x][y] = true;
	for (int i = 0; i < 4; i++)
		if (onfield(x + px[i], y + py[i]) && field[x + px[i]][y + py[i]] == '#' && !used[x + px[i]][y + py[i]])
			dfs(x + px[i], y + py[i]);
}

bool check()
{
	bool flag = true;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			used[i][j] = false;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (field[i][j] == '#' && flag)
			{
				dfs(i, j);
				flag = false;
			}
	if (flag)
		return false;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (field[i][j] == '#' && !used[i][j])
				return true;
	return false;
}

int main() {
	//freopen("problem_a.in", "r", stdin);
	//freopen("problem_a.out", "w", stdout);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> field[i];
	int ans = -1;
	if (check())
		ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (field[i][j] == '#')
			{
				field[i][j] = '.';
				if (check() && ans == -1)
					ans = 1;
				field[i][j] = '#';
			}
	if (ans != -1)
	{
		cout << ans << endl;
		return 0;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (field[i][j] == '#')
			{
				int cnt = 0;
				if (i + 1 < n && field[i + 1][j] == '#')
				{
					cnt++;
					field[i + 1][j] = '.';
				}
				if (j + 1 < m && field[i][j + 1] == '#')
				{
					cnt++;
					field[i][j + 1] = '.';
				}
				if (check())
				{
					cout << cnt << endl;
					return 0;
				}
				cout << -1 << endl;
				return 0;
			}
	cout << ans << endl;
	return 0;

	return 0;
}