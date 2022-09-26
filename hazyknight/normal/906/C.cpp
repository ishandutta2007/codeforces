#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

const int INF = 1000000000;

int n,m;
int f[1 << 22];
int pre[1 << 22],cho[1 << 22];
int next_[22];

pair<int,int> ff[1 << 22];

bool G[22][22];

int bitcount(int p){return p ? bitcount(p - (p & -p)) + 1 : 0;}

void dfs(int p)
{
	if (f[p] == 0)
		return;
	dfs(pre[p]);
	cout << cho[p] + 1 << ' ';
}

int main()
{
	cin >> n >> m;
	for (int i = 0;i < n;i++)
		next_[i] = (1 << i),G[i][i] = true;
	for (int u,v,i = 1;i <= m;i++)
	{
		cin >> u >> v;
		u--;
		v--;
		next_[u] |= (1 << v);
		next_[v] |= (1 << u);
		G[u][v] = G[v][u] = true;
	}
	for (int i = 0;i < (1 << n);i++)
	{
		int cnt = 0;
		for (int j = 0;j < n;j++)
			if ((i & (1 << j)) && (next_[j] & i) != i)
			{
				cnt = 1;
				break;
			}
		if (!cnt)
			f[i] = 0;
		else
			f[i] = INF;
	}
	for (int i = 0;i < (1 << n);i++)
		ff[i] = make_pair(bitcount(i),i);
	sort(ff,ff + (1 << n));
	for (int j = 0;j < (1 << n);j++)
		if (f[ff[j].second] != INF)
		{
			for (int k = 0;k < n;k++)
				if (ff[j].second & (1 << k))
				{
					int to = (ff[j].second | next_[k]);
					if (f[to] > f[ff[j].second] + 1)
					{
						cho[to] = k;
						pre[to] = ff[j].second;
						f[to] = f[ff[j].second] + 1;
					}
				}
		}
	/*
	for (int i = 0;i < (1 << n);i++)
	{
		cout << "f[";
		for (int j = 0;j < n;j++)
			if (i & (1 << j))
				cout << 1;
			else
				cout << 0;
		cout << "]=" << f[i] << "from:f[";
		for (int j = 0;j < n;j++)
			if (pre[i] & (1 << j))
				cout << 1;
			else
				cout << 0;
		cout << "] choose:" << cho[i] + 1 << endl;
	}
	*/
	cout << f[(1 << n) - 1] << endl;
	dfs((1 << n) - 1);
	cout << endl;
	return 0;
}