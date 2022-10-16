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
  set<int> st;
  int med;
  cin >> med;
  st.insert(med);
  bool ok = true;
  for (int i = 1; i < n; ++i) {
    int x;
    cin >> x;
    if (!ok) continue;
    if (x == med) {
      continue;
    }
    if (x > med) {
      auto it = st.upper_bound(med);
      if (it != st.end() && *it < x) {
        ok = false;
      }
    }
    if (x < med) {
      auto it = st.lower_bound(med);
      if (it != st.begin() && *prev(it) > x) {
        ok = false;
      }
    }
    med = x;
    st.insert(x);
  }
  cout << (ok ? "YES" : "NO") << '\n';
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