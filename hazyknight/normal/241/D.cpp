#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <iomanip>

using namespace std;

long long power10[3] = {1,10,100};

int cnt(int p)
{
	int ret = 0;
	while (p > 0)
	{
		ret++;
		p /= 10;
	}
	return ret;
}

int n,p,ans;
int a[65];
int pos[65];

bool mark[65];
bool flag[65][65][50005];

void dfs(int now,int x,int y)
{
	if (flag[now][x][y])
		return;
	if (ans > 0 && !x && !y)
	{
		cout << "Yes" << endl;
		cout << ans << endl;
		for (int i = 1;i <= n;i++)
			if (mark[i])
				cout << pos[i] << ' ';
		cout << endl;
		exit(0);
	}
	if (now > n)
		return;
	if (rand() & 1)
	{
		dfs(now + 1,x,y);
		mark[now] = true;
		ans++;
		dfs(now + 1,x ^ a[now],(y * power10[cnt(a[now])] + a[now]) % p);
		ans--;
		mark[now] = false;
	}
	else
	{
		mark[now] = true;
		ans++;
		dfs(now + 1,x ^ a[now],(y * power10[cnt(a[now])] + a[now]) % p);
		ans--;
		mark[now] = false;
		dfs(now + 1,x,y);
	}
	flag[now][x][y] = true;
}

int main()
{
	srand(20030506);
	ios::sync_with_stdio(false);
	cin >> n >> p;
	for (int i = 1,j = 1;i <= n;i++,j++)
	{
		cin >> a[i];
		if (a[i] > 63)
			i--,n--;
		else
			pos[i] = j;
	}
	dfs(1,0,0);
	cout << "No" << endl;
	return 0;
}