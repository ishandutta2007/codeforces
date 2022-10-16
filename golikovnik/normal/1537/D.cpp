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
  if (n % 2) {
    cout << "Bob\n";
    return;
  }

  int deg = 0;
  while (n % 2 == 0) {
    deg++;
    n /= 2;
  }
  if (n == 1 && deg % 2 == 1) {
    cout << "Bob\n";
  } else {
    cout << "Alice\n";
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

//  int const N = 1000;
//  vector<bool> win(N);
//  for (int n = 2; n < N; ++n) {
//    for (int x = 2; x < n; ++x) {
//      if (n % x == 0 && !win[n - x]) {
//        win[n] = true;
//        break;
//      }
//    }
//    if (win[n]) {
//      if (n % 2 != 0) {
//        cerr << "wtf\n";
//      }
////      cout << n << endl;
//    }
//    if (n % 2 == 0 && !win[n]) {
//      cout << n << endl;
//    }
//  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}