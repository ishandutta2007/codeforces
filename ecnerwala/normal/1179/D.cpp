#include<bits/stdc++.h>
using namespace std;

namespace kactl {
//https://github.com/kth-competitive-programming/kactl/blob/165807e28402c9be906f6e6a09452431787bb70d/content/data-structures/LineContainer.h
using ll = long long;
/**
 * Author: Simon Lindholm
 * Date: 2017-04-20
 * License: CC0
 * Source: own work
 * Description: Container where you can add lines of the form kx+m, and query maximum values at points x.
 *  Useful for dynamic programming.
 * Time: O(\log N)
 * Status: tested
 */

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};
}

using ll = long long;

ll c2(ll A) {
	return A * (A-1) / 2;
}

const int MAXN = 6.1e5;
ll N;
vector<int> adj[MAXN];
ll sz[MAXN];

ll ans;
ll bestTo[MAXN];

ll dpVal[MAXN];

void dfs(int cur, int prv) {

	for (int i = 0; i < int(adj[cur].size()); i++) {
		if (adj[cur][i] == prv) {
			adj[cur].erase(adj[cur].begin() + i);
		}
	}

	for (int nxt : adj[cur]) {
		dfs(nxt, cur);
	}

	sz[cur] = 1;
	for (int nxt : adj[cur]) {
		sz[cur] += sz[nxt];
	}

	// assuming we use the parent edge
	bestTo[cur] = c2(sz[cur]);
	for (int nxt : adj[cur]) {
		bestTo[cur] = min(bestTo[cur], bestTo[nxt] + c2(sz[cur] - sz[nxt]));
	}

	// if we take cur as the root
	for (int nxt : adj[cur]) {
		ans = min(ans, bestTo[nxt] + c2(N - sz[nxt]));
	}

	for (int a : adj[cur]) {
		dpVal[a] = bestTo[a] + c2(sz[a] + 1) - N * sz[a];
	}

	kactl::LineContainer cont;
	for (int a : adj[cur]) {
		if (!cont.empty()) {
			ans = min(ans, dpVal[a] + c2(N) - cont.query(sz[a]));
		}
		cont.add(-sz[a], -dpVal[a]);
	}

	/*
	for (int a : adj[cur]) {
		for (int b : adj[cur]) {
			if (a == b) continue;
			ll v = bestTo[a] + bestTo[b] + c2(N - sz[a] - sz[b]);
			assert(v == dpVal[a] + dpVal[b] + c2(N) + sz[a] * sz[b]);
			ans = min(ans, v);
		}
	}
	*/

	// if we take 2 paths down...
	// it's min of bestTo[a] + bestTo[b] + c2(N - sz[a] - sz[b])
	// bestTo[a] + bestTo[b] + (N - sz[a] - sz[b]) * (N - sz[a] - sz[b] - 1) / 2
	// bestTo[a] + bestTo[b] (N^2 + sz[a]^2 + sz[b]^2 - N + sz[a] + sz[b]) / 2 - Nsz[a] - Nsz[b] + sz[a] sz[b]
	// bestTo[a] + bestTo[b] + c2(N) + c2(sz[a]+1) + c2(sz[b]+1) - N * sz[a] - N * sz[b] + sz[a] * sz[b]
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N-1; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	ans = c2(N);
	dfs(1, 0);

	cout << c2(N) + c2(N) - ans << '\n';

	return 0;
}