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
	// Postup:
	// Zistime si, na kolko tahov vieme o kolko znizit sumu S ak pouzivame len 1-hrany
	// Zistime si, na kolko tahov vieme o kolko znizit sumu S ak pouzivame len 2-hrany
	// Vyskusame vsetky moznosti, kolko 2 tahov urobit a binarne vyhladame, kolko 1 tahov musime urobit
	ll solve(int &n, ll &s, vector<pair<pair<int, int>, ll> > &e, vector<ll>&c)
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
		set<pair<ll, int>>v1;
		set<pair<ll, int>>v2;
		for (int i = 0; i < e.size(); i++)
		{
			int a = e[i].first.first;
			int b = e[i].first.second;
			if (d[a] > d[b]) swap(a, b);
			vaha[i] = l[b];
			s -= l[b] * e[i].second;
			if (c[i] == 1)
				v1.insert({ -(e[i].second - e[i].second / 2) * l[b], i }); // kolko dostaneme, ak potiahneme tuto hranu
			else
				v2.insert({ -(e[i].second - e[i].second / 2) * l[b], i });
		}
		if (s >= 0) return 0;
		vector<ll> c1; // ake znizenie vieme dosiahnut na i tahov
		c1.push_back(0);
		ll s1 = 0;
		while (!v1.empty() && v1.begin()->first < 0)
		{
			pair<ll, int> p = *v1.begin();
			v1.erase(p);
			e[p.second].second /= 2;
			s1 -= p.first;
			v1.insert({ -(e[p.second].second - e[p.second].second / 2) * vaha[p.second], p.second });
			c1.push_back(s1);
		}
		ll best = 1000000000;
		int m2 = 0;
		if (c1.back() + s >= 0)
		{
			best = min(best, (ll)(lower_bound(c1.begin(), c1.end(), -s) - c1.begin()));
		}
		while (!v2.empty() && v2.begin()->first < 0)
		{
			pair<ll, int> p = *v2.begin();
			v2.erase(p);
			e[p.second].second /= 2;
			s -= p.first;
			m2++;
			if (s >= 0)
			{
				best = min(best, m2 * 2ll);
				return best;
			}
			if (c1.back() + s >= 0)
			{
				best = min(best, m2 * 2ll + (lower_bound(c1.begin(), c1.end(), -s) - c1.begin()));
			}
			v2.insert({ -(e[p.second].second - e[p.second].second / 2) * vaha[p.second], p.second });
		}
		return best;
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
		vector<ll>c(n);
		for (int i = 0; i < n - 1; i++)
			cin >> e[i].first.first >> e[i].first.second >> e[i].second >> c[i];
		testcase i;
		cout << i.solve(n, s, e, c) << endl;
	}
	return 0;
}