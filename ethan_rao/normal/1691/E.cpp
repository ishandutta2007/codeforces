#include "bits/stdc++.h"
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
const int N = 1e6 + 10;
struct Q
{
	int l, r, c, id;
	bool operator<(const Q &o) const { return r == o.r ? id < o.id : r < o.r; }
};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int testcase;
	for (cin >> testcase; testcase--;)
	{
		int n, i, j;
		cin >> n;
		vector<Q> a(n);
		vector<int> f(n);
		iota(all(f), 0);
		auto getf = [&](auto getf, int u) -> int
		{ return f[u] == u ? u : f[u] = getf(getf, f[u]); };
		for (i = 0; i < n; i++)
		{
			int c, l, r;
			cin >> c >> l >> r;
			a[i] = Q{l, r, c, i};
		}
		sort(all(a), [&](const Q &a, const Q &b)
			 {{ return a.l == b.l ? a.c < b.c : a.l < b.l; } });
		set<Q> s[2];
		for (auto [l, r, c, id] : a)
		{
			s[c].insert({l, r, c, id});
			if (!s[c ^ 1].size())
				continue;
			c ^= 1;
			auto it = s[c].lower_bound({0, l, 0, 0});
			if (it == s[c].end())
				continue;
			for (auto jt = it; jt != s[c].end(); ++jt)
				f[getf(getf, id)] = getf(getf, jt->id);
			s[c].erase(it, prev(s[c].end()));
		}
		int r = 0;
		for (i = 0; i < n; i++)
			r += f[i] == i;
		cout << r << '\n';
	}
}