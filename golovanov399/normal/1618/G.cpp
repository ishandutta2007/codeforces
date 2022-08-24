#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	int n = nxt(), m = nxt(), q = nxt();
	vector<pair<int, int>> a(n + m);
	for (int i = 0; i < n + m; ++i) {
		a[i] = {nxt(), i < n};
	}
	sort(all(a));
	vector<pair<int, int>> diffs;
	for (int i = 0; i < (int)a.size() - 1; ++i) {
		diffs.push_back({a[i + 1].first - a[i].first, i});
	}
	sort(all(diffs));

	vector<long long> p(n + m + 1);
	for (int i = 0; i < n + m; ++i) {
		p[i + 1] = p[i] + a[i].first;
	}
	list<pair<int, int>> lst;
	vector<decltype(lst)::iterator> its;
	for (int i = 0; i < n + m; ++i) {
		lst.push_back({i, a[i].second});
		its.push_back(prev(lst.end()));
	}
	lst.push_back({n + m, 0});

	vector<int> ds;
	vector<long long> ans;
	long long cur = 0;
	for (int i = 0; i < n + m; ++i) {
		if (a[i].second) {
			cur += a[i].first;
		}
	}
	ds.push_back(0);
	ans.push_back(cur);
	for (auto [d, i] : diffs) {
		ds.push_back(d);
		auto rit = its[i + 1];
		auto lit = prev(rit);
		cur -= p[i + 1] - p[i + 1 - lit->second];
		cur -= p[next(rit)->first] - p[next(rit)->first - rit->second];
		lit->second += rit->second;
		cur += p[next(rit)->first] - p[next(rit)->first - lit->second];
		lst.erase(rit);
		ans.push_back(cur);
	}

	while (q--) {
		int k = nxt();
		int idx = prev(upper_bound(all(ds), k)) - ds.begin();
		printf("%lld\n", ans[idx]);
	}

	return 0;
}