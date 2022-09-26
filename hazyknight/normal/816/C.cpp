#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <queue>

using namespace std;

const int MAXN = 105;
const int INF = (1 << 30);

int n,m;
int g[MAXN][MAXN];

vector<int> num;
vector<string> ans;

void pickc(bool c)
{
	for (int i = 1;i <= m;i++)
	{
		int MIN = INF;
		bool flag = false;
		for (int j = 1;j <= n;j++)
			MIN = min(MIN,g[j][i]);
		for (int j = 1;j <= n;j++)
		{
			g[j][i] -= MIN;
			if (g[j][i] && c)
			{
				cout << -1 << endl;
				exit(0);
			}
		}
		for (int j = 1;j <= MIN;j++)
			ans.push_back("col"),num.push_back(i);
	}
}

void pickr(bool c)
{
	for (int i = 1;i <= n;i++)
	{
		int MIN = INF;
		bool flag = false;
		for (int j = 1;j <= m;j++)
			MIN = min(MIN,g[i][j]);
		for (int j = 1;j <= m;j++)
		{
			g[i][j] -= MIN;
			if (g[i][j] && c)
			{
				cout << -1 << endl;
				exit(0);
			}
		}
		for (int j = 1;j <= MIN;j++)
			ans.push_back("row"),num.push_back(i);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			cin >> g[i][j];
	if (n > m)
	{
		pickc(0);
		pickr(1);
	}
	else
	{
		pickr(0);
		pickc(1);
	}
	cout << ans.size() << endl;
	for (int i = 0;i < ans.size();i++)
		cout << ans[i] << ' ' << num[i] << endl;
	return 0;
}