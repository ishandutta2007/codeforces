#include <bits/stdc++.h>

using namespace std;

int n;
int f[1005][1005];
int sum[2005];

bool mark[1005];

bool ok(int p)
{
	for (int i = 0;i < n;i++)
		for (int j = 0;j <= p;j++)
			f[i][j] = 1e9;
	f[0][0] = 0;
	for (int i = 1;i < n;i++)
	{
		if (mark[i])
		{
			for (int j = 0;j <= p;j++)
				f[i][j] = f[i - 1][j] + 1;
		}
		else
		{
			for (int j = 0;j <= p;j++)
				if (f[i - 1][j] < p)
					f[i][j] = 0;
				else if (j)
					f[i][j] = f[i - 1][j - 1] + 1;
		}
	}
	return f[n - 1][p] < p;
}

int main()
{
	cin >> n;
	int st = 0,MAX = -1;
	for (int i = 2;i <= n;i++)
	{
		int cnt = 0,tot = 0;
		for (int j = i + 1;j < n;j++)
		{
			if (cnt + 1 == i)
			{
				cnt = 0;
				continue;
			}
			cnt++;
			tot++;
		}
		if (tot > MAX)
		{
			st = i;
			MAX = tot;
		}
	}
	while (1)
	{
		int tot = 0;
		for (int i = 1;i < n;i++)
			if (!mark[i])
				tot++;
		if (st > tot)
			break;
		for (int i = st;i <= tot;i++)
		{
			if (!ok(i))
				st = i + 1;
			else
				break;
		}
		if (st > tot)
			break;
		ok(st);
		int cur = st;
		vector<int> ask;
		for (int i = n - 1;i >= 1;i--)
		{
			if (mark[i])
				continue;
			if (!f[i][cur])
				continue;
			ask.push_back(i);
			cur--;
		}
		reverse(ask.begin(),ask.end());
		cout << ask.size() << ' ';
		for (int i = 0;i < ask.size();i++)
		{
			cout << ask[i] << ' ';
			mark[ask[i]] = 1;
		}
		cout << endl;
		cout.flush();
		int x = 1;
		cin >> x;
		/*
		for (int i = 1;i <= n;i++)
			sum[i] = sum[i - 1] + mark[i];
		for (int i = n + 1;i <= 2 * n;i++)
			sum[i] = sum[i - 1] + mark[i - n];
		for (int i = 2;i <= n;i++)
			if (sum[x + ask.size() - 1] - sum[x - 1] < sum[i + ask.size() - 1] - sum[i - 1])
				x = i;
		*/
		for (int i = 0;i < ask.size();i++)
			mark[(x + i) % n == 0 ? n : (x + i) % n] = 0;
	}
	cout << 0 << endl;
	cout.flush();
	/*
	int ANS = 0;
	for (int i = 1;i <= n;i++)
		ANS += mark[i];
	cout << ANS << endl;
	*/
	return 0;
}