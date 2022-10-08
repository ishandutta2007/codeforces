#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
const double pi = acos(-1.0);

const int size = 100 * 1000;
const int inf = 1000 * 1000 * 1000;

int n, k;
long long ans;
int deep[size];
vector <int> vertex[size];

void dfs(int v, int f, set <pair <int, int> > &mst)
{
	set <pair <int, int> > h;
	h.clear();
	set <pair <int, int> > :: iterator it, it2;
	for (int i = 0; i < vertex[v].size(); i++)
		if (vertex[v][i] != f)
		{
			h.clear();
			dfs(vertex[v][i], v, h);
			it = h.lower_bound(mp(deep[v] + k, -inf));
			if (it -> fs == deep[v] + k)
				ans += it -> sc;
			if (mst.size() < h.size())
				swap(mst, h);
			for (it = h.begin(); it != h.end(); it++)
			{
				it2 = mst.lower_bound(mp(deep[v] * 2 + k - (it -> fs), -inf));
				if (it2 != mst.end() && it2 -> fs + it -> fs - deep[v] * 2 == k)
					ans += 1ll * (it -> sc) * (it2 -> sc);
			}
			for (it = h.begin(); it != h.end(); it++)
			{
				it2 = mst.lower_bound(mp(it -> fs, -inf));
				if (it2 != mst.end() && it2 -> fs == it -> fs)
				{
					int d = it2 -> sc;
					mst.erase(it2);
					mst.insert(mp(it -> fs, it -> sc + d));
				}
				else
					mst.insert(mp(it -> fs, it -> sc));
			}
		}
	h.clear();
	mst.insert(mp(deep[v], 1));
}

void dfs_deep(int v, int f, int d)
{
	deep[v] = d;
	for (int i = 0; i < int(vertex[v].size()); i++)
		if (f != vertex[v][i])
			dfs_deep(vertex[v][i], v, d + 1);
}

int main() {
	int s, f;

	//freopen("problem_d.in", "r", stdin);
	//freopen("problem_d.out", "w", stdout);
	
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d%d", &s, &f);
		s--, f--;
		vertex[s].pb(f);
		vertex[f].pb(s);
	}
	dfs_deep(0, 0, 0);
	set <pair <int, int> > h;
	dfs(0, 0, h);

	cout << ans << endl;

	return 0;
}