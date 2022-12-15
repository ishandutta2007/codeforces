#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll ms = 2e5+5;

vector<pair<ll, pair<ll, ll>>> g[ms];
ll sz[ms], par[ms], h[ms];
ll t, in[ms], out[ms], rin[ms], nxt[ms];
ll arr[ms];
ll magia[ms];

ll n;
ll seg[2 * ms];

ll merge(ll a, ll b) {
  if(a > 2000000000000000000ll/b) return 1000000000000000001ll;
  else return min(1000000000000000001ll, a * b);
}

void build() {
  for(ll i = n - 1; i > 0; --i) seg[i] = merge(seg[i<<1], seg[i<<1|1]); // Merge
}

void update(ll p, ll value) { // set value at position p
  for(seg[p += n] = value; p > 1; p >>= 1) seg[p>>1] = merge(seg[p], seg[p^1]); // Merge
}

ll query(ll l, ll r) {
  
  ll res = 1;
  for(l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
    if(l&1) res = merge(res, seg[l++]); // Merge
    if(r&1) res = merge(res, seg[--r]); // Merge
  }
  return res;
}

void dfs_sz(ll v = 0, ll p = -1){
  sz[v] = 1;
  for(ll i = 0; i < g[v].size(); i++){
    auto &u = g[v][i];
    if(u.first == p) continue;
    h[u.first] = h[v]+1, par[u.first] = v;
    dfs_sz(u.first, v);
    sz[v] += sz[u.first];
    if(g[v][0].first == p || sz[u.first] > sz[g[v][0].first]){
      swap(u, g[v][0]);
    }
  }
}

void dfs_hld(ll v = 0, ll p = -1, ll val = 1, ll idx = 0){
  in[v] = t++;
  seg[in[v]+n] = val;
  if(~p) magia[idx] = in[v];
  rin[in[v]] = v;
  for(ll i = 0; i < g[v].size(); i++){
    auto &u = g[v][i];
    if(u.first == p) continue;
    nxt[u.first] = u.first == g[v][0].first ? nxt[v] : u.first;
    dfs_hld(u.first, v, u.second.first, u.second.second);
  }
  out[v] = t;
}

ll up(ll v){
  return (nxt[v] != v) ? nxt[v] : (~par[v] ? par[v] : v); 
}

ll getLCA(ll a, ll b){
  while(nxt[a] != nxt[b]){
    if(h[a] == 0 || h[up(a)] < h[up(b)]) swap(a, b);
    a = up(a);
  }
  return h[a] < h[b] ? a : b;
}

ll queryUp(ll a, ll p = 0){
  ll ans = 1;
  while(nxt[a] != nxt[p]){
   ans = merge(ans, query(in[nxt[a]], in[a]));
    a = par[nxt[a]];
  }
  return merge(ans, query(in[p]+1, in[a]));
}

ll queryPath(ll u, ll v) {
  ll lca = getLCA(u, v);
  //cout << "U V LCA " << u << ' ' << v << ' ' << lca << endl;
  ll a = queryUp(u, lca);
  ll b = queryUp(v, lca);
  //cout << "A B " << a << ' ' << b << endl;
  return merge(a, b);
}

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  ll m;
  cin >> n >> m;
  for(ll i = 0; i < n - 1; i++) {
    ll u, v; ll x;
    cin >> u >> v >> x;
    u--; v--;
    g[u].emplace_back(v, make_pair(x, i));
    g[v].emplace_back(u, make_pair(x, i));
  }
  dfs_sz(); dfs_hld();
  build();
  for(ll i = 0; i < m; i++) {
    ll type;
    cin >> type;
    if(type == 1) {
      ll a, b;
      ll y;
      cin >> a >> b >> y;
      a--; b--;
      cout << y / queryPath(a, b) << endl;
    } else {
      ll p; ll c;
      cin >> p >> c;
      p--;
      update(magia[p], c);
    }
  }
}