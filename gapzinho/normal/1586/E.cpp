
#include <bit>
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 1e18;
const int ms = 6e5+5;
const int mod = 1e9+7;
using ii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> g[ms];
map<int, int> dic;
int a[ms], b[ms];
int par[ms];
int lvl[ms];

void dfs(int u, int p = -1, int curLvl = 0) {
  if(par[u]) return;
  par[u] = p;
  lvl[u] = curLvl;
  for(int v : g[u]) {
    dfs(v, u, curLvl+1);
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  int q;
  cin >> q;
  for(int i = 0; i < q; i++) {
    cin >> a[i] >> b[i];
    int x = a[i], y = b[i];
    if(dic.count(a[i]) && dic[a[i]] == b[i]) {
      dic.erase(a[i]);
      dic.erase(b[i]);
      continue;
    }
    if(dic.count(a[i])) {
      x = dic[a[i]];
      dic.erase(a[i]);
    }
    if(dic.count(b[i])) {
      y = dic[b[i]];
      dic.erase(b[i]);
    }
    dic[x] = y;
    dic[y] = x;
  }
  if(!dic.empty()) {
    cout << "NO\n";
    cout << dic.size() / 2 << endl;
    return;
  }
  cout << "YES\n";
  dfs(1);
  for(int i = 0; i < q; i++) {
    vector<int> p1, p2;
    int swpd = 0;
    if(lvl[a[i]] < lvl[b[i]]) {
      swap(a[i], b[i]);
      swpd = 1;
    }
    while(lvl[a[i]] > lvl[b[i]]) {
      p1.emplace_back(a[i]);
      a[i] = par[a[i]];
    }
    while(a[i] != b[i]) {
      p1.emplace_back(a[i]);
      p2.emplace_back(b[i]);
      a[i] = par[a[i]];
      b[i] = par[b[i]];
    }
    p1.emplace_back(a[i]);
    if(swpd) {
      p1.swap(p2);
    }
    reverse(p2.begin(), p2.end());
    cout << p1.size() + p2.size() << '\n';
    for(int  u : p1) {
      cout << u << ' ';
    }
    for(int u : p2) {
      cout << u << ' ';
    }
    cout << '\n';
  }
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // t = inf;
  // cin >> t;
  // cout << fixed << setprecision(9);
  while (t--) {
      solve();
  }
  return 0;
}