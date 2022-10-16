//  Copyright 2021 Nikita Golikov

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

bool isPrime(int d) {
  if (d == 1) return false;
  for (int p = 2; p * p <= d; ++p) {
    if (d % p == 0) return false;
  }
  return true;
}

void solve(int) {
  int k; cin >> k;
  string s; cin >> s;
  vector<int> ds(k);
  for (int i = 0; i < k; ++i) ds[i] = s[i] - '0';
  for (int i = 0; i < k; ++i) {
    if (!isPrime(ds[i])) {
      cout << 1 << '\n' << s[i] << '\n';
      return;
    }
  }
  for (int i = 0; i < k; ++i) {
    for (int j = i + 1; j < k; ++j) {
      if (!isPrime(ds[i] * 10 + ds[j])) {
        cout << 2 << '\n' << ds[i] * 10 + ds[j] << '\n';
        return;
      }
    }
  }

  for (int i = 0; i < k; ++i) {
    for (int j = i + 1; j < k; ++j) {
      for (int t = j + 1; t < k; ++t) {
        if (!isPrime(100 * ds[i] + 10 * ds[j] + ds[t])) {
          cout << 3 << ' ' << ds[i] * 100 + 10 * ds[j] + ds[t] << '\n';
          return;
        }
      }
    }
  }

  assert(false);
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int _tests;
  cin >> _tests;
  for (int _tt = 1; _tt <= _tests; ++_tt) {
    solve(_tt);
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}