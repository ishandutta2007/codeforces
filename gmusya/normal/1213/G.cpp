#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <chrono>
#include <ctime>
#include <random>

typedef long long ll;

using namespace std;

mt19937 gen;

ll ans = 0;
vector <ll> dsu, sz;

int get(int v) {
  if (dsu[v] == v) return v;
  return dsu[v] = get(dsu[v]);
}

void merge(int u, int v) {
  u = get(u), v = get(v);
  ans += sz[u] * sz[v];
  if (gen() % 2)
    swap(u, v);
  dsu[v] = u;
  sz[u] += sz[v];
}

int main () {
  gen.seed(time(NULL));
  int n, q;
  cin >> n >> q;
  dsu.resize(n), sz.resize(n, 1);
  iota(dsu.begin(), dsu.end(), 0);
  vector <pair <int, pair <int, int>>> e;
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    e.push_back({w, {u, v}});
  }
  sort(e.begin(), e.end());
  vector <pair <ll, ll>> arr;
  arr.push_back({0, 0});
  for (auto &now : e) {
    int w = now.first, u = now.second.first, v = now.second.second;
    merge(u, v);
    arr.push_back({w, ans});
  }
  while (q--) {
    ll val;
    cin >> val;
    pair <ll, ll> x = {val, 1e18};
    cout << (--upper_bound(arr.begin(), arr.end(), x))->second << ' ';
  }
  return 0;
}