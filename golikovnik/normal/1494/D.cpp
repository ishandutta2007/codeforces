//  Copyright 2021 Nikita Golikov

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

  int n;
  cin >> n;
  vector a(n, vector<int>(n));
  for (auto& r : a) for (auto& c : r) cin >> c;
  vector<int> salaries(n);
  for (int i = 0; i < n; ++i) salaries[i] = a[i][i];
  vector<pair<int, int>> edges;
  auto solve = [&](auto&& solve, vector<int> ids, int parent) -> void {
    if (ids.size() == 1) {
      edges.emplace_back(ids[0], parent);
      return;
    }
    int mx = 0;
    for (int i : ids) {
      for (int j : ids) {
        smax(mx, a[i][j]);
      }
    }
    int id = int(salaries.size());
    salaries.emplace_back(mx);
    if (parent >= 0) {
      edges.emplace_back(id, parent);
    }
    vector<bool> used(ids.size());
    for (int i = 0; i < int(ids.size()); ++i) {
      if (used[i]) continue;
      vector<int> ncomp;
      for (int j = 0; j < int(ids.size()); ++j) {
        if (a[ids[i]][ids[j]] != mx) {
          assert(!used[j]);
          used[j] = true;
          ncomp.push_back(ids[j]);
        }
      }
      solve(solve, ncomp, id);
    }
  };
  vector<int> all(n);
  iota(all.begin(), all.end(), 0);
  solve(solve, all, -1);
  cout << salaries.size() << '\n';
  for (auto x : salaries) cout << x << ' ';
  cout << '\n';
  cout << n + 1 << '\n';
  for (auto[u, v] : edges) cout << u + 1 << ' ' << v + 1 << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}