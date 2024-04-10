#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <queue>
#include <set> 
#include <vector>
#include <ctime>

using namespace std;

int n;
int u,v;
int degree[100005];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i < n;i++)
	{
		cin >> u >> v;
		degree[u]++;
		degree[v]++;
	}
	int st = 0;
	for (int i = 1;i <= n;i++)
		if (degree[i] > 2)
		{
			if (st)
			{
				cout << "No" << endl;
				return 0;
			}
			st = i;
		}
	cout << "Yes" << endl;
	if (!st)
	{
		cout << 1 << endl;
		for (int i = 1;i <= n;i++)
			if (degree[i] == 1)
				cout << i << ' ';
		cout << endl;
		return 0;
	}
	int cnt = 0;
	for (int i = 1;i <= n;i++)
		if (degree[i] == 1)
			cnt++;
	cout << cnt << endl;
	for (int i = 1;i <= n;i++)
		if (degree[i] == 1)
			cout << i << ' ' << st << endl;
	return 0;
}