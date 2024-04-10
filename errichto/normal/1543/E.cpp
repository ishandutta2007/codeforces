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

vector<vector<int>> edges;
vector<int> p;
vector<bool> vis;
vector<int> c;

void rec(int a, int value, int k) {
	vis[a] = true;
	p[value] = a;
	if(k == 0) {
		return;
	}
	rec(a, value, k - 1);
	for(int b : edges[a]) {
		if(!vis[b]) {
			c[b] = c[a] ^ (k - 1);
			rec(b, value + (1 << (k - 1)), k - 1);
			break;
		}
	}
}

void test_case() {
	int n;
	scanf("%d", &n);
	edges.clear();
	vis.clear();
	p.clear();
	edges.resize(1 << n);
	vis.resize(1 << n);
	p.resize(1 << n, -1);
	c.clear();
	c.resize(1 << n, -1);
	for(int i = 0; i < n * (1 << (n - 1)); ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	c[0] = 0;
	// rec(0, 0, n);
	
	vector<int> me{0};
	p[0] = 0;
	for(int r = 0; r < n; ++r) {
		vector<bool> good(1 << n);
		vector<bool> taken(1 << n);
		for(int x : me) {
			taken[x] = true;
		}
		vector<int> they;
		auto add = [&](int x) {
			they.push_back(x);
			for(int e : edges[x]) {
				good[e] = true;
			}
		};
		for(int e : edges[me[0]]) {
			if(!taken[e]) {
				add(e);
				break;
			}
		}
		for(int a : me) {
			if(a == me[0]) {
				continue;
			}
			for(int e : edges[a]) {
				if(!taken[e] && good[e]) {
					add(e);
					break;
				}
			}
		}
		assert(me.size() == they.size());
		for(int x : they) {
			me.push_back(x);
			taken[x] = true;
		}
	}
	
	for(int x : me) {
		printf("%d ", x);
	}
	puts("");
	vector<int> inv_me(1 << n);
	for(int i = 0; i < (1 << n); ++i) {
		inv_me[me[i]] = i;
	}
	if(__builtin_popcount(n) == 1) {
		for(int i = 0; i < (1 << n); ++i) {
			// me[i]
			int total = 0;
			for(int z = 0; z < n; ++z) {
				if(inv_me[i] & (1 << z)) {
					total ^= z;
				}
			}
			printf("%d ", total);
		}
		puts("");
	}
	else {
		puts("-1");
	}
	return;
	
	// for(int x : p) {
		// printf("%d ", x);
	// }
	// puts("");
	// if(__builtin_popcount(n) == 1) {
		// for(int x : c) printf("%d ", x);
		// puts("");
	// }
	// else {
		// puts("-1");
	// }
}

int main() {
	int T;
	scanf("%d", &T);
	for(int z = 1; z <= T; z++) {
		// printf("Case #%d: ", z);
		test_case();
	}
}