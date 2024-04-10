#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>

using namespace std;

const int MAXN = 105;
const int INF = 1 << 30;

int a[MAXN], pos[MAXN][MAXN];

int n, k, res = 0;

set<int> myset;
set<int>::iterator it, chose;

int main()
{
	ios::sync_with_stdio(false);
	memset(pos, -1, sizeof(pos));
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = n; i >= 1; i--)
	{

		for (int j = 1; j <= n; j++)
			pos[i][j] = pos[i + 1][j];
		pos[i][a[i]] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		if (myset.find(a[i]) != myset.end())
			continue;
		res++;
		if (myset.size() == k)
		{
			int r = 0;
			for (it = myset.begin(); it != myset.end(); it++)
			{
				if (pos[i][*it] > r || pos[i][*it] == -1)
				{
					chose = it;
					r = pos[i][*it];
					if (r == -1) r = INF;
				}
			}
			myset.erase(chose);
		}
		myset.insert(a[i]);
	}
	cout << res << endl;
	return 0;
}