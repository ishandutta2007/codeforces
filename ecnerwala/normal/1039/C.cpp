#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = int(1e9) + 7;
const ll HALF = (MOD+1)/2;

const int MAXN = 6e5;
int N;
ll C[MAXN];

int M;
unordered_map<ll, vector<pair<int, int>>> edges;

int par[MAXN];
int getpar(int a) {
	if (par[a] == 0) return a;
	return par[a] = getpar(par[a]);
}
bool merge(int a, int b) {
	a = getpar(a), b = getpar(b);
	if (a == b) return false;
	par[a] = b;
	return true;
}

int K;

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> C[i];
	}
	for (int m = 0; m < M; m++) {
		int u, v; cin >> u >> v;
		edges[C[u] ^ C[v]].emplace_back(u, v);
	}

	ll res = (1ll << K) - ll(edges.size());
	res %= MOD;

	for (auto& it : edges) {
		ll v = 1;

		for (auto e : it.second) {
			if(merge(e.first, e.second)) {
				v = v * HALF % MOD;
			}
		}

		res += v;
		res %= MOD;

		for (auto e : it.second) {
			par[e.first] = 0;
			par[e.second] = 0;
		}
	}

	for (int i = 0; i < N; i++) {
		res *= 2;
		res %= MOD;
	}

	cout << res << '\n';

	return 0;
}