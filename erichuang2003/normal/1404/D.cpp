#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int MAXN = 1000005;

int n;
int a[MAXN];
int x[MAXN];
int y[MAXN];
int match[MAXN];

bool vis[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	if (~n & 1)
	{
		cout << "First" << endl;
		for (int i = 1;i <= n;i++)
			cout << i << ' ';
		for (int i = 1;i <= n;i++)
			cout << i << ' ';
		cout << endl;
		cout.flush();
		return 0;
	}
	else
	{
		cout << "Second" << endl;
		for (int i = 1;i <= 2 * n;i++)
		{
			cin >> a[i];
			if (x[a[i]])
				y[a[i]] = i;
			else
				x[a[i]] = i;
		}
		for (int i = 1;i <= n;i++)
		{
			match[x[i]] = y[i];
			match[y[i]] = x[i];
		}
		for (int i = 1;i <= n;i++)
		{
			int cur = i;
			if (vis[i] || vis[i + n])
				continue;
			while (!vis[cur])
			{
				vis[cur] = 1;
				cur = (match[cur] > n ? match[cur] - n : match[cur] + n);
			}
		}
		int sum = 0;
		for (int i = 1;i <= 2 * n;i++)
			if (vis[i])
				(sum += i) %= (2 * n);
		if (sum)
		{
			for (int i = 1;i <= 2 * n;i++)
				vis[i] ^= 1;
		}
		for (int i = 1;i <= 2 * n;i++)
			if (vis[i])
				cout << i << ' ';
		cout << endl;
		cout.flush();
	}
	return 0;
}