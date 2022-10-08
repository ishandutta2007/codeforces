#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#include <algorithm>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define pi 3.1415926535897932384626433832795

const int size = 200 * 1000;

int n;
long long ans;
int sz[size], good[size];
vector <pair <int, int> > vertex[size];

bool isgood(int c)
{
	while (c > 0)
	{
		if ((c % 10) != 4 && (c % 10) != 7)
			return false;
		c /= 10;
	}
	return true;
}

void dfs1(int v, int f)
{
	sz[v] = 1;
	good[v] = 0;
	int i;
	for (i = 0; i < vertex[v].size(); i++)
		if (vertex[v][i].fs != f)
		{
			dfs1(vertex[v][i].fs, v);
			sz[v] += sz[vertex[v][i].fs];
			if (vertex[v][i].sc)
				good[v] += sz[vertex[v][i].fs];
			else
				good[v] += good[vertex[v][i].fs];
		}
}

void dfs2(int v, int f, int cd)
{
	int sum = cd + good[v], i, d;
	ans += sum * 1ll * (sum - 1);
	for (i = 0; i < vertex[v].size(); i++)
		if (vertex[v][i].fs != f)
		{
			d = (vertex[v][i].sc ? sz[vertex[v][i].fs] : good[vertex[v][i].fs]);
			if (vertex[v][i].sc)
				dfs2(vertex[v][i].fs, v, n - sz[vertex[v][i].fs]);
			else
				dfs2(vertex[v][i].fs, v, sum - d);
		}
}

int main() {
	int i, a, b, c;

	//freopen("luck.in", "r", stdin);
	//freopen("luck.out", "w", stdout);

	cin >> n;
	for (i = 0; i < n - 1; i++)
	{
		cin >> a >> b >> c;
		c = isgood(c);
		a--, b--;
		vertex[a].pb(mp(b, c));
		vertex[b].pb(mp(a, c));
	}

	dfs1(0, 0);
	dfs2(0, 0, 0);

	cout << ans;

	return 0;
}