#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <set>
#include <queue>

using namespace std;

const int MAXN = 1005;

int n,id;
int cnt[MAXN];

pair<int,int> e[MAXN];

vector<int> Q;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int u,v,i = 1;i < n;i++)
	{
		cin >> u >> v;
		if (u > v)
			swap(u,v);
		if (v != n)
		{
			cout << "NO" << endl;
			return 0;
		}
		cnt[u]++;
	}
	for (int i = 1;i < n;i++)
	{
		if (!cnt[i])
			Q.push_back(i);
		else if (cnt[i] == 1)
		{
			id++;
			e[id].first = i;
			e[id].second = n;
		}
		else
		{
			if (Q.size() + 1 < cnt[i])
			{
				cout << "NO" << endl;
				return 0;
			}
			id++;
			e[id].first = i;
			e[id].second = Q.back();
			for (int j = 1;j < cnt[i] - 1;j++)
			{
				id++;
				e[id].first = Q.back();
				Q.pop_back();
				e[id].second = Q.back();
			}
			id++;
			e[id].first = Q.back();
			Q.pop_back();
			e[id].second = n;
		}
	}
	if (Q.size() > 0)
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for (int i = 1;i < n;i++)
		cout << e[i].first << ' ' << e[i].second << endl;
	return 0;
}