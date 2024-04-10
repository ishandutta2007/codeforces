#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int n,m,lim;
int ans[200005];

long long step;
long long a[200005];

vector<int> v[200005],tmp;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	lim = n / m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		v[a[i] % m].push_back(i);
	}
	for (int i = 0;i < m * 2;i++)
	{
		int j = i % m;
		while (v[j].size() > lim)
		{
			tmp.push_back(v[j].back());
			v[j].pop_back();
		}
		while (v[j].size() < lim && tmp.size() > 0)
		{
			v[j].push_back(tmp.back());
			tmp.pop_back();
		}
	}
	for (int i = 0;i < m;i++)
		for (int j = 0;j < v[i].size();j++)
			ans[v[i][j]] = i;
	for (int i = 1;i <= n;i++)
	{
		long long to = a[i],val = 0;
		if (to % m < ans[i])
			val = ans[i] - to % m;
		else if (to % m > ans[i])
			val = m - to % m + ans[i];
		to += val;
		step += val;
		a[i] = to;
	}
	cout << step << endl;
	for (int i = 1;i <= n;i++)
		cout << a[i] << ' ';
	cout << endl;
	return 0;
}