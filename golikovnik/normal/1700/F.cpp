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

  int n; cin >> n;
  vector a(2, vector<int>(n)), b(2, vector<int>(n));
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> b[i][j];
    }
  }
  ll ans = 0;
  int u = 0;
  int d = 0;
  //  a-b
  for (int i = 0; i < n; ++i) {
    int xa = a[0][i];
    int ya = a[1][i];
    int xb = b[0][i];
    int yb = b[1][i];
    ans += abs(u) + abs(d);
    u += xa - xb;
    d += ya - yb;
    while (u < 0 && d > 0) {
      ++ans;
      ++u;
      --d;
    }
    while (u > 0 && d < 0) {
      ++ans;
      --u;
      ++d;
    }
  }
  cout << (u || d ? -1 : ans) << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}