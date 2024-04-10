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

int n,m;
int mark[2005];

string s[2005];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> s[i];
		for (int j = 0;j < m;j++)
			mark[j] += s[i][j] - '0';
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 0;j < m;j++)
			mark[j] -= s[i][j] - '0';
		bool ok = true;
		for (int j = 0;j < m;j++)
			if (!mark[j])
			{
				ok = false;
				break;
			}
		if (ok)
		{
			cout << "YES" << endl;
			return 0;
		}
		for (int j = 0;j < m;j++)
			mark[j] += s[i][j] - '0';
	}
	cout << "NO" << endl;
	return 0;
}