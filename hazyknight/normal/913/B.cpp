#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

int n;
int fa[1005];
int degree[1005];
int cnt[1005];

int main()
{
	cin >> n;
	for (int i = 2;i <= n;i++)
	{
		cin >> fa[i];
		degree[fa[i]]++;
	}
	for (int i = 1;i <= n;i++)
		if (!degree[i])
			cnt[fa[i]]++;
	for (int i = 1;i <= n;i++)
		if (degree[i] && cnt[i] < 3)
		{
			cout << "No" << endl;
			return 0;
		}
	cout << "Yes" << endl;
	return 0;
}