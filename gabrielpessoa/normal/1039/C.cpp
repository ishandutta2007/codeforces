#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int ms = 5e5+5;
const ll mod = 1e9+7;

int dsu[ms];
int mark[ms];
map<ll, vector<pair<int, int>>> g;
ll c[ms];
int idx = 0;

int find(int u) {
  if(mark[u] != idx) return u;
  else return dsu[u] = find(dsu[u]);
}

void dsunion(int u, int v) {
  u = find(u); v = find(v);
  mark[u] = idx;
  dsu[u] = v;
}

ll fexp(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if(b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
      cin >> c[i];
    }
    for(int i = 1; i <= m; i++) {
      int u, v;
      cin >> u >> v;
      auto &vec = g[c[u] ^ c[v]];
      vec.push_back({u, v});
    }
    ll ans = (fexp(2, k+n) - (g.size() * fexp(2, n)) % mod + mod) % mod;
    //cout << ans << endl;
    for(auto &v : g) {
      ++idx;
      int x = n;
      for(auto &e : v.second) {
        if(find(e.first) != find(e.second)) {
          dsunion(e.first, e.second);
          x--;
        }
      }
      ans = (ans + fexp(2, x)) % mod;
    }
    cout << ans << endl;
    return 0;
}