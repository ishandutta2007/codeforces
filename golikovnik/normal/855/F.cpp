//  Copyright 2021 Nikita Golikov

//  pragmas
#if 1
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,tune=native")
#endif

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

int const N = int(1e5 + 10);
int const INF = int(1.2e9);
struct node {
  int min_pos = INF;
  int min_neg = INF;
};
node a[N];

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int q;
  cin >> q;
  while (q--) {
    int t, l, r;
    cin >> t >> l >> r;
    --l, --r;
    if (t == 1) {
      int k;
      cin >> k;
      if (k > 0) {
        for (int i = l; i < r; ++i) {
          smin(a[i].min_pos, k);
        }
      } else {
        k = -k;
        for (int i = l; i < r; ++i) {
          smin(a[i].min_neg, k);
        }
      }
    } else {
      i64 ans = 0;
      for (int i = l; i < r; ++i) {
        int const x = a[i].min_pos;
        int const y = a[i].min_neg;
        if (x != INF && y != INF) {
          ans += x + y;
        }
      }
      cout << ans << '\n';
    }
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}