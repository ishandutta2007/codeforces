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
  vector<int> a(n);
  for (auto& x : a) {
    cin >> x;
  }
  int ans = int(4e6);
  for (int i = 1; i < n - 1; ++i) {
    int x = a[i - 1];
    int y = a[i + 1];
    smin(ans, min(x, y) + (max(x, y) - min(x, y) + 1) / 2);
  }

  for (int i = 0; i + 1 < n; ++i) {
    int x = a[i];
    int y = a[i + 1];
    smin(ans, max({(x + y + 2) / 3, (x + 1) / 2, (y + 1) / 2}));
  }
  sort(a.begin(), a.end());
  smin(ans, (a[1] + 1) / 2 + (a[0] + 1) / 2);
  cout << ans << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}