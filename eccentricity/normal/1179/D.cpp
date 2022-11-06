//Author: SBHeltion
//Date: 2019-06-22
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 540000;
vector<int> G[maxn];
LL sz[maxn], n, p[maxn], ans;
void DFS1(int u, int fa = 0){
	sz[u] = 1;
	for(int v : G[u]) if(v != fa){
		DFS1(v, u);
		sz[u] += sz[v];
	}
	if(G[u].size() == 1) p[u] = 2;
	else {
		p[u] = 1e18;
		for(int v : G[u])
		if(v != fa)
			p[u] = min(p[u], p[v] + (sz[u] - sz[v]) * (sz[u] - sz[v] + 1));
	}
}

using ll = long long;
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

void DFS2(int u, int fa = 0){
	for(int v : G[u]) if(v != fa) DFS2(v, u);
	/*
	for(int v : G[u]) if(v != fa)
		for(int w : G[u]) if(w != fa)
			if(v != w){
				LL pans = p[v] + p[w] + (n - sz[v] - sz[w]) * (n - sz[v] - sz[w] + 1);
				ans = min(ans, pans);
			}
	*/
	//-sz[w] * (2 * n - 2 * sz[v] + 1) + (n - sz[v]) * (n - sz[v] + 1) + p[v] + sz[w] * sz[w] + p[w]
	LineContainer ch;
	for(int v : G[u]) if(v != fa){
		if(ch.size()) ans = min(ans, -ch.query(sz[v]) + sz[v] * sz[v] + p[v]);
		ch.add(2 * n - 2 * sz[v] + 1, -(n - sz[v]) * (n - sz[v] + 1) - p[v]);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(12);
	cin >> n;
	ans = n * (n + 1);
	for(int i = 1, u, v; i < n; i += 1){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(n == 2){
		cout << 2;
		return 0;
	}
	int root = 0;
	for(int i = 1; i <= n; i += 1) if(G[i].size() > 1) root = i;
	DFS1(root);
	DFS2(root);
	cout << n * n - ans / 2;
	return 0;
}