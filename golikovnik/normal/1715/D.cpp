//  Copyright 2022 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

#ifdef GOLIKOV
    #define debug(x) cerr << (#x) << ":\t" << (x) << endl
#else
    #define debug(x) 238;
#endif

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

  int n, q;
  cin >> n >> q;
  int const B = 30;
  vector<int> a(n, (1 << B) - 1);
  vector<vector<pair<int, int>>> qs(n);
  for (int i = 0; i < q; ++i) {
    int u, v, x;
    cin >> u >> v >> x;
    --u, --v;
    qs[u].emplace_back(v, x);
    qs[v].emplace_back(u, x);
    a[u] &= x;
    a[v] &= x;
  }
  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    int know = 0;
    for (auto[j, x] : qs[i]) {
      for (int b = B - 1; b >= 0; --b) {
        if (!(x >> b & 1)) {
          continue;
        }
        if (j > i) {
          if (!(a[j] >> b & 1)) {
            know |= 1 << b;
          }
        } else {
          if (!(ans[j] >> b & 1)) {
            know |= 1 << b;
          }
        }
      }
    }
    ans[i] = know;
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " \n"[i + 1 == n];
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}