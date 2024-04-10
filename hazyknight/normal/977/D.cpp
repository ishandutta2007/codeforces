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

long long a[105];

vector<int> v[105];

bool flag;

void dfs(int now,int depth)
{
	if (depth == n)
	{
		flag = true;
		cout << a[now] << ' ';
		return;
	}
	for (int i = 0;i < v[now].size();i++)
	{
		dfs(v[now][i],depth + 1);
		if (flag)
		{
			cout << a[now] << ' ';
			return;
		}
	}
}

int main()
{
	srand(time(0));
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	random_shuffle(a + 1,a + n + 1);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
		{
			if (a[i] % 3 == 0 && a[i] / 3 == a[j])
				v[j].push_back(i);
			if (a[i] * 2 == a[j])
				v[j].push_back(i);
		}
	for (int i = 1;i <= n;i++)
	{
		flag = false;
		dfs(i,1);
		if (flag)
		{
			cout << endl;
			return 0;
		}
	}
	return 0;
}