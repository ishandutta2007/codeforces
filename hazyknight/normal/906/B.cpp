#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int n,m,xa,xb,ya,yb;
long long c[100005];
bool mark[100005];
vector<long long> ans[100005];

long long id(long long x,long long y){return (x - 1) * m + y;}

bool check(long long a,long long b)
{
	if (a > b)
		swap(a,b);
	xa = (a - 1) / m + 1,ya = (a - 1) % m + 1;
	xb = (b - 1) / m + 1,yb = (b - 1) % m + 1;
	if (xa == xb && ya + 1 == yb)
		return true;
	if (ya == yb && xa + 1 == xb)
		return true;
	return false;
}

void dfs(int now)
{
	if (now > n * m)
	{
		cout << "YES" << endl;
		for (int i = 1;i <= n;i++,cout << endl)
			for (int j = 1;j <= m;j++)
				cout << c[id(i,j)] << ' ';
		exit(0);
	}
	for (int i = 1;i <= n * m;i++)
		if (!mark[i])
		{
			if (now > m && check(i,c[now - m]))
				continue;
			if ((now - 1) % m != 0 && check(i,c[now - 1]))
				continue;
			c[now] = i;
			mark[i] = true;
			dfs(now + 1);
			mark[i] = false;
		}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		for (int j = 0;j <= m;j++)
			ans[i].push_back(0);
	if (n > 4)
	{
		for (int i = 1;i <= m;i++)
		{
			if (i & 1)
			{
				int cnt = 0;
				for (int j = 1;j <= n;j += 2)
					ans[++cnt][i] = id(j,i);
				for (int j = 2;j <= n;j += 2)
					ans[++cnt][i] = id(j,i);
			}
			else
			{
				int cnt = 0;
				for (int j = 2;j <= n;j += 2)
					ans[++cnt][i] = id(j,i);
				for (int j = 1;j <= n;j += 2)
					ans[++cnt][i] = id(j,i);
			}
		}
	}
	else if (m > 4)
	{
		for (int i = 1;i <= n;i++)
		{
			if (i & 1)
			{
				int cnt = 0;
				for (int j = 1;j <= m;j += 2)
					ans[i][++cnt] = id(i,j);
				for (int j = 2;j <= m;j += 2)
					ans[i][++cnt] = id(i,j);
			}
			else
			{
				int cnt = 0;
				for (int j = 2;j <= m;j += 2)
					ans[i][++cnt] = id(i,j);
				for (int j = 1;j <= m;j += 2)
					ans[i][++cnt] = id(i,j);
			}
		}
	}
	else
	{
		dfs(1);
		cout << "NO" << endl;
		return 0;
	}
	if (ans[1][1])
	{
		cout << "YES" << endl;
		for (int i = 1;i <= n;i++,cout << endl)
			for (int j = 1;j <= m;j++)
				cout << ans[i][j] << ' ';
	}
	else
		cout << "NO" << endl;
	return 0;
}