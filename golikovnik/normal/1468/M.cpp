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

void solve(int) {
  int n;
  cin >> n;
  vector<vector<int>> sets(n);
  vector<int> all_elements;
  for (auto& v : sets) {
    int sz;
    cin >> sz;
    v.resize(sz);
    for (auto& x : v) {
      cin >> x;
      all_elements.push_back(x);
    }
  }
  sort(all_elements.begin(), all_elements.end());
  all_elements.erase(unique(all_elements.begin(), all_elements.end()),
                     all_elements.end());
  for (auto& v : sets) for (auto& x : v) {
    x = int(lower_bound(all_elements.begin(), all_elements.end(), x)
        - all_elements.begin());
  }
  int nuniq = int(all_elements.size());
  vector<vector<int>> graph(n + nuniq);
  vector<int> deg(n + nuniq);
  for (int i = 0; i < n; ++i) {
    for (int x : sets[i]) {
      graph[i].push_back(n + x);
      graph[n + x].push_back(i);
      deg[i]++;
      deg[n + x]++;
    }
  }
  vector<int> ord(n + nuniq);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](int i, int j) {
    return deg[i] > deg[j];
  });
  vector<int> pos_in_ord(n + nuniq);
  for (int i = 0; i < n + nuniq; ++i) pos_in_ord[ord[i]] = i;
  vector<pair<int, int>> used(n + nuniq, {-1, -1});

  auto report = [&](int a, int b, int c, int d) {
    if (a < n) {
      cout << a + 1 << ' ' << c + 1 << '\n';
    } else {
      cout << b + 1 << ' ' << d + 1 << '\n';
    }
  };

  for (int a : ord) {
    for (int b : graph[a]) {
      if (pos_in_ord[b] < pos_in_ord[a]) continue;
      for (int c : graph[b]) {
        if (c == a) continue;
        if (used[c].first == a) {
          report(c, used[c].second, a, b);
          return;
        }
        used[c] = {a, b};
      }
    }
  }
  cout << -1 << '\n';
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tests;
  cin >> tests;
  for (int _tt = 1; _tt <= tests; ++_tt) {
    solve(_tt);
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}