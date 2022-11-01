#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <ctime>
#include <chrono>
#include <random>

typedef long long ll;

using namespace std;

mt19937 gen;
vector <int> dsu;

int getp(int v) {
  if (dsu[v] == v) return v;
  return dsu[v] = getp(dsu[v]);
}

void merge (int u, int v) {
  u = getp(u), v = getp(v);
  if (gen() % 2) swap(u, v);
  dsu[v] = u;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  gen.seed(time(NULL));
  int n, m;
  cin >> n >> m;
  dsu.resize(n);
  iota(dsu.begin(), dsu.end(), 0);
  vector <ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int id = 0;
  for (int i = 0; i < n; i++)
    if (a[id] > a[i])
      id = i;
  vector <pair <ll, pair <ll, ll>>> e;
  for (int i = 0; i < m; i++) {
    ll u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    e.push_back({w, {u, v}});
  }
  for (int i = 0; i < n; i++)
    e.push_back({a[id] + a[i], {id, i}});
  sort(e.begin(), e.end());
  ll ans = 0;
  for (auto &now : e) {
    ll w = now.first, u = now.second.first, v = now.second.second;
    u = getp(u), v = getp(v);
    if (u == v) continue;
    ans += w;
    merge(u, v);
  }
  cout << ans;
  return 0;
}