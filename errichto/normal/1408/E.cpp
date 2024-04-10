#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }



int main() {
	int n, m;
	scanf("%d%d", &m, &n);
	vector<int> a(m);
	for(int i = 0; i < m; ++i) {
		scanf("%d", &a[i]);
		a[i] *= -1;
	}
	vector<int> b(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &b[i]);
		b[i] *= -1;
	}
	vector<vector<int>> sets(m), taken(m);
	vector<vector<int>> where(n);
	long long total = 0;
	for(int id = 0; id < m; ++id) {
		int cnt;
		scanf("%d", &cnt);
		for(int i = 0; i < cnt; ++i) {
			int x;
			scanf("%d", &x);
			assert(1 <= x && x <= n);
			x--;
			total += a[id] + b[x];
			sets[id].push_back(x);
		}
		sort(sets[id].begin(), sets[id].end(), [&](int x, int y) {
			return make_pair(b[x], x) < make_pair(b[y], y);
		});
		taken[id].push_back(sets[id][0]);
		for(int i = 1; i < (int) sets[id].size(); ++i) {
			where[sets[id][i]].push_back(id);
		}
	}
	vector<int> all;
	for(int i = 0; i < n; ++i) {
		all.push_back(i);
	}
	sort(all.begin(), all.end(), [&](int x, int y) {
		return make_pair(b[x], x) < make_pair(b[y], y);
	});
	vector<int> g(n);
	vector<vector<int>> inv(n);
	for(int i = 0; i < n; ++i) {
		g[i] = i;
		inv[i] = {i};
	}
	auto uni = [&](int x, int y) {
		x = g[x];
		y = g[y];
		assert(x != y);
		if(inv[x].size() > inv[y].size()) {
			swap(x, y);
		}
		for(int c : inv[x]) {
			g[c] = y;
			inv[y].push_back(c);
		}
		inv[x].clear();
	};
	vector<pair<int,int>> pp;
	for(int val : all) {
		for(int x : where[val]) {
			pp.emplace_back(val, x);
		}
	}
	sort(pp.begin(), pp.end(), [&](const pair<int,int>& A, const pair<int,int>& B) {
		return b[A.first]+a[A.second] < b[B.first]+a[B.second];
	});
	for(pair<int,int> p : pp) {
		int val = p.first;
		int s = p.second;
		if(g[val] != g[taken[s][0]]) {
			taken[s].push_back(val);
			uni(val, taken[s][0]);
		}
	}
	if(0)for(int val : all) {
		sort(where[val].begin(), where[val].end(), [&](int x, int y) {
			return a[x] < a[y];
		});
		debug() << imie(val) imie(where[val]);
		for(int s : where[val]) {
			if(g[val] != g[taken[s][0]]) {
				taken[s].push_back(val);
				uni(val, taken[s][0]);
				// break;
			}
		}
	}
	for(int s = 0; s < m; ++s) {
		for(int x : taken[s]) {
			total -= a[s] + b[x];
		}
		debug() << imie(s) imie(taken[s]);
	}
	printf("%lld\n", -total);
}