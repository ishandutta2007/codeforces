//  Copyright 2020 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

template <class A, class B>
bool smin(A &x, B &&y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}

template <class A, class B>
bool smax(A &x, B &&y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m, n;
  cin >> m >> n;
  vector<i64> a(m);
  for (auto& x : a) cin >> x;
  vector<i64> b(n);
  for (auto& x : b) cin >> x;
  vector<tuple<i64, int, int>> edges;
  i64 total = 0;
  for (int i = 0; i < m; ++i) {
    int s;
    cin >> s;
    while (s--) {
      int x;
      cin >> x;
      --x;
      edges.emplace_back(a[i] + b[x], i, m + x);
      total += a[i] + b[x];
    }
  }
  sort(edges.rbegin(), edges.rend());
  vector<int> dsu(n + m);
  iota(dsu.begin(), dsu.end(), 0);
  auto find = [&](auto&& find, int v) -> int {
    return dsu[v] == v ? v : dsu[v] = find(find, dsu[v]);
  };
  for (auto[w, x, y] : edges) {
    x = find(find, x);
    y = find(find, y);
    if (x == y) continue;
    dsu[x] = y;
    total -= w;
  }
  cout << total << '\n';
#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}