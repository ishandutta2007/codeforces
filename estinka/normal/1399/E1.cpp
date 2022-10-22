#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <iomanip>
#include <functional>
//#pragma optimize GCC("O3")
typedef long long ll;
typedef long double ld;
using namespace std;

class testcase
{
	vector<ll>vaha; // zistime vahu kazdej hrany - kolkym listom sa rata
	vector<int> d; // hlbka
	vector<int> l; // pocet listov
	void dfs(int vr, int p, vector<vector<pair<int, ll> > > &g)
	// vrchol, rodic, vaha hrany do rodica, S, g
	{
		if (vr > 0 && g[vr].size() == 1)
		{
			l[vr] = 1;
			return;
		}
		for (pair<int, ll> i : g[vr])
		{
			if (i.first == p)
				continue;
			d[i.first] = d[vr] + 1;
			dfs(i.first, vr, g);
			l[vr] += l[i.first];
		}
	}
public:
	ll solve(int &n, ll &s, vector<pair<pair<int, int>, ll> > &e)
	{
		vector<vector<pair<int, ll> > > g(n);
		for (int i = 0; i < e.size(); i++)
		{
			e[i].first.first--;
			e[i].first.second--;
			g[e[i].first.first].push_back(make_pair(e[i].first.second, e[i].second));
			g[e[i].first.second].push_back(make_pair(e[i].first.first, e[i].second));
		}
		d.resize(n, 0);
		l.resize(n, 0);
		dfs(0, -1, g);
		vaha.resize(e.size());
		set<pair<ll, int>>v;
		for (int i = 0; i < e.size(); i++)
		{
			int a = e[i].first.first;
			int b = e[i].first.second;
			if (d[a] > d[b]) swap(a, b);
			vaha[i] = l[b];
			s -= l[b] * e[i].second;
			v.insert({ -(e[i].second - e[i].second / 2) * l[b], i }); // kolko dostaneme, ak potiahneme tuto hranu
		}
		int moves = 0;
		while (s < 0)
		{
			pair<ll, int> p = *v.begin();
			v.erase(p);
			e[p.second].second /= 2;
			s -= p.first;
			v.insert({ -(e[p.second].second - e[p.second].second / 2) * vaha[p.second], p.second });
			moves++;
		}
		return moves;
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		ll s;
		cin >> n >> s;
		vector<pair<pair<int, int>, ll> > e(n - 1);
		for (int i = 0; i < n - 1; i++)
			cin >> e[i].first.first >> e[i].first.second >> e[i].second;
		testcase i;
		cout << i.solve(n, s, e) << endl;
	}
	return 0;
}