#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define MAX 501010
#define MAXS 20
#define B 1010
#define INF 1000000000000000001
#define bb ' '
#define ln '\n'
#define Ln '\n'
ll sp[MAX][MAXS];
vector<ll> adj[MAX];
ll A[MAX];
vector<ll> va[MAX];
ll cp[MAX];
vector<ll> cadj[MAX];
ll latest[MAX];
ll use[MAX];
ll spoint[MAX]; //stop point
ll depth[MAX];
void make_p(ll x, ll p = 0, ll d = 1) {
	depth[x] = d;
	sp[x][0] = p;
	for (ll i = 1; i < MAXS; i++) sp[x][i] = sp[sp[x][i - 1]][i - 1];
	cp[x] = latest[A[x]];
	ll pv = latest[A[x]];
	latest[A[x]] = x;
	for (auto v : adj[x]) {
		if (v == p) continue;
		make_p(v, x, d + 1);
	}
	latest[A[x]] = pv;
}
ll lca(ll u, ll v) {
	if (!(u && v)) return max(u, v);
	if (depth[u] != depth[v]) {
		if (depth[u] > depth[v]) swap(u, v);
		ll d = depth[v] - depth[u];
		for (ll i = MAXS - 1; i >= 0; i--) if (d & (1LL << i)) v = sp[v][i];
	}
	if (u == v) return u;
	for (ll i = MAXS - 1; i >= 0; i--) if (sp[u][i] != sp[v][i]) u = sp[u][i], v = sp[v][i];
	return sp[u][0];
}
ll cdfs(ll x, ll p = 0, bool up = false) {
	if (A[x]) {
		if (up && cadj[x].size() >= 2) return x;
		if (!up) {
			ll l = 0;
			for (auto v : cadj[x]) if (v != p) l = lca(l, v);
			if (l == x) return x;
		}
	}
	for (auto v : cadj[x]) {
		if (v == p) continue;
		ll res;
		if (A[x]) res = cdfs(v, x, true);
		else if (cadj[x].size() > 1) res = cdfs(v, x, true);
		else res = cdfs(v, x);
		if (res) return res;
	}
	return 0;
}
ll M;
ll cnt;
ll sum;
ll sq;
void add(ll v) {
	cnt++;
	sum += v;
	sq += v * v;
}
void dfs(ll x, ll p = 0, ll all = 0) {
	if (spoint[x]) return;
	all += use[x];
	if (all == M) add(x);
	for (auto v : adj[x]) {
		if (v == p) continue;
		dfs(v, x, all);
	}
}
void print() {
	cout << cnt << ln;
	//cout << cnt << ln << sum << ln << sq << ln;
	exit(0);
}
signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll N;
	cin >> N;
	ll i;
	vector<ll> asdf;
	for (i = 1; i <= N; i++) cin >> A[i], asdf.push_back(A[i]);
	sort(asdf.begin(), asdf.end());
	asdf.erase(unique(asdf.begin(), asdf.end()), asdf.end());
	for (i = 1; i <= N; i++) A[i] = lower_bound(asdf.begin(), asdf.end(), A[i]) - asdf.begin() + 1, va[A[i]].push_back(i);
	ll a, b;
	for (i = 1; i < N; i++) cin >> a >> b, adj[a].push_back(b), adj[b].push_back(a);
	make_p(1);
	for (i = 1; i <= N; i++) {
		if (cp[i]) cadj[i].push_back(cp[i]), cadj[cp[i]].push_back(i);
		else cadj[A[i] + N].push_back(i), cadj[i].push_back(A[i] + N);
	}
	ll err = 0;
	for (i = 1; i <= N; i++) {
		if (va[i].size() > 1) {
			err = cdfs(i + N);
			if (err) print();
			if (cadj[i + N].size() == 1) M++, latest[i] = cadj[i + N][0];
			else latest[i] = 0;
			ll l = 0;
			for (auto cv : va[i]) {
				if (cv == latest[i]) continue;
				else spoint[cv] = 1, l = lca(l, cv);
			}
			if (latest[i] && l == latest[i]) print();
			if (latest[i]) {
				for (auto v : adj[latest[i]]) {
					if (depth[v] < depth[latest[i]]) continue;
					if (lca(v, l) == v) {
						use[v]++;
						break;
					}
				}
			}
		}
	}
	dfs(1);
	print();
}