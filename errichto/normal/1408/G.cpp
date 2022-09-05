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
#define int long long


int f(int x) {
	return x * (x - 1) / 2;
}

vector<vector<int>> children;
const int mod = 998244353;

vector<int> dfs(int a) {
	if((int) children[a].empty()) {
		// debug() << imie(a) imie(1);
		return {0, 1};
	}
	vector<int> mul;
	for(int b : children[a]) {
		vector<int> his = dfs(b);
		if(mul.empty()) {
			mul = his;
		}
		else {
			vector<int> nowy((int) mul.size() + (int) his.size());
			for(int i = 0; i < (int) mul.size(); ++i) {
				for(int j = 0; j < (int) his.size(); ++j) {
					nowy[i+j] = (nowy[i+j] + (long long) mul[i] * his[j]) % mod;
				}
			}
			mul = nowy;
		}
	}
	mul[1] = (mul[1] + 1) % mod;
	return mul;
	// debug() << imie(a) imie(mul);
	// return (mul + 1) % mod;
}

#undef int
int main() {
	#define int long long
	int n;
	scanf("%lld", &n);
	if(n == 1) {
		puts("1");
		return 0;
	}
	vector<pair<int, pair<int,int>>> all;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			int x;
			scanf("%lld", &x);
			if(i < j) {
				all.emplace_back(x, make_pair(i, j));
			}
		}
	}
	sort(all.begin(), all.end());
	int count_bad = 0;
	int ccs = n;
	vector<int> g(n);
	vector<vector<int>> inv(n), extra(n);
	for(int i = 0; i < n; ++i) {
		g[i] = i;
		inv[i] = {i};
		extra[i] = {i};
	}
	vector<int> cnt(n, 1), deg(n);
	int nxt = n;
	vector<int> parent(n, -1);
	vector<int> last(n);
	for(int i = 0; i < n; ++i) {
		last[i] = i;
	}
	for(pair<int, pair<int,int>> pp : all) {
		int a = pp.second.first;
		int b = pp.second.second;
		debug() << imie(a+1) imie(b+1) imie(pp.first);
		a = g[a];
		b = g[b];
		if(a == b) {
			if(++deg[a] == f(cnt[a])) {
				--count_bad;
			}
		}
		else {
			--ccs;
			if(deg[a] < f(cnt[a])) {
				--count_bad;
			}
			if(deg[b] < f(cnt[b])) {
				--count_bad;
			}
			if(inv[a].size() > inv[b].size()) {
				swap(a, b);
			}
			deg[b] += deg[a] + 1;
			cnt[b] += cnt[a];
			for(int x : inv[a]) {
				inv[b].push_back(x);
				g[x] = b;
			}
			for(int x : extra[a]) {
				extra[b].push_back(x);
			}
			extra[a].clear();
			inv[a].clear();
			assert(deg[b] <= f(cnt[b]));
			if(deg[b] < f(cnt[b])) {
				++count_bad;
			}
		}
		assert(deg[g[a]] <= f(cnt[g[a]]));
		assert(cnt[g[a]] == (int) inv[g[a]].size());
		// debug() << imie(ccs) imie(count_bad);
		assert(count_bad >= 0);
		if(deg[g[a]] == f(cnt[g[a]])) {
			int me = nxt++;
			set<int> what;
			for(int x : inv[g[b]]) {
				what.insert(last[x]);
			}
			for(int x : what) {
				parent[x] = me;
			}
			for(int x : inv[g[b]]) {
				last[x] = me;
			}
			debug() << imie(me) imie(what);
			// for(int x : extra[g[a]]) {
				// parent[x] = me;
			// }
			parent.push_back(-1);
			extra[g[a]] = {me};
			// debug() << imie(ccs);
		}
	}
	debug() << imie(parent);
	int root = nxt - 1;
	assert(parent[root] == -1);
	for(int i = 0; i < root; ++i) {
		assert(parent[i] != -1);
	}
	assert((int) parent.size() == root + 1);
	// debug() << imie(root);
	children.resize(root + 1);
	for(int i = 0; i < root; ++i) {
		children[parent[i]].push_back(i);
	}
	vector<int> ans = dfs(root);
	// debug() << imie(ans);
	if((int) ans.size() < n + 5) {
		ans.resize(n + 5);
	}
	for(int i = 1; i <= n; ++i) {
		printf("%lld ", ans[i]);
	}
	puts("");
}