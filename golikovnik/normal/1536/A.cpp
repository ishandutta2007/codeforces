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
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  set<int> b(a.begin(), a.end());
  bool ch = true;
  while (ch && int(b.size()) <= 300) {
    ch = false;
    for (int x : b) {
      for (int y : b) {
        if (b.insert(abs(x - y)).second) {
          ch = true;
          break;
        }
      }
      if (ch) break;
    }
  }
  if (int(b.size()) <= 300) {
    cout << "YES\n";
    cout << b.size() << '\n';
    for (auto x : b) cout << x << ' ';
    cout << '\n';
  } else cout << "NO\n";
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