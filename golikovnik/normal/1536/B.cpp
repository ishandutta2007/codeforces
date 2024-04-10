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
  string s;
  cin >> s;
  auto check = [&](string const& t) {
    return s.find(t) == string::npos;
  };
  for (char x = 'a'; x <= 'z'; ++x) {
    if (check(string(1, x))) {
      cout << x << '\n';
      return;
    }
  }
  for (char x = 'a'; x <= 'z'; ++x) {
    for (char y = 'a'; y <= 'z'; ++y) {
      if (check(string(1, x) + string(1, y))) {
        cout << x << y << '\n';
        return;
      }
    }
  }
  for (char x = 'a'; x <= 'z'; ++x) {
    for (char y = 'a'; y <= 'z'; ++y) {
      for (char z = 'a'; z <= 'z'; ++z) {
        if (check(string(1, x) + string(1, y) + string(1, z))) {
          cout << x << y << z << '\n';
          return;
        }
      }
    }
  }
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