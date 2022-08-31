#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int pos[120] = {0};

vector <pair <int, int> > paths;
int f[1000];

int alt(int x)
{
	int p = pos[x];
	return (paths[p].first + paths[p].second - x);
}

pair <int, int> unite(pair <int, int> a, pair <int, int> b)
{
	if (a.first == b.first) return make_pair(a.second, b.second);
	if (a.first == b.second) return make_pair(a.second, b.first);
	if (a.second == b.first) return make_pair(a.first, b.second);
	return make_pair(a.first, b.first);
}

int main()
{
//	freopen("", "rt", stdin);
//	freopen("", "wt", stdout);
	int n, m;
	cin >> n >> m;	
	for (int i = 0; i < n; ++i)
	{
		pos[i] = i;
		paths.push_back(make_pair(i, i));
		f[i] = 1;
	}
	int q = n;
	for (int i = 0; i < m; ++i)
	{
		int x, y;
		cin >> x >> y;
		x--; y--;
		if (pos[x] > pos[y]) swap(x, y);
		if (pos[x] == pos[y])
			if (q != 1)
			{
				cout << "NO";
				return 0;
			}
			else if (i == m-1)
			{
				cout << "YES\n0\n";
				return 0;
			}
			else
			{
				cout << "NO";
				return 0;
			}
		if (pos[x] < 0 || pos[y] < 0)
		{
			cout << "NO";
			return 0;
		}
		paths.push_back(make_pair(alt(x), alt(y)));
		int fr = paths.size() - 1;
		f[pos[x]] = 0;
		f[pos[y]] = 0;
		f[fr] = 1;
		q--;
		if (x != alt(x))
		{
			pos[alt(x)] = fr;
			pos[x] = -1;
		}
		else pos[x] = fr;
		if (y != alt(y)) 
		{
			pos[alt(y)] = fr;
			pos[y] = -1;
		}
		else pos[y] = fr;
	}
	vector <pair <int, int> > chains;
	for (int i = 0; i < paths.size(); ++i)
		if (f[i])
		{
			if (paths[i].first > paths[i].second) swap(paths[i].first, paths[i].second);
			chains.push_back(paths[i]);
		}	
	sort(chains.begin(), chains.end());
	cout << "YES\n";
	cout << chains.size() << '\n';
	while (chains.size() > 1)
	{
		cout << chains[0].first + 1 << ' ' << chains[1].first + 1 << '\n';
		chains[1].first = chains[0].second;
		if (chains[1].first > chains[1].second) swap(chains[1].first, chains[1].second);
		chains.erase(chains.begin());
		sort(chains.begin(), chains.end());
	}
	cout << chains[0].first + 1 << ' ' << chains[0].second + 1<< '\n';
	return 0;
}