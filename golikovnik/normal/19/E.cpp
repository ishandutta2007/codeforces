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

  int n, m;
  cin >> n >> m;
  if (m == 0) {
    cout << 0 << '\n';
    return 0;
  }
  vector<pair<int, int>> edges(m);
  for (auto& [x, y] : edges) {
    cin >> x >> y;
    --x, --y;
  }
  vector<int> dsu(n, -1), color(n);
  int isBad = 0;
  vector<int> ans;
  vector<pair<int*, int>> changes;
  auto Set = [&](int& x, int val) {
    changes.emplace_back(&x, x);
    x = val;
  };
  auto add = [&](int ei) {
    if (isBad) {
      return;
    }
    auto[u, v] = edges[ei];
    int parU = u;
    int cU = 0;
    while (dsu[parU] >= 0) {
      cU ^= color[parU];
      parU = dsu[parU];
    }
    int parV = v;
    int cV = 0;
    while (dsu[parV] >= 0) {
      cV ^= color[parV];
      parV = dsu[parV];
    }
    if (parU == parV) {
      if (cU == cV) {
        Set(isBad, 1);
      }
      return;
    }
    if (dsu[parU] > dsu[parV]) {
      swap(parU, parV);
      swap(cU, cV);
    }
    if (cU == cV) {
      Set(color[parV], color[parV] ^ 1);
    }
    Set(dsu[parU], dsu[parU] + dsu[parV]);
    Set(dsu[parV], parU);
  };
  auto undo = [&](int sz) {
    while (int(changes.size()) > sz) {
      auto[ptr, v] = changes.back();
      changes.pop_back();
      *ptr = v;
    }
  };
  auto solve = [&](auto&& solve, int l, int r) -> void {
    if (l + 1 == r) {
      if (!isBad) {
        ans.push_back(l);
      }
      return;
    }
    int sz = int(changes.size());
    int mid = (l + r) / 2;
    for (int i = mid; i < r; ++i) {
      add(i);
    }
    solve(solve, l, mid);
    undo(sz);
    for (int i = l; i < mid; ++i) {
      add(i);
    }
    solve(solve, mid, r);
    undo(sz);
  };
  solve(solve, 0, m);
  cout << ans.size() << '\n';
  for (auto x : ans) cout << x + 1 << ' ';
  cout << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}